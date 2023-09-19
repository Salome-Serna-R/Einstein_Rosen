cmake_minimum_required(VERSION 3.25)
project(Einstein_Rosen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Einstein_Rosen
        Evento.cpp
        Evento.h
        ListaDoblementeEnlazada.cpp
        ListaDoblementeEnlazada.h
        Nodo.cpp
        Nodo.h main.cpp)
