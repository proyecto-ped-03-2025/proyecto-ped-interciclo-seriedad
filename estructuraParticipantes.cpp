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