cmake_minimum_required(VERSION 3.12)
project(abstract-data-types VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_library(abstract-data-types SHARED ${SOURCES} ${HEADERS})

find_package(Catch2 REQUIRED)
add_executable(abstract-data-types-test ${TESTS})
target_link_libraries(abstract-data-types-test PRIVATE abstract-data-types Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(abstract-data-types-test)
