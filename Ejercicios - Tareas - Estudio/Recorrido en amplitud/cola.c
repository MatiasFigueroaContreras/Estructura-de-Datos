#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

Cola crearCola(){
    Cola newCola = malloc(sizeof(Cola));
    newCola->top = NULL;
    newCola->bot = NULL;
    return newCola;
}

link crearNodo(int num){
    link newNodo = malloc(sizeof(link));
    newNodo->numero = num;
    newNodo->siguiente = NULL;
    return newNodo;
}

int isEmpty(Cola cola){
    if((cola->bot == NULL) && (cola->top == NULL)){
        return 1;
    }
    else{
        return 0;
    }
}

void encolar(Cola cola, int num){
    link newNodo = crearNodo(num);
    if(isEmpty(cola) == 0){
        cola->bot->siguiente = newNodo;
    }
    else{
        cola->top = newNodo;
    }
    cola->bot = newNodo;
}

void desencolar(Cola cola){
    if(isEmpty(cola) == 0){
        link temp;
        temp = cola->top;
        if (cola->bot == cola->top){
            cola->bot = cola->bot->siguiente;
        }
        cola->top = cola->top->siguiente;
        free(temp);
    }
}

int elemTop(Cola cola){
    int elem;
    elem = cola->top->numero;
    return elem;
}

int elemBot(Cola cola){
    int elem;
    elem = cola->bot->numero;
    return elem;
}

int estaEnCola(Cola cola, int num){
    Cola tempCola = crearCola();
    int elem, ver;
    ver = 0;
    while(isEmpty(cola) != 1){
        elem = elemTop(cola);
        // printf("elemento: %d\n", elem);
        if(num == elem){
            // printf("encotrado\n");
            ver = 1;
        }
        desencolar(cola);
        encolar(tempCola, elem);
    }
    
    cola->bot = tempCola->bot;
    cola->top = tempCola->top;
    return ver;
}
