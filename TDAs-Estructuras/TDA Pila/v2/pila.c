#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila crearPila(){
    Pila newPila = malloc(sizeof(Pila));
    newPila->top = NULL;
    return newPila;
}

link crearNodo(int num){
    link newNodo = malloc(sizeof * newNodo);
    newNodo->numero = num;
    newNodo->siguiente = NULL;
    return newNodo;
}

int isEmpty(Pila pila){
    if(pila->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(Pila pila, int num){
    link newNodo;
    newNodo = crearNodo(num);
    if(isEmpty(pila) == 0){
        newNodo->siguiente = pila->top;
    }
    pila->top = newNodo;
}

void pop(Pila pila){
    if (isEmpty(pila) == 0){
        link temp;
        temp = pila->top;
        pila->top = pila->top->siguiente;
        free(temp); 
    }
}

int elemTop(Pila pila){
    int elem;
    if(pila->top != NULL){
        elem = pila->top->numero;
        return elem;
    }
    else{
        return NULL;
    }
}
