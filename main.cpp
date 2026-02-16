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
    } while (opcion != 0);
    return 0;
}