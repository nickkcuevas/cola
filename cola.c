#include "cola.h"
#include <stdlib.h>

struct nodo {
    void* dato;
    nodo_t* proximo;
};

struct cola {
    nodo_t* primero;
    nodo_t* ultimo;
};

/* *****************************************************************
 *                    FUNCIONES AUXILIARES
 * *****************************************************************/


nodo_t* nodo_crear(void* dato){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL; 
    nodo->dato = dato;
    nodo->proximo = NULL;
    return nodo;
}

void* nodo_destruir(nodo_t* nodo){
    void* dato = nodo->dato;
    free(nodo);
    return dato;
}


/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/


cola_t* cola_crear(void){
    cola_t* cola = malloc(sizeof(cola_t));
    if(!cola) return NULL;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}


void cola_destruir(cola_t *cola, void destruir_dato(void*)){
    while(!cola_esta_vacia(cola)){
        void* dato = cola_desencolar(cola);
        if (destruir_dato){
            destruir_dato(dato);
        }
    }
    free(cola);
}


bool cola_esta_vacia(const cola_t *cola){
    return cola->primero == cola->ultimo && cola->primero == NULL;
}


bool cola_encolar(cola_t *cola, void* valor){
    nodo_t* nodo = nodo_crear(valor);
    if(!nodo) return false;    
    if (cola_esta_vacia(cola)){
        cola->primero = nodo;
        cola->ultimo = nodo;
    }
    else{
        if (cola->primero == cola->ultimo){
            cola->ultimo = nodo;
            cola->primero->proximo = cola->ultimo;
        }
        else{
            cola->ultimo->proximo = nodo;
            cola->ultimo = nodo;
        }
    }
    return true;
}


void* cola_ver_primero(const cola_t *cola){
    if (cola_esta_vacia(cola)) return NULL;
    return cola->primero->dato;
}


void* cola_desencolar(cola_t *cola){
    if (cola_esta_vacia(cola)) return NULL;
    nodo_t* nodo = cola->primero;
    if (cola->primero == cola->ultimo){
        cola->primero = NULL;
        cola->ultimo = NULL;
    }
    else{
        cola->primero = cola->primero->proximo;
    }
    return nodo_destruir(nodo);
}
