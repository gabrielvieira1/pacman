cmake_minimum_required(VERSION 3.23)
project(pacman C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pacman
        mapa.c
        mapa.h
        pacman.c
        pacman.h
        ui.c
        ui.h)
