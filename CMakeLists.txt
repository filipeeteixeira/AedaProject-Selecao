cmake_minimum_required(VERSION 3.14.5)
project(codigo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(codigo
        BST.h
        Convocatoria.cpp
        Convocatoria.h
        Date.cpp
        Date.h
        Jogador.cpp
        Jogador.h
        Jogo.cpp
        Jogo.h
        main.cpp
        Menus.cpp
        Menus.h
        Selecao.cpp
        Selecao.h
        Staff.cpp
        Staff.h
        Utils.cpp
        Utils.h)
