#include "logicaJuego.h"

int JuegoPPT::obtenerJugada() {
    int opcion = 0;

    do {
        cout << "----------------------------------------\n";
        cout << "Escoge entre estas 3 opciones:\n";
        cout << "1. Piedra\n";
        cout << "2. Papel\n";
        cout << "3. Tijera\n";
        cout << "Ingrese su opcion (1-3): ";

        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Ingrese un numero (1-3): ";
        }

        if (opcion < 1 || opcion > 3) {
            cout << "Sea serio, escoge una opcion valida.\n";
        }

    } while (opcion < 1 || opcion > 3);

    for (int i = 0; i < 50; i++) cout << endl;
    return opcion;
}

void JuegoPPT::imprimirNombreJugada(int jugada) {
    if (jugada == 1) cout << "Piedra";
    else if (jugada == 2) cout << "Papel";
    else if (jugada == 3) cout << "Tijera";
    else cout << "Desconocido";
}

int JuegoPPT::determinarGanador(int p1, int p2) {
    if (p1 == p2) return 0;

    if ((p1 == 1 && p2 == 3) ||
        (p1 == 2 && p2 == 1) ||
        (p1 == 3 && p2 == 2))
        return 1;

    return 2;
}