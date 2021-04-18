This demonstrates compiling with multiple cpp files,
using a GLOB file rule.

As noted in the CMake documentation, however:
>We do not recommend using `GLOB` to collect a list of source files from your source tree. If no CMakeLists.txt file changes when a source is added or removed then the generated build system cannot know when to ask CMake to regenerate. The `CONFIGURE_DEPENDS` flag may not work reliably on all generators, or if a new generator is added in the future that cannot support it, projects using it will be stuck. Even if `CONFIGURE_DEPENDS` works reliably, there is still a cost to perform the check on every rebuild.