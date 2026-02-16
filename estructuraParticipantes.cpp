#include "estructuraParticipantes.h"

ListaCircular::ListaCircular()
{
    // Se inicializa la lista vacia
    tail = NULL;
}

char ListaCircular::aMayus(char c)
{
    // Convierte una letra minuscula en mayuscula con ASCII
    if(c >= 'a' && c <= 'z') return char(c - ('a' - 'A'));

    // Si no es minuscula, la devuelve de igual manera
    return c;
}