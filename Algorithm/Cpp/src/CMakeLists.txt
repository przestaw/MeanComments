cmake_minimum_required(VERSION 3.8)
set(algorithm ${PROJECT_NAME}-algorithm)

add_executable(${algorithm} "algorithm.cpp")
target_link_libraries(${algorithm} ${EXTERNAL_LIBS})