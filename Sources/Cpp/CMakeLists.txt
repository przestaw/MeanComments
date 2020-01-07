cmake_minimum_required(VERSION 3.10)
project("AAL")

#set(CMAKE_C_COMPILER clang-8)
#set(CMAKE_CXX_COMPILER clang++-8)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

cmake_policy(SET CMP0069 NEW)
include(CheckIPOSupported)
check_ipo_supported()

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g3 -Wshadow -Wall -pedantic -Wextra -Wold-style-cast")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fdevirtualize -finline-functions -funroll-loops")

find_package(Boost COMPONENTS program_options system chrono REQUIRED)

set(EXTERNAL_LIBS "Boost::program_options" "Boost::system" "Boost::chrono")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE})

include_directories("include" ${BOOST_INCLUDE_DIR})

add_subdirectory("src")