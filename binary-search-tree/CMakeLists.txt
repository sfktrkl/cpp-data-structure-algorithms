cmake_minimum_required(VERSION 3.12)
project(binary-search-tree VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
add_library(binary-search-tree INTERFACE ${HEADERS})

find_package(Catch2 REQUIRED)
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_executable(binary-search-tree-test ${TESTS})
target_link_libraries(binary-search-tree-test PRIVATE binary-search-tree Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(binary-search-tree-test)
