#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;



class Menu {
public:
    int menuPrincipal();
    void mostrarayuda();
    void leerNombre(char nombre[], int tam);
    void mostrarGanador(ListaCircular& lista);
    void mostrarintegrantes();
};

#endif