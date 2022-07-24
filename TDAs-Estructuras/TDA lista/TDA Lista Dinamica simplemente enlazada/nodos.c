#include <stdio.h>
#include <stdlib.h>
#include "nodos.h"

link last_link(link head){
    //Esta funcion entrega el ultimo link(puntero a la estructura de los nodos) el cual
    // esta apuntando a una ubicacion nula.
    link last = head;
    while(last->siguiente != NULL){
        last = last->siguiente;
    }
    return last;
}

link pos_link(link head, int pos, int inicio){
    //Esta funcion entrega el link que pertenece a la posicion dada, en el caso de que
    // el inicio parta desde 0, por otro lado si este parte por 1, sera el link anterior
    // a la posicion dada (la posicion del numero contando dese 1).
    link nodoP = head;
    int i;
    for(i = inicio; i < pos; i++){
        if(nodoP->siguiente == NULL){
            return NULL;
        }
        else{
            nodoP = nodoP->siguiente;
        }
    }
    return nodoP;
}

link link_num(link head, int num){
    //Esta funcion entrega el link que pertenece a el numero dado.
    link pos = head;
    while (pos->numero != num){
        if (pos->siguiente != NULL){
            pos = pos->siguiente;
        }
        else{
            return head;
        }
    }
    return pos;
}

link posA_link_num(link head, int num){
    //Esta funcion entrega el link anterior a el numero dado.
    link pos = head;
    while (pos->siguiente->numero != num){
        if (pos->siguiente != NULL){
            pos = pos->siguiente;
        }
        else{
            return head;
        }
    }
    return pos;
}

link crearLista(){
    //Esta funcion crea el link principal/cabezal (head).
    link head = malloc(sizeof(link));
    head->numero = NULL;
    head->siguiente = NULL;
    return head;
}

link crearNodo(int num){
    //Esta funcion crea un nodo con el numero entregado, y apuntando a nulo.
    link newNodo = malloc(sizeof *newNodo);
    newNodo->numero = num;
    newNodo->siguiente = NULL;
    return newNodo;
}

void insertarNodoInico(link head, link newNodo){
    //Esta funcion permite insertar un nodo al inicio del link principal (el primer 
    // nodo al que apunta).
    link temp;
    temp = head->siguiente;
    head->siguiente = newNodo;
    newNodo->siguiente = temp;
}

void insertarNodoFinal(link head, link newNodo){
    //Esta funcion permite insertar un nodo al final del ultimo link al que
    // apunta el recorrido del link principal(head).
    link pointer;
    pointer = last_link(head);
    pointer->siguiente = newNodo;
}

void insertarNodoPos(link head, link newNodo, int pos){
    //Esta funcion permite insertar un nodo en una posicion dada del recorrido 
    // del link principal.
    link pointer;
    link temp;
    pointer = pos_link(head, pos, 1);
    temp = pointer->siguiente;
    pointer->siguiente = newNodo;
    newNodo->siguiente = temp;
}

void insertarNodoNum(link head, link newNodo, int num){
    //Esta funcion permite insertar un nodo en la posicion de un numero dado
    // del recorrido del link principal.
    link pointer;
    link temp;
    pointer = posA_link_num(head, num);
    temp = pointer->siguiente;
    pointer->siguiente = newNodo;
    newNodo->siguiente = temp;
}

void recorrerLista(link head){
    //Esta funcion recorre la lista de nodos desde el link head dado, mostrando
    // por pantalla la posicion y el dato que este tiene.
    link nodoLista = head->siguiente;
    int i;
    for(i = 2; nodoLista != NULL; i++){
        printf("Posicion %i: %d\n", i - 1, nodoLista->numero);
        nodoLista = pos_link(head, i, 0);
    }
}

link primeroLista(link head){
    //Entrega el link del primer nodo perteneciente al link principal dado.
    return head->siguiente;
}

link ultimoLista(link head){
    //Entrega el link del ultimo nodo perteneciente al recorrido del link principal dado.
    link ultimo = last_link(head);
    return ultimo;
}

void eliminarNodoInicio(link head){
    //Esta funcion elimina el primer nodo perteneciente al link principal dado.
    link temp = head->siguiente->siguiente;
    free(head->siguiente);
    head->siguiente = temp;
}

void eliminarNodoFinal(link head){
    //Esta funcion elimina el ultimo nodo perteneciente al recorrido del link principal dado.
    link ultimo = last_link(head);
    link posA_ultimo = posA_link_num(head, ultimo->numero);
    posA_ultimo->siguiente = NULL;
    free(ultimo);
}

void eliminarNodoNum(link head, int num){
    //Esta funcion elimina el nodo que tiene el valor del numero dado 
    // perteneciente al recorrido del link principal dado.
    link posA_num = posA_link_num(head, num);
    link temp = posA_num->siguiente->siguiente;
    free(posA_num->siguiente);
    posA_num->siguiente = temp;
}

void eliminarNodoPos(link head, int pos){
    //Esta funcion elimina el nodo que se encuentra en la posicion dada,
    // perteneciente al recorrido del link principal dado.
    link posA_num = pos_link(head, pos, 1);
    link temp = posA_num->siguiente->siguiente;
    free(posA_num->siguiente);
    posA_num->siguiente = temp;
}

void actualizarNodo(link head, int oldNum, int newNum){
    //Esta funcion actualiza un numero perteneciente al recorrido del link principal.
    link nodo = link_num(head, oldNum);
    nodo->numero = newNum;
}

int largoLista(link head){
    //Esta funcion entrega el largo del recorrido del link principal dado.
    link nodoLista = head->siguiente;
    int i;
    for(i = 0; nodoLista != NULL; i++){
        nodoLista = nodoLista->siguiente;
    }
    return i;
}

char isVaciaLista(link head){
    //Esta funcion verifica si el recorrido del link principal dado es 
    // de 0 (vacio) o no.
    if(head->siguiente == NULL){
        return 'V';
    }
    else{
        return 'F';
    }
}

link liberarLista(link actual){
    //Esta funcion libera todos los nodos de forma recursiva, con
    // caso base cuando se llega al ultimo de la lista (Null), en donde
    // va a empezar a liberar todos los nodos desde el ultimo hasta el primero 
    // ingresado.
    if(actual->siguiente != NULL){
        liberarLista(actual->siguiente);
    }
    free(actual);
}

void anularLista(link head){
    //Esta funcion libera la memorida del link principal dado, dejando
    // esta vacia/nula.
    liberarLista(head->siguiente);
    head->siguiente = NULL;
}
