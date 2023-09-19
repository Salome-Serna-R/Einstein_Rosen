//
// Created by Miguel Mercado on 5/09/23.
//

#include "ListaDoblementeEnlazada.h"
#include <iostream>
#include <string>
using namespace std;
#include "Evento.h"
#include <cmath>
#include <cstdlib>
#include <ctime>



int eventoNuevo;
int eventoCreado = 0;
bool realizadoA = false;
bool realizadoB = false;
int nombre = 0;

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->datoGenerado = 0;
    this->datoEvento1 = 0;
    this->datoEvento2 = 0;
    this->datoEvento3 = 0;
}

bool esPrimo(int numero) {
    int contador = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            contador++;
        }
    }
    if (contador == 2) {
        return true;
    } else {
        return false;
    }
}

bool esCoprimo(int numero1, int numero2) {
    if (numero1 == 0 || numero2 == 0)
        return false;

    int menor = std::min(numero1, numero2);

    for (int i = 2; i <= std::sqrt(menor); ++i) {
        if (numero1 % i == 0 && numero2 % i == 0)
            return false;
    }

    return true;
}



int ListaDoblementeEnlazada::obtenerDatoGenerado() {
    return this->datoGenerado;
}




void ListaDoblementeEnlazada::insertar(string cientifico, Evento evento) {
    this->datoGenerado = rand() % 100; // 0 a 99
    nombre = rand() % 100 + 1; // 1 a 100
    if (nombre % 2 == 0) {
        this->cientifico = "E";
    } else {
        this->cientifico = "R";
    }
    Nodo *nuevo = new Nodo(this->datoGenerado, this->cientifico, evento);
    if (this->primero == nullptr) {
        this->primero = nuevo;
        this->ultimo = nuevo;
    } else {
        this->ultimo->siguiente = nuevo; // El ultimo apunta al nuevo
        nuevo->anterior = this->ultimo; // El nuevo apunta al anterior para que no se pierdan datos
        this->ultimo = nuevo; // El nuevo es el ultimo
    }

}


void ListaDoblementeEnlazada::print(int dato, string cientifico, Evento evento) {
    cout << "[NULL] -> ";

    Nodo *temp = this->primero;
    while (temp != nullptr) {
        cout << "[" << temp->dato << "|" << temp->cientifico << "]" << " -> ";
        temp = temp->siguiente;
    }
    cout << "[NULL]" << endl;
}

string ListaDoblementeEnlazada::obtenerCientifico() {
    return this->cientifico;
}

void ListaDoblementeEnlazada::eventos(int dato, string cientifico, Evento evento) {

    if (esPrimo(dato) && realizadoA == false && obtenerCientifico() == "E") {
        eventoNuevo = evento.EventoTipoA();
        setDatoEvento1(dato);
        cout << datoEvento1 << endl;
        cout << "[" << datoEvento1 << "|" << "E" << "|" << "A" << "]" << endl;
        realizadoA = true;
        eventoCreado = 1;
    }
    static string nombreCientificoB;
    if (eventoCreado == 1 && esPrimo(dato) && realizadoB == false) {
        setDatoEvento2(dato);
        if (datoEvento1 != datoEvento2 && nombreCientificoB.empty()) {
            nombreCientificoB = obtenerCientifico(); // Asignar el nombre del científico B
            eventoNuevo = evento.EventoTipoB();
            cout << datoEvento2 << endl;
            cout << "[" << datoEvento1 << "|" << "E" << "|" << "A" << "]" << "->" << "[" << datoEvento2 << "|" << nombreCientificoB << "|" << "B" << "]" << endl;
            realizadoB = true;
            eventoCreado = 2;
        }

    }

    string cientificoC = obtenerCientifico();
    if (eventoCreado == 2 && esCoprimo(dato, datoGenerado) && realizadoA == true && realizadoB == true) {
        setDatoEvento3(dato);
        if (datoEvento2 != datoEvento3) {
        eventoNuevo = evento.EventoTipoC();
        cout << datoEvento3 << endl;
            if (esPrimo(datoEvento3)) {
                cout << "Se ha viajado y se han compartido datos" << endl;
                cout << "[" << datoEvento1 << "|" << "E" << "|" << "A" << "]" << "->" << "[" << datoEvento2 << "|"
                     << nombreCientificoB << "|" << "B" << "]" << "->" << "[" << datoEvento3 << "|" << cientificoC << "|" << "C" << "]" << endl;
                realizadoA = false;
                realizadoB = false;
                eventoCreado = 0;
            } else {
                cout << "Se ha viajado y no se han compartido datos" << endl;
                cout << "[" << datoEvento1 << "|" << "E" << "|" << "A" << "]" << "->" << "[" << datoEvento2 << "|"
                     << nombreCientificoB << "|" << "B" << "]" << "->" << "[" << datoEvento3 << "|" << cientificoC << "|" << "C" << "]" << endl;
                realizadoA = false;
                realizadoB = false;
                eventoCreado = 0;
            }
        }
    }
}



