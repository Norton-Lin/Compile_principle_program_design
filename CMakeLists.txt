cmake_minimum_required(VERSION 3.23)
project(Compile_principle_program_design)

set(CMAKE_CXX_STANDARD 14)

include_directories(backend/lexical_analysis/src)

add_executable(Compile_principle_program_design
        backend/lexical_analysis/src/lex.yy.cpp
        backend/lexical_analysis/src/main.h
        backend/lexical_analysis/src/main.cpp
        backend/lexical_analysis/src/Disposal.cpp)
