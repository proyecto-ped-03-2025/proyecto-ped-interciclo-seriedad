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

    // Convierte el ID a mayus para comparacion
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