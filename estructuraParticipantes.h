#ifndef ESTRUCTURA_PARTICIPANTES_H
#define ESTRUCTURA_PARTICIPANTES_H

#include <iostream>
using namespace std;

class ListaCircular
{
public:
    // Se define la estructura que tendra el nodo
    struct Nodo
    {
        char nombre[50];
        char id;
        int puntos;
        Nodo *sig;
    };

private:
    // Apunta al ultimo nodo de la lista circular
    Nodo *tail;

    // Convierte un caracter a mayus
    char aMayus(char c);

    // Verifica si el caracter ingresado es una letra valida
    bool esLetra(char c);

    // Funcion auxiliar recursiva
    int contarRecAux(Nodo *actual, Nodo *inicio);
};


#endif