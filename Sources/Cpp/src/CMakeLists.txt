cmake_minimum_required(VERSION 3.10)
set(program ${PROJECT_NAME}-program)

add_executable(${program} "main.cpp" Generator.cpp ../include/Generator.h Solver.cpp ../include/Solver.h)

target_link_libraries(${program} ${EXTERNAL_LIBS} -static-libgcc -static-libstdc++ -static)