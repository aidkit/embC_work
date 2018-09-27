
cmake_minimum_required( VERSION 2.8 )
project( unity-test )

set( UNITY_ROOT lib/Unity )

include_directories( ${UNITY_ROOT}/src )
include_directories( ${UNITY_ROOT}/extras/fixture/src )
include_directories( include/ )
link_libraries( m )

set(
    UNITY_FILES

        ${UNITY_ROOT}/src/unity.c
        ${UNITY_ROOT}/extras/fixture/src/unity_fixture.c
)

set(
    TEST_FILES

        test/testcases/my_math_test.c
        test/testcases/my_string_test.c
        
)

set(
    SOURCE_FILES

        src/my_math.c
        src/my_string.c
        
)

set(
    TEST_RUNNER_FILES

        test/runner/my_math_test_runner.c
        test/runner/my_string_test_runner.c
        test/runner/all_tests.c
)

# CMAKE_BUILD_TYPEの指定がない場合Releaseに設定
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

# C++11を使用
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(STATUS "${CMAKE_CXX_COMPILER} has no C++11 support. Pleasae use a different C++ compiler.")
endif()


add_executable( unity_test ${SOURCE_FILES} ${TEST_FILES} ${TEST_RUNNER_FILES} ${UNITY_FILES} )

