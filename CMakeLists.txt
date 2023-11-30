cmake_minimum_required(VERSION 3.25)
project(advent-of-code)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/**.cpp" )
file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/src/*/*.cpp" "${CMAKE_SOURCE_DIR}/src/AdventFactory.cpp" "${CMAKE_SOURCE_DIR}/test/**.cpp")
file(COPY "${CMAKE_SOURCE_DIR}/data" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(advent ${SOURCES})

add_executable(advent_test ${TESTS})
find_package(Catch2 REQUIRED)
target_link_libraries(advent_test Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(advent_test)
