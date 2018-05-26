// #include "cola.h"
// #include "testing.h"
// #include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>


// /* ******************************************************************
//  *                   PRUEBAS UNITARIAS ALUMNO
//  * *****************************************************************/


// /* Pruebas para una pila vacia */
// void pruebas_con_pila_vacia() {
//     printf("INICIO DE PRUEBAS CON PILA VACIA \n");

//     /* Declaro las variables a utilizar*/
//     pila_t* pila = pila_crear();

//     /* Inicio de pruebas */
//     print_test("crear pila vacia inicialmente vacia", pila_esta_vacia(pila) == true);
//     print_test("obtener tope de pila devuelve NULL", pila_ver_tope(pila) == NULL);
//     print_test("pila desapilar devuelve NULL", pila_desapilar(pila) == NULL);

//     pila_destruir(pila);
//     print_test("la pila fue destruida", true);
// }


// /* Pruebas para una pila vacia */
// void pruebas_pila_pocos_elementos() {
//     printf("INICIO DE PRUEBAS CON POCOS ELEMENTOS \n");

//     /* Declaro las variables a utilizar*/
//     pila_t* pila = pila_crear();


//     size_t cantidad_elementos_a_apilar = 11;
//     int* datos = malloc(cantidad_elementos_a_apilar * sizeof(int));
//     bool apilando = true;
//     for (int i=0; i < cantidad_elementos_a_apilar; i++){
//         datos[i] = i;
//         if(!pila_apilar(pila, &datos[i])){
//             apilando = false;
//         }
//     }

//     /* Inicio de pruebas */
//     print_test("Apilar pila con numeros de 0 a 10 ", apilando == true);
//     int valor_tope_pila = *((int*)pila_ver_tope(pila));
//     print_test("Pila desapilar devuelve 10", *((int*)pila_desapilar(pila)) == valor_tope_pila);
//     valor_tope_pila--;
//     print_test("Obtener tope de pila devuelve 9", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     print_test("Pila desapilar devuelve 9", *((int*)pila_desapilar(pila)) == valor_tope_pila);
//     valor_tope_pila--;
//     print_test("Obtener tope de pila devuelve 8", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     print_test("Pila desapilar devuelve 8", *((int*)pila_desapilar(pila)) == valor_tope_pila);
//     valor_tope_pila--;
//     print_test("Obtener tope de pila devuelve 7", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     int diez = 10;
//     print_test("Pila apilar 10 devuelve true", pila_apilar(pila, &diez) == true);
//     print_test("Obtener tope de pila devuelve 10", *((int*)pila_ver_tope(pila)) == diez);
//     print_test("Pila desapilar devuelve 10", *((int*)pila_desapilar(pila)) == diez);
//     print_test("Obtener tope de pila devuelve 7", *((int*)pila_ver_tope(pila)) == valor_tope_pila);

//     pila_destruir(pila);
//     print_test("la pila fue destruida", true);
//     free(datos);
// }


// /* Pruebas para una pila que contiene elementos */
// void pruebas_pila_volumen() {
//     printf("INICIO DE PRUEBAS DE VOLUMEN \n");

//     /* Declaro las variables a utilizar*/
//     pila_t* pila = pila_crear();
//     size_t cantidad_elementos_a_apilar = 1001;
//     int* datos = malloc(cantidad_elementos_a_apilar * sizeof(int));
//     bool apilando = true;
//     for (int i=0; i < cantidad_elementos_a_apilar; i++){
//         datos[i] = i;
//      if(!pila_apilar(pila, &datos[i])){
//             apilando = false;
//         }
//     }

//     /* Inicio de pruebas */
//     printf("Apilar primeros ");
//     printf("%d", (int)cantidad_elementos_a_apilar);
//     print_test(" numeros naturales en la pila", apilando == true);
//     print_test("Pila esta vacia devuelve false", pila_esta_vacia(pila) == false);

//     int valor_tope_pila = *((int*)pila_ver_tope(pila));
    
//     print_test("Obtener tope de pila devuelve 1000", *((int*)pila_ver_tope(pila)) == valor_tope_pila);

//     printf("Desapilando 100 elementos....\n");
//     int desapilar_cien_elementos = 100;
//     bool desapilando_en_orden_correcto = true;
//     for(int i=0; i < desapilar_cien_elementos; i++){
//         int tope = *((int*)pila_desapilar(pila));
//         if (valor_tope_pila != tope){
//             desapilando_en_orden_correcto = false;
//         }
//         valor_tope_pila--;
//     }
//     print_test("Se desapilaron 100 elementos en orden correcto ", desapilando_en_orden_correcto == true);
//     print_test("Obtener tope de pila devuelve 900", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     print_test("Obtener elemento desapilado de pila devuelve 900", *((int*)pila_desapilar(pila)) == valor_tope_pila);
//     valor_tope_pila--;
//     print_test("Obtener tope de pila devuelve 899", *((int*)pila_ver_tope(pila)) == valor_tope_pila);

//     printf("Desapilando 600 elementos....\n");
//     int desapilar_seiscientos_elementos = 600;
//     for(int i=0; i < desapilar_seiscientos_elementos; i++){
//         pila_desapilar(pila);
//     }
//     valor_tope_pila -= desapilar_seiscientos_elementos;
//     print_test("Obtener tope de pila devuelve 299", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     print_test("Obtener elemento desapilado devuelve 299", *((int*)pila_desapilar(pila)) == valor_tope_pila);
//     valor_tope_pila--;
//     print_test("Obtener tope de pila devuelve 298", *((int*)pila_ver_tope(pila)) == valor_tope_pila);
//     pila_destruir(pila);
//     print_test("la pila fue destruida", true);
//     free(datos);
// }


// void pruebas_pila_alumno() {
//     pruebas_con_pila_vacia();
//     printf("------------------\n");
//     pruebas_pila_pocos_elementos();
//     printf("------------------\n");
//     pruebas_pila_volumen();
// }
