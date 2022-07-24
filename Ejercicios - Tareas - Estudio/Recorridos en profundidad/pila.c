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

int estaEnPila(Pila pila, int num){
    Pila tempPila = crearPila();
    int ver, elem;
    ver = 0;
    while (isEmpty(pila) != 1){
        elem = elemTop(pila);
        if(elem == num){
            ver = 1;
        }
        push(tempPila, elem);
        pop(pila);
    }
    while (isEmpty(tempPila) != 1){
        elem = elemTop(tempPila);
        push(pila, elem);
        pop(tempPila);
    }
    return ver;
}

