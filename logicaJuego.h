#ifndef LOGICA_JUEGO_H
#define LOGICA_JUEGO_H
#include <iostream>
using namespace std;




class juegoPPT {
    private:
        int obtenerJugada();
        void imprimirNombreJugada(int jugada);
        int determinarGanador(int p1, int p2);
    public:
    void reiniciarPuntos(ListaCircular& lista);
};


#endif