#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila crearPila(){
    Pila newPila = malloc(sizeof(Pila));
    newPila->siguiente = NULL;
    return newPila;
}

Pila crearNodo(int num){
    Pila newNodo = malloc(sizeof * newNodo);
    newNodo->numero = num;
    newNodo->siguiente = NULL;
    return newNodo;
}

int isEmpty(Pila top){
    if(top->siguiente == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// 1era forma
// void push(Pila top, Pila newNodo){
//     if(isEmpty(top) == 0){
//         newNodo->siguiente = top->siguiente;
//     }
//     top->siguiente = newNodo;
// }


// 2da forma
void push(Pila top, int num){
    Pila newNodo;
    newNodo = crearNodo(num);
    if(isEmpty(top) == 0){
        newNodo->siguiente = top->siguiente;
    }
    top->siguiente = newNodo;
}

int pop(Pila top){
    if (isEmpty(top) == 0){
        Pila temp;
        int numero;
        temp = top->siguiente;
        numero = temp->numero;
        top->siguiente = top->siguiente->siguiente;
        free(temp); 
        return numero;   
    }
}
