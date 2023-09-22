cmake_minimum_required(VERSION 3.12)
project(graph-dfs VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_library(graph-dfs SHARED ${SOURCES} ${HEADERS})

find_library(GRAPH graph "${CMAKE_SOURCE_DIR}/../graph/build")
target_link_libraries(graph-dfs PRIVATE ${GRAPH})

find_package(Catch2 REQUIRED)
add_executable(graph-dfs-test ${TESTS})
target_link_libraries(graph-dfs-test PRIVATE graph-dfs ${GRAPH} Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(graph-dfs-test)
