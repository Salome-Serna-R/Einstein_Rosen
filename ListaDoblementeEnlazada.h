//
// Created by Miguel Mercado on 5/09/23.
//

#ifndef EINSTEIN_ROSEN_LISTADOBLEMENTEENLAZADA_H
#define EINSTEIN_ROSEN_LISTADOBLEMENTEENLAZADA_H
#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;

class ListaDoblementeEnlazada {
public:
    Nodo *head; // Puntero al inicio de la lista, a la cabeza

    ListaDoblementeEnlazada(); // Constructor

    void insertar(string cientifico, Evento evento); // Insertar un nodo al inicio de la lista

    void eventos(int dato, string cientifico, Evento evento); // realizar los eventos y imprimirlos

    void print(int dato, string cientifico, Evento evento); // Imprimir la lista

    int obtenerDatoGenerado(); // Obtener el dato generado

    string obtenerCientifico(); // Obtener el cientifico

    void setDatoEvento1(int dato) {
        datoEvento1 = dato;
    }

    void setDatoEvento2(int dato) {
        datoEvento2 = dato;
    }

    void setDatoEvento3(int dato) {
        datoEvento3 = dato;
    }

private:
    Nodo *primero;
    Nodo *ultimo;
    int datoGenerado;
    string cientifico;
    int datoEvento1;
    int datoEvento2;
    int datoEvento3;
};


#endif //EINSTEIN_ROSEN_LISTADOBLEMENTEENLAZADA_H
