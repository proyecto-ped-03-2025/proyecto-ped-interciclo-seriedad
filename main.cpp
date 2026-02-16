#include <iostream>
#include "estructuraParticipantes.h" 
#include "logicaJuego.h"       
#include "Menu.h"              

using namespace std;
int main(){
    ListaCircular lista; 
    JuegoPPT juego;      
    Menu menuObj;        

    int opcion;
    char nombre[50];
    char id;

    do {
        opcion = menuObj.menuPrincipal();

        switch (opcion) {
            case 1:
            menuObj.leerNombre(nombre, 50);

            cout << "Ingresa tu ID (letra unica): \n ";
            cin >> id;

            if (lista.inscribir(nombre, id)) {
                    cout << "Participante inscrito con exito.\n";
                } else {
                    cout << "Error: ID invalido (no es letra) o ya esta ocupado.\n";
                }
                break;
        }
    } while (opcion != 0);
    return 0;
}