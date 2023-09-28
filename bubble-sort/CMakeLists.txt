cmake_minimum_required(VERSION 3.12)
project(bubble-sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
add_library(bubble-sort INTERFACE ${HEADERS})

find_package(Catch2 REQUIRED)
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_executable(bubble-sort-test ${TESTS})
target_link_libraries(bubble-sort-test PRIVATE bubble-sort Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(bubble-sort-test)
