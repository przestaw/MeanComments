cmake_minimum_required(VERSION 3.10)
project("AAL")

set(EXECUTABLE ${PROJECT_NAME}-program)
set(LIBRARY ${PROJECT_NAME})
set(TEST ${PROJECT_NAME}-test)
set(CHECK ${TEST}-check)

file(GLOB LIB_SRC "src/*.cpp")
file(GLOB LIB_INC "include/*.h")
file(GLOB TEST_SRC "test/*.cpp")

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g3 -Wshadow -Wall -pedantic -Wextra -Wold-style-cast")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fdevirtualize -finline-functions -funroll-loops")

find_package(Boost COMPONENTS program_options system chrono REQUIRED)

set(EXTERNAL_LIBS "Boost::program_options" "Boost::system" "Boost::chrono")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE})

include_directories("include" ${BOOST_INCLUDE_DIR})

add_subdirectory("src")
add_subdirectory("test")

add_executable(${EXECUTABLE} main.cpp)

add_dependencies(${EXECUTABLE} ${CHECK} ${LIBRARY})

target_link_libraries(${EXECUTABLE} ${LIBRARY} ${EXTERNAL_LIBS})