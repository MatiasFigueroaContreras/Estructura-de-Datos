#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"

link last_link(link head){
    //Esta funcion entrega la direccion(link) de la ultima estructura(diccionario) encontrada
    // para esto es necesario pasarle el diccionario que fue creado(head)
    link last = head;
    while(last->siguiente != NULL){
        last = last->siguiente;
    }
    return last;
}

link link_palabra(link head, char palabra[]){
    //Esta funcion entrega la direccion(link) de la estructura(diccionario) en la que se encuentra
    // la palabra entregada, para esto es necesario pasarle el diccionario que fue creado(head).
    link pos = head->siguiente;
    if(pos == NULL){
        return NULL;
    }
    while (strcmp(pos->palabra, palabra) != 0){
        pos = pos->siguiente;
        if (pos == NULL){
            return NULL;
        }
    }
    return pos;
}

link post_link_palabra(link head, char palabra[]){
    //Esta funcion entrega la direccion(link) de la estructura(diccionario) anterior a una palabra
    // entregada, para esto es necesario pasarle el diccionario que fue creado(head).
    link pos = head;
    if (pos->siguiente == NULL){
        return NULL;
    }
    while (strcmp(pos->siguiente->palabra, palabra) != 0){
        pos = pos->siguiente;
        if (pos->siguiente == NULL){
            return NULL;
        }
    }
    return pos;
}

link crearDiccionario(){
    //Esta funcion permite crear un nuevo diccionario
    link head = malloc(sizeof * head);
    head->palabra = NULL;
    head->definicion = NULL;
    head->sinonimos = NULL;
    head->siguiente = NULL;
    return head;
}

void insertarPalabraDi(link head, char *palabra, char *definicion, char *sinonimos){
    //Esta funcion permite ingresar una palabra con su definicion y sinonimos, a un diccionario
    // creado anteriormente(head).
    link newDiccionario = malloc(sizeof *newDiccionario);
    link pointer;
    pointer = last_link(head);
    newDiccionario->palabra = palabra;
    newDiccionario->definicion = definicion;
    newDiccionario->sinonimos = sinonimos;
    newDiccionario->siguiente = NULL;
    pointer->siguiente = newDiccionario;
}

void eliminarPalabraDi(link head, char *palabra){
    //Esta funcion elimina una palabra con su respectiva definicion y sinonimo, para esto es
    // necesario entregar la palabra que se desea eliminar y el diccionario en el que se encuentra.
    link post_palabra = post_link_palabra(head, palabra);
    if (post_palabra != NULL){
        link temp = post_palabra->siguiente->siguiente;
        free(post_palabra->siguiente);
        post_palabra->siguiente = temp;
    }
}

void actualizarDef(link head, char *palabra, char *newdefinicion){
    //Esta funcion actualiza la definicion de una palabra, recibiendo como entrada el diccionario
    // en el que se encuentra, la palabra que se desea actualizar y la nueva definicion de esta.
    link pos_palabra = link_palabra(head, palabra);
    if (pos_palabra != NULL){
        free(pos_palabra->definicion);
        pos_palabra->definicion = newdefinicion;
    }
}

void actualizarSin(link head, char *palabra, char *sinonimos){
    //Esta funcion actualiza los sinonimos de una palabra, recibiendo como entrada el diccionario
    // en el que se encuentra, la palabra que se desea actualizar y los nuevos de esta.
    link pos_palabra = link_palabra(head, palabra);
    if (pos_palabra != NULL){
        free(pos_palabra->sinonimos);
        pos_palabra->sinonimos = sinonimos;
    }
}

char *buscarDef(link head, char *palabra){
    //Esta funcion busca y retorna la definicion de una palabra, en donde es necesario entregarle
    // la palabra de la que se desea la definicion y en el diccionario en que esta se encuentra.
    link pos_palabra = link_palabra(head, palabra);
    if(pos_palabra == NULL){
        return NULL;
    }
    return pos_palabra->definicion;
}

char *buscarSin(link head, char *palabra){
    //Esta funcion busca y retorna los sinonimos de una palabra, en donde es necesario entregarle
    // la palabra de la que se desean los sinonimos y en el diccionario en que esta se encuentra.
    link pos_palabra = link_palabra(head, palabra);
    if(pos_palabra == NULL){
        return NULL;
    }
    return pos_palabra->sinonimos;
}

void imprimirDiccionario(link head){
    //Esta funcion busca cada conjunto de una palabra y lo imprime en un formato establecido.
    link last = head;
    int i = 1;
    while(last->siguiente != NULL){
        last = last->siguiente;
        printf("{\nPalabra n%i\n  -Palabra: %s\n  -Definicion: %s\n  -Sinonimos: %s\n}\n", i, last->palabra, last->definicion, last->sinonimos);
        i++;
    }
}
