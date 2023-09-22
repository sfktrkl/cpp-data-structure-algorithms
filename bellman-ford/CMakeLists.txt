cmake_minimum_required(VERSION 3.12)
project(bellman-ford VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*/*.h")
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_library(bellman-ford SHARED ${SOURCES} ${HEADERS})

find_library(GRAPH graph "${CMAKE_SOURCE_DIR}/../graph/build")
target_link_libraries(bellman-ford PRIVATE ${GRAPH})

find_package(Catch2 REQUIRED)
add_executable(bellman-ford-test ${TESTS})
target_link_libraries(bellman-ford-test PRIVATE bellman-ford ${GRAPH} Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(bellman-ford-test)
