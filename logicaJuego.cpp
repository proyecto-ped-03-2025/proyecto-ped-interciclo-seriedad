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

void JuegoPPT::reiniciarPuntos(ListaCircular& lista) {
    if (lista.vacia()) return;

    ListaCircular::Nodo* inicio = lista.head();
    ListaCircular::Nodo* actual = inicio;

    do {
        actual->puntos = 0;
        actual = actual->sig;
    } while (actual != inicio);
}

void JuegoPPT::jugarCompetencia(ListaCircular& lista) {
    int cantidad = lista.contar();

    if (cantidad < 2) {
        cout << "Se necesitan al menos 2 participantes para jugar.\n";
        return;
    }

    reiniciarPuntos(lista);

    cout << "\n===== INICIANDO TORNEO (Modo Manual) =====\n";
    cout << "Instrucciones: Cada jugador elige un numero entre 1-3 y presiona Enter.\n";

    ListaCircular::Nodo* cabeza = lista.head();
    ListaCircular::Nodo* jugador1 = cabeza;

    for (int i = 0; i < cantidad - 1; i++) {

        ListaCircular::Nodo* jugador2 = jugador1->sig;

        for (int j = i + 1; j < cantidad; j++) {

            cout << "\n>>> DUELO: " 
                 << jugador1->nombre << " vs " 
                 << jugador2->nombre << " <<<\n";

            cout << "\nTURNO DE " << jugador1->nombre << ":\n";
            int p1 = obtenerJugada();

            cout << "\nTURNO DE " << jugador2->nombre << ":\n";
            int p2 = obtenerJugada();

            cout << "\nRESULTADOS DEL DUELO:\n";
            cout << "-> " << jugador1->nombre << " eligio: ";
            imprimirNombreJugada(p1);
            cout << endl;

            cout << "-> " << jugador2->nombre << " eligio: ";
            imprimirNombreJugada(p2);
            cout << endl;

            int resultadoFinal = determinarGanador(p1, p2);

            if (resultadoFinal == 1) {
                cout << "GANADOR: " << jugador1->nombre << " (+3 puntos)\n";
                jugador1->puntos += 3;
            }
            else if (resultadoFinal == 2) {
                cout << "GANADOR: " << jugador2->nombre << " (+3 puntos)\n";
                jugador2->puntos += 3;
            }
            else {
                cout << "EMPATE (+1 punto a cada uno)\n";
                jugador1->puntos += 1;
                jugador2->puntos += 1;
            }

            cout << "Presione Enter para continuar.";
            cin.ignore(10000, '\n');
            cin.get();

            jugador2 = jugador2->sig;
        }

        jugador1 = jugador1->sig;
    }

    cout << "\n===== FIN DEL TORNEO =====\n";
}