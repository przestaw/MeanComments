cmake_minimum_required(VERSION 3.8)
project("AAL")

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(Boost COMPONENTS program_options REQUIRED)

include_directories(${BOOST_INCLUDE_DIR})

set(EXTERNAL_LIBS "Boost::program_options")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(Generator/Cpp)
add_subdirectory(Algorithm/Cpp)