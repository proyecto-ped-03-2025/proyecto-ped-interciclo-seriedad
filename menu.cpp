#include <iostream>
#include "menu.h"

using namespace std;

int Menu::menuPrincipal() {
    int op;
    cout << "\n===== PIEDRA, PAPEL O TIJERA (PROYECTO FINAL) =====\n";
    cout << "1) Inscribir participante\n";
    cout << "2) Ver participantes\n";
    cout << "3) Jugar (todos contra todos)\n";
    cout << "4) Reportar ganador\n";
    cout << "5) Ayuda\n";
    cout << "6) Integrantes\n";
    cout << "0) Salir\n";
    cout << "Opcion: ";
    cin >> op;
    return op;
}