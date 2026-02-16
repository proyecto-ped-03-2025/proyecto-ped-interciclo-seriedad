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

void Menu::mostrarayuda() {
    cout << "\n=== AYUDA ===\n";
    cout << "Inscribir Participantes: ingrese nombre e ID (letra unica para tu nombre).\n";
    cout << "Listar Participantes: muestra participantes y puntajes.\n";
    cout << "Jugar: todos contra todos (sin repetir partidas).\n";
    cout << "   Jugadas: 1 Piedra, 2 Papel, 3 Tijera.\n";
    cout << "   Puntaje: ganador=3, empate=1, perder=0.\n";
    cout << "Reportar Ganador: ganador o EMPATE si todos tienen el mismo puntaje.\n";
    cout << "Integrantes: muestra los nombres y carnets de los integrantes del proyecto.\n";
}

void Menu::leerNombre(char nombre[], int tam) {
    cout << "Nombre (con espacios): ";
    cin.ignore(10000, '\n');
    cin.getline(nombre, tam);
}

void Menu::mostrarGanador(ListaCircular& lista) {
    if (lista.vacia()) {
        cout << "\nNo hay participantes para determinar un ganador.\n";
        return;
    }

    ListaCircular::Nodo* inicio = lista.head();
    ListaCircular::Nodo* actual = inicio;
    
    //puntaje maximo
    int maxPuntos = -1;
    do {
        if (actual->puntos > maxPuntos) {
            maxPuntos = actual->puntos;
        }
        actual = actual->sig;
    } while (actual != inicio);

    //cuantos lo tienen
    int contadoresMax = 0;
    actual = inicio;
    do {
        if (actual->puntos == maxPuntos) {
            contadoresMax++;
        }
        actual = actual->sig;
    } while (actual != inicio);

    // resultados ganador  si hay empate
    cout << "\n=== RESULTADOS DEL TORNEO ===\n";
    
    if (contadoresMax > 1) {
        cout << "EMPATE!\n";
        cout << "Se encontraron " << contadoresMax << " participantes con " << maxPuntos << ":\n";
    } else {
        cout << "GANADOR!\n";
    }

    // decir el ganador o los que empatan
    actual = inicio;
    do {
        if (actual->puntos == maxPuntos) {
            cout << "-> " << actual->nombre << " [" << actual->id << "] | Puntos: " << actual->puntos << "\n";
        }
        actual = actual->sig;
    } while (actual != inicio);
}

void mostrarintegrantes() {
    cout << "\n=== INTEGRANTES DEL PROYECTO ===\n";
    cout << "1. Jose Andres Calles Ramirez - 00054525\n";
    cout << "2. Daniel Alexander Avelar Orellana - 00089625\n";
    cout << "3. Rodrigo Josue Medrano Marquez - 00148625\n";
}