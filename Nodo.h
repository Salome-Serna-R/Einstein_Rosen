//
// Created by Miguel Mercado on 15/09/23.
//

#ifndef EINSTEIN_ROSEN_NODO_H
#define EINSTEIN_ROSEN_NODO_H
#include <iostream>
#include <string>
#include "Evento.h"
using namespace std;


class Nodo : public Evento{
private:// Dato que contiene el nodo
    Evento evento;

public:
    int dato;
    Nodo *siguiente; // Puntero al siguiente nodo
    Nodo *anterior; // Puntero al nodo anterior
    string cientifico;
    Nodo(int dato, string cientifico, Evento evento); // Constructor

};


#endif //EINSTEIN_ROSEN_NODO_H
