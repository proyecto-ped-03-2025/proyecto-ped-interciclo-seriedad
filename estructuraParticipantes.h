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
};


#endif