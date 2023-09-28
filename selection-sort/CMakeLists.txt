cmake_minimum_required(VERSION 3.12)
project(selection-sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
add_library(selection-sort INTERFACE ${HEADERS})

find_package(Catch2 REQUIRED)
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_executable(selection-sort-test ${TESTS})
target_link_libraries(selection-sort-test PRIVATE selection-sort Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(selection-sort-test)
