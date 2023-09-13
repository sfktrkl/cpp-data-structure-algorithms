cmake_minimum_required(VERSION 3.12)
project(class-templates VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_library(class-templates SHARED ${SOURCES} ${HEADERS})

find_library(ABSTRACT_DATA_TYPES abstract-data-types "${CMAKE_SOURCE_DIR}/../abstract-data-types/build")
target_link_libraries(class-templates PRIVATE ${ABSTRACT_DATA_TYPES})
find_library(FUNCTION_TEMPLATES function-templates "${CMAKE_SOURCE_DIR}/../function-templates/build")
target_link_libraries(class-templates PRIVATE ${FUNCTION_TEMPLATES})

find_package(Catch2 REQUIRED)
add_executable(class-templates-test ${TESTS})
target_link_libraries(class-templates-test PRIVATE class-templates Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(class-templates-test)
