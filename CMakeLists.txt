cmake_minimum_required(VERSION 2.8)
project(SSARI)
include_directories(include)
include_directories(/usr/include/libxml2)
include_directories(/usr/include/sigc++-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/sigc++-2.0/include)
include_directories(/usr/include/libxml++-2.6)
include_directories(/usr/lib/libxml++-2.6/include)
include_directories(/usr/include/glibmm-2.4)
include_directories(/usr/lib/x86_64-linux-gnu/glibmm-2.4/include)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)

# Get Source List
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
message(STATUS "${PROJECT_SOURCES}")



add_subdirectory(gtest-1.7.0)
add_subdirectory(src)
add_subdirectory(tests)
