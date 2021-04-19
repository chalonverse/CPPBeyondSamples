# This is required to issue any FetchContent commands
include(FetchContent)

# This declares "cppcoro" as a git repository we depend on
FetchContent_Declare(
  cppcoro
  GIT_REPOSITORY https://github.com/lewissbaker/cppcoro.git
)

# This says we want the "cppcoro" we declared available
FetchContent_MakeAvailable(cppcoro)

include_directories(${cppcoro_SOURCE_DIR}/include)

if (WIN32)
	# Need to specify /await
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /await")
endif()

add_executable(Ex05 Main.cpp
	${cppcoro_SOURCE_DIR}/lib/async_manual_reset_event.cpp
	${cppcoro_SOURCE_DIR}/lib/lightweight_manual_reset_event.cpp
	${cppcoro_SOURCE_DIR}/lib/static_thread_pool.cpp
	${cppcoro_SOURCE_DIR}/lib/spin_mutex.cpp
	${cppcoro_SOURCE_DIR}/lib/auto_reset_event.cpp
	${cppcoro_SOURCE_DIR}/lib/spin_wait.cpp
	${cppcoro_SOURCE_DIR}/lib/win32.cpp
)

if (WIN32)
	target_link_libraries(Ex05 synchronization)
endif()