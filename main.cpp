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
            case 2:
                lista.listaParticipantes();
                break;
            case 3:
                juego.jugarCompetencia(lista);
                break;
            case 4:
                menuObj.mostrarGanador(lista);
                break;
            case 5:
                menuObj.mostrarayuda();
                break;
            case 6: 
                menuObj.mostrarintegrantes();
                break;
            case 0: 
                cout<< "Saliendo del programa...\n";
                break;
            default:
                cout << "Sea serio, digite una opcion valida.\n";



        }

        if (opcion != 0) {
            cout << "\n Presiona ENTER para continuar...";
            cin.ignore(10000, '\n');
            cin.get();
        }

    } while (opcion != 0);
    return 0;
}