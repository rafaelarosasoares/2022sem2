cmake_minimum_required(VERSION 3.23)
project(lab2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(exerc�cios_ed/lista3-ListasEncadeadas/exerc1-lista3)
include_directories(exerc�cios_ed/lista3-ListasEncadeadas/exerc2-lista3)
include_directories(exerc�cios_ed/lista3-ListasEncadeadas/exerc3-lista3)
include_directories(exerc�cios_ed/lista3-ListasEncadeadas/exerc4-lista3)

add_executable(lab2022
        exerc�cios_ed/lista1-VetAlocDin/exerc1-lista1.c
        exerc�cios_ed/lista1-VetAlocDin/exerc2-lista1.c
        exerc�cios_ed/lista1-VetAlocDin/exerc3-lista1.c
        exerc�cios_ed/lista1-VetAlocDin/exerc4-lista1.c
        exerc�cios_ed/lista1-VetAlocDin/exerc5-lista1.c
        exerc�cios_ed/lista2-MatAlocDin/exerc1-lista2.c
        exerc�cios_ed/lista2-MatAlocDin/exerc2-lista2.c
        exerc�cios_ed/lista2-MatAlocDin/exerc3-lista2.c
        exerc�cios_ed/lista2-MatAlocDin/exerc4-lista2.c
        exerc�cios_ed/lista3-ListasEncadeadas/exerc1-lista3/listas.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc1-lista3/listas.h
        exerc�cios_ed/lista3-ListasEncadeadas/exerc1-lista3/main.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc2-lista3/listas.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc2-lista3/listas.h
        exerc�cios_ed/lista3-ListasEncadeadas/exerc2-lista3/main.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc3-lista3/listas.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc3-lista3/listas.h
        exerc�cios_ed/lista3-ListasEncadeadas/exerc3-lista3/main.cpp
        exerc�cios_ed/lista3-ListasEncadeadas/exerc4-lista3/lista.c
        exerc�cios_ed/lista3-ListasEncadeadas/exerc4-lista3/lista.h
        exerc�cios_ed/lista3-ListasEncadeadas/exerc4-lista3/main.c
        t1/t1.c
        t2/t2.c)
