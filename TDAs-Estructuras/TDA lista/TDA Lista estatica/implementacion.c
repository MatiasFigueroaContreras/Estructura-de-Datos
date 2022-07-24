#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.c"

void readArray(int *array, int lenght){
    //Esta funcion lee un arreglo y imprime sus elementos en un formato especifico
    int i;
    printf("{");
    for(i = 0; i < lenght; i++){
        if (i == lenght - 1){
            printf("%i", *(array + i));
        }
        else{
            printf("%i, ", *(array + i));
        }
    }
    printf("}");
}

int main(){
    //Prueba del TDA y sus operaciones.
    Lista listanueva = crearLista();
    Lista * punteroLista;
    punteroLista = &listanueva;
    int i;
    for(i = 1; i <= 5; i++){
        insertarElemFin(punteroLista, i);
    }
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    insertarElemPos(punteroLista, 2, 8);
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");
    
    eliminarElemFin(punteroLista);
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    eliminarElemPos(punteroLista, 4);
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    actualizarElemPos(punteroLista, 2, 3);
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    int largo = largoLista(punteroLista);
    printf("Largo Lista: %d\n", largo);

    int posicion = posicionElem(punteroLista, 2);
    printf("Posicion: %d\n", posicion);

    int elem = recuperaElem(punteroLista, 0);
    printf("Elemento: %d\n", elem);

    anularLista(punteroLista);
    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    char verif1 = isVaciaLista(punteroLista);
    printf("Es vacia?: %c", verif1);
    printf("\n");
    for (i = 1; i <= 6; i++){
        insertarElemFin(punteroLista, i);
    }

    readArray(punteroLista->elementos, punteroLista->largoActual);
    printf("\n");

    char verif2 = isVaciaLista(punteroLista);
    printf("Es vacia?: %c", verif2);

    return 0;
}