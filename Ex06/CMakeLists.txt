# This says to create an executable target called Ex06 that compiles Main.cpp using modules
add_library(ModuleTest)
target_sources(ModuleTest PUBLIC FILE_SET CXX_MODULES FILES
				ModuleTest.cppm)

add_executable(Ex06 Main.cpp)
