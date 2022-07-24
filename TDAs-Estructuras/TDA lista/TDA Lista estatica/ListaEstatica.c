#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

Lista crearLista(){
    //Esta funcion crea una lista.
    Lista newLista;
    newLista.largoActual = 0;
    return newLista;
}

void insertarElemFin(Lista *list, int elemento){
    //Esta funcion inserta un elemeneto al final de una lista dada.
    int pos = list->largoActual;
    list->elementos[pos] = elemento;
    list->largoActual++;
}

void insertarElemPos(Lista *list, int pos, int elemento){
    //Esta funcion inserta un elemento en una posicion dada de una lista.
    if (pos <= list->largoActual){
        int i;
        int largo = list->largoActual;
        for(i = largo; pos < i;i--){
            list->elementos[i] = list->elementos[i - 1];
        }
        list->elementos[pos] = elemento;
        list->largoActual++;
    }
}

void eliminarElemFin(Lista *list){
    //Esta funcion "elimina" el elemento final de una lista, cambiando
    // el largo actual de esta.
    list->largoActual--;
}

void eliminarElemPos(Lista *list, int pos){
    //Esta funcion elimina el elemento que se encuentra en la posicion
    // de una lista dada.
    int i;
    int largo = list->largoActual;
    if (pos < largo){
        for(i = pos; i < largo;i++){
        list->elementos[i] = list->elementos[i + 1];
        }
        list->largoActual--;
    }
}

void actualizarElemPos(Lista *list, int pos, int newElement){
    //Esta funcion actualiza el numero que se encuentra en la posicion
    // de una lista dada.
    list->elementos[pos] = newElement;
}

void anularLista(Lista *list){
    //Esta funcion "anula" una lista dada, cambiando su largo a 0.
    list->largoActual = 0;
}

int largoLista(Lista *list){
    //Esta funcion entrega el largo actual de una lista.
    int largo = list->largoActual;
    return largo;
}

int posicionElem(Lista *list, int elemento){
    //Esta funcion entrega la posicion en la que se encuentrea un 
    // elemento en una lista (entrega la posicion contando desde el 1)
    int i;
    for(i = 0; (list->elementos[i] != elemento) && (i < list->largoActual); i++){
    }
    if(i == list->largoActual){
        return -1;
    }
    return i + 1;
}

int recuperaElem(Lista *list, int pos){
    //Esta funcion entrega el elemento que se encuentra en una posicion
    // de una lista.
    int elem = list->elementos[pos];
    return elem;
}

char isVaciaLista(Lista *list){
    //Esta funcion verifica si una lista es "vacia/nula" o no, en caso
    // de que el largo actual sea 0 entonces esta lo es, caso contrario
    // no lo es.
    int verif = list->largoActual;
    if(verif != 0){
        return 'F';
    }
    else{
        return 'V';
    }
}
