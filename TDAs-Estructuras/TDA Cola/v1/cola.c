#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

Cola crearCola(){
    Cola newCola = malloc(sizeof(Cola));
    newCola->top = NULL;
    newCola->bot = NULL;
    return newCola;
}

nodo crearNodo(int num){
    nodo newNodo = malloc(sizeof(nodo));
    newNodo->numero = num;
    newNodo->siguiente = NULL;
    return newNodo;
}

int isEmpty(Cola cola){
    if(cola->bot && cola->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void encolar(Cola cola, int num){
    nodo newNodo = crearNodo(num);
    if(isEmpty(cola) == 0){
        cola->top = newNodo;
    }
    cola->bot = newNodo;
}

void desencolar(Cola cola){
    if(isEmpty(cola) == 0){
        nodo temp;
        temp = cola->top;
        cola->top = cola->top->siguiente;
        free(temp);
    }
}
