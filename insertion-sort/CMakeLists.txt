cmake_minimum_required(VERSION 3.12)
project(insertion-sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
add_library(insertion-sort INTERFACE ${HEADERS})

find_package(Catch2 REQUIRED)
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_executable(insertion-sort-test ${TESTS})
target_link_libraries(insertion-sort-test PRIVATE insertion-sort Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(insertion-sort-test)
