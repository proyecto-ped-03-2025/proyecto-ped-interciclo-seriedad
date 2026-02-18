#include "estructuraParticipantes.h"

ListaCircular::ListaCircular()
{
    // Se inicializa la lista vacia
    tail = NULL;
}

char ListaCircular::aMayus(char c)
{
    // Convierte una letra minuscula en mayuscula con ASCII
    if (c >= 'a' && c <= 'z')
        return char(c - ('a' - 'A'));

    // Si no es minuscula, la devuelve de igual manera
    return c;
}

bool ListaCircular::esLetra(char c)
{
    // Convierte el caracter a mayus
    c = aMayus(c);
    // Verifica si esta dentro del rango A-Z
    return (c >= 'A' && c <= 'Z');
}

bool ListaCircular::vacia()
{
    // Retorna true si la lista no tiene elementos
    return tail == NULL;
}

ListaCircular::Nodo *ListaCircular::head()
{
    // Verifica: si la lista esta vacia retorna NULL, si no, devuelve el primer nodo
    return vacia() ? NULL : tail->sig;
}

ListaCircular::Nodo *ListaCircular::buscarPorId(char id)
{
    // Si la lista esta vacia, no busca nada
    if (vacia())
        return NULL;

    // Convierte ID a mayus
    id = aMayus(id);
    // Comienza desde el primero
    Nodo *p = tail->sig;
    // Recorre la lista
    do
    {
        // Si el ID coincide, devuelve el nodo
        if (p->id == id)
            return p;
        // Se pasa al sig nodo
        p = p->sig;
        // Hasta llegar al primero
    } while (p != tail->sig);

    // Retorna NULL si no encontro el ID
    return NULL;
}

bool ListaCircular::inscribir(char nombre[], char id)
{
    // Convierte ID a mayus
    id = aMayus(id);
    // Verifica que sea letra
    if (!esLetra(id))
        return false;
    // Verifica que el ID no exista
    if (buscarPorId(id) != NULL)
        return false;

    // Crea un nuevo nodo
    Nodo *nuevo = new Nodo;

    // Copia nombre sin usar librerias <cstring>
    int i = 0;
    while (nombre[i] != '\0' && i < 49)
    {
        nuevo->nombre[i] = nombre[i];
        i++;
    }
    nuevo->nombre[i] = '\0';

    // Se asignan datos
    nuevo->id = id;
    nuevo->puntos = 0;

    // Se inserta en la lista circular
    if (vacia())
    {
        // Si esta vacia, el nodo se apunta a si mismo
        tail = nuevo;
        tail->sig = tail;
    }
    else
    {
        // Apunta al primero, el ultimo apunta al nuevo, el nuevo ahora es el ultimo
        nuevo->sig = tail->sig;
        tail->sig = nuevo;
        tail = nuevo;
    }

    // Retorna true si la insercion fue exitosa
    return true;
}

void ListaCircular::listaParticipantes()
{
    // Verificar si la lista está vacía
    if (vacia())
    {
        cout << "\nNo hay participantes inscritos.\n";
        return;
    }

    cout << "\n=== PARTICIPANTES ===\n";
    // Empieza desde el primer nodo
    Nodo *p = tail->sig;
    // Recorre la lista circular
    do
    {
        cout << "[" << p->id << "] " << p->nombre
             << " | Puntos: " << p->puntos << "\n";
        // Avanza al siguiente nodo
        p = p->sig;
    } while (p != tail->sig); // Hasta llegar al primer nodo
}

int ListaCircular::contar()
{
    // Verifica si la lista esta vacia
    if (vacia())
        return 0;

    int c = 0;
    // Empieza desde el primer nodo
    Nodo *p = tail->sig;
    // Recorre la lista circular
    do
    {
        // Aumenta el contador y avanza al siguiente nodo
        c++;
        p = p->sig;
    } while (p != tail->sig); // Para hasta llegar al primero

    // Retorna el total de nodos
    return c;
}

// ===== Recursión =====
int ListaCircular::contarRecAux(Nodo *actual, Nodo *inicio)
{
    if (actual == NULL)
        return 0;
    // Si el sig nodo es el inicio significa que esta en el ultimo nodo
    if (actual->sig == inicio)
        return 1;
    // Contar ese nodo + llamada recursiva al sig
    return 1 + contarRecAux(actual->sig, inicio);
}

int ListaCircular::contarRec()
{
    // Verifica si la lista esta vacia
    if (vacia())
        return 0;
    // Obtiene el primer nodo
    Nodo *inicio = tail->sig;
    // Retorna la funcion auxiliar recursiva
    return contarRecAux(inicio, inicio);
}