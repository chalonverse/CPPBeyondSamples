# This is required to issue any FetchContent commands
include(FetchContent)

# Fetch the project and make it available for use.
FetchContent_Declare(
    libcoro
    GIT_REPOSITORY https://github.com/jbaldwin/libcoro.git
    GIT_TAG        v0.14.1
)
FetchContent_MakeAvailable(libcoro)

include_directories(${libcoro_SOURCE_DIR}/include)

add_executable(Ex05 Main.cpp)

target_link_libraries(Ex05 PUBLIC libcoro)
