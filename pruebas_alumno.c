#include "cola.h"
#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
size_t CANT_ENCOLAR = 1000;


/* *****************************************************************
 *                    FUNCIONES AUXILIARES
 * *****************************************************************/

void pila_destruir_wrapper(void* pila){
	pila_destruir((pila_t*) pila);
}


// /* ******************************************************************
//  *                   PRUEBAS UNITARIAS ALUMNO
//  * *****************************************************************/


/* Pruebas para una cola vacia */
void pruebas_cola_vacia() {
    printf("INICIO DE PRUEBAS CON COLA VACIA \n");

    cola_t* cola = cola_crear();

    print_test("Creacion de Cola no devuelve NULL", cola != NULL);
    print_test("Cola esta vacia devuelve True", cola_esta_vacia(cola) == true);
    print_test("Cola ver primero devuelve NULL", cola_ver_primero(cola) == NULL);
    print_test("Cola desencolar devuelve NULL", cola_desencolar(cola) == NULL);

    cola_destruir(cola, NULL);
    print_test("Se destruyo la Cola", true);
}


void pruebas_cola_pocos_elementos() {
    printf("INICIO DE PRUEBAS COLA POCOS ELEMENTOS \n");

    cola_t* cola = cola_crear();
    int elementos[] = {1,2,3};
    
    print_test("Cola encolar 1 devuelve True", cola_encolar(cola, &elementos[0]) == true);
    print_test("Cola encolar 2 devuelve True", cola_encolar(cola, &elementos[1]) == true);
    print_test("Cola encolar 3 devuelve True", cola_encolar(cola, &elementos[2]) == true);
    print_test("Cola ver primero devuelve 1", *((int*)cola_ver_primero(cola)) == elementos[0]);
    print_test("Cola desencolar devuelve 1", *((int*)cola_desencolar(cola)) == elementos[0]);
    print_test("Cola ver primero devuelve 2", *((int*)cola_ver_primero(cola)) == elementos[1]);
    print_test("Cola desencolar devuelve 2", *((int*)cola_desencolar(cola)) == elementos[1]);
    print_test("Cola ver primero devuelve 3", *((int*)cola_ver_primero(cola)) == elementos[2]);
    print_test("Cola encolar 2 devuelve True", cola_encolar(cola, &elementos[1]) == true);
    print_test("Cola encolar 1 devuelve True", cola_encolar(cola, &elementos[0]) == true);
    print_test("Cola ver primero devuelve 3", *((int*)cola_ver_primero(cola)) == elementos[2]);
    
    cola_destruir(cola, NULL);
    print_test("Se destruyo la Cola", true);
}


void pruebas_cola_volumen() {
    printf("INICIO DE PRUEBAS COLA VOLUMEN \n");

    cola_t* cola = cola_crear();    
    pila_t** pilas = malloc(CANT_ENCOLAR * sizeof(pila_t*));
    for (int i=0; i< CANT_ENCOLAR; i++){
        pila_t* pila = pila_crear();
        pilas[i] = pila;
    }
    bool encolando_ok = true;
    for (int i=0; i< CANT_ENCOLAR; i++){
        if(!cola_encolar(cola, pilas[i])){
            encolando_ok = false;
        }
    }
    printf("Cola encolar ");
    printf("%zd elementos de tipo pila ", CANT_ENCOLAR);
    print_test("devuelve True", encolando_ok == true);
    print_test("Cola esta vacia devuelve False", cola_esta_vacia(cola) == false);

    cola_destruir(cola, pila_destruir_wrapper);
    free(pilas);

    print_test("Se destruyo la Cola", true);
}


void pruebas_cola_alumno() {
    pruebas_cola_vacia();
    printf("------------------\n");
    pruebas_cola_pocos_elementos();
    printf("------------------\n");
    pruebas_cola_volumen();
}
