#include <stdio.h>
#include <stdlib.h>
#include "nodos.c"

int main(){
    //Prueba del TDA y sus operaciones.
    link lista = crearLista();
    link nodo;
    int i;
    for (i = 0; i < 10; i++){
        nodo = crearNodo(i);
        insertarNodoFinal(lista, nodo);
    }
    recorrerLista(lista);

    nodo = crearNodo(-10);
    insertarNodoInico(lista, nodo);
    printf("\n\n");
    recorrerLista(lista);

    nodo = crearNodo(65);
    insertarNodoPos(lista, nodo, 5);
    printf("\n\n");
    recorrerLista(lista);

    nodo = crearNodo(23);
    insertarNodoNum(lista, nodo, 65);
    printf("\n\n");
    recorrerLista(lista);

    link num = link_num(lista, 5);
    printf("\nNumero 5: %d\n", num->numero);
    
    link primero = primeroLista(lista);
    printf("Primero: %d\n", primero->numero);

    link ultimo = ultimoLista(lista);
    printf("Ultimo: %d", ultimo->numero);

    eliminarNodoInicio(lista);
    printf("\n\n");
    recorrerLista(lista);

    eliminarNodoFinal(lista);
    printf("\n\n");
    recorrerLista(lista);

    eliminarNodoNum(lista, 4);
    printf("\n\n");
    recorrerLista(lista);

    eliminarNodoPos(lista, 5);
    printf("\n\n");
    recorrerLista(lista);

    actualizarNodo(lista, 6, 4);
    printf("\n\n");
    recorrerLista(lista);

    int largo = largoLista(lista);
    printf("Largo lista: %d\n", largo);

    anularLista(lista);
    char ver = isVaciaLista(lista);
    printf("es Vacia?: %c\n", ver);

    nodo = crearNodo(1);
    insertarNodoFinal(lista, nodo);
    char ver2 = isVaciaLista(lista);
    printf("es Vacia?: %c", ver2);

    return 0;
}