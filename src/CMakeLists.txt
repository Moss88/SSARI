# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -g -Wall")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# Now build our tools
add_library(ssari ${PROJECT_SOURCES})



# Link against LLVM libraries
target_link_libraries(ssari xml++-2.6 xml2 glibmm-2.4 gobject-2.0 sigc-2.0 glib-2.0)

install(TARGETS ssari DESTINATION /usr/lib)
install (DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../include/" DESTINATION /usr/include/SSARI)

