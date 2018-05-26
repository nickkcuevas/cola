#include "cola.h"
#include <stdlib.h>

struct nodo_t {
    void* dato;
    nodo_t* proximo;
};

struct cola {
    nodo_t* primero;
    nodo_t* ultimo;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

cola_t* cola_crear(void){
    cola_t* cola = malloc(sizeof(cola_t));
    if(!cola) return NULL;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}
