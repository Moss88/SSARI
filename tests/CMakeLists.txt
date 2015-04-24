# Now build our tools
enable_testing()
include_directories("${gtest_SOURCE_DIR}/include")
message(STATUS "${gtest_SOURCE_DIR}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g") 
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/test_src" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
SET(sourceFiles registerFile_UnitTest.cpp RegisterFileReader_UnitTest.cpp RegisterFileWriter_UnitTest.cpp
	ConstraintProcessor_UnitTest.cpp BoolFunction_UnitTests.cpp CFunc_UnitTest.cpp)
add_executable(testProg ${sourceFiles})
target_link_libraries(testProg ssari gtest gtest_main)
