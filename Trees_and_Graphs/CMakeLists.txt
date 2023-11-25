cmake_minimum_required(VERSION 3.26)
project(Trees_and_Graphs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Trees_and_Graphs
        BST.h
        force_multiplier.h
        main.c
        bin/scratch.c
        bin/scratch1.c
        DBMS.h)
