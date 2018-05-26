#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


// /* ******************************************************************
//  *                   PRUEBAS UNITARIAS ALUMNO
//  * *****************************************************************/


/* Pruebas para una cola vacia */
void pruebas_con_cola_vacia() {
    printf("INICIO DE PRUEBAS CON COLA VACIA \n");

    /* Declaro las variables a utilizar*/
    cola_t* cola = cola_crear();

    /* Inicio de pruebas */
    print_test("Creacion de Cola no devuelve vacio", cola != NULL);
    
}


void pruebas_cola_pocos_elementos() {
}


void pruebas_cola_volumen() {
}


void pruebas_cola_alumno() {
    pruebas_con_cola_vacia();
    printf("------------------\n");
    pruebas_cola_pocos_elementos();
    printf("------------------\n");
    pruebas_cola_volumen();
}
