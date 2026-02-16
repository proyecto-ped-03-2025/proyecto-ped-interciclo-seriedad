#ifndef LOGICA_JUEGO_H
#define LOGICA_JUEGO_H
#include <iostream>
using namespace std;

#include "estructuraParticipantes.h"


class JuegoPPT {
    private:
        int obtenerJugada();
        void imprimirNombreJugada(int jugada);
        int determinarGanador(int p1, int p2);
    public:
    void reiniciarPuntos(ListaCircular& lista);
    void jugarCompetencia(ListaCircular& lista);
};


#endif