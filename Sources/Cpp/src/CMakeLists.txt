cmake_minimum_required(VERSION 3.8)
set(program ${PROJECT_NAME}-program)

add_executable(${program} "main.cpp" Generator.cpp ../include/Generator.h)

target_link_libraries(${program} ${EXTERNAL_LIBS})