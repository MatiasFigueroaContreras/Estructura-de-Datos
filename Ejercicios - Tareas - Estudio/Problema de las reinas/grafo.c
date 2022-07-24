#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo crearGrafo(){
    Grafo newGrafo = malloc(sizeof * newGrafo);
    newGrafo->largo = 0;
    return newGrafo;
}

void insertarVertice(Grafo grafo){
    grafo->largo += 1;
    int i;
    for(i=0; i < grafo->largo; i++){
        grafo->vertices[grafo->largo][i] = 0;
        grafo->vertices[i][grafo->largo] = 0;
    }
}

void insertarArista(Grafo grafo, int vertN1, int vertN2){
    grafo->vertices[vertN1 - 1][vertN2 - 1] = 1;
}

void eliminarArista(Grafo grafo, int vert1, int vert2){
    grafo->vertices[vert1 - 1][vert2 - 1] = 0;
}

void obtenerAristas(Grafo grafo, int vert){
    int i;
    printf("Aristas de %d: ", vert);
    for(i = 0; i < grafo->largo; i++){
        if(grafo->vertices[vert - 1][i] == 1){
            printf("%d ", i + 1);
        }
    }
}

int consultarArista(Grafo grafo, int vert1, int vert2){
    if(grafo->vertices[vert1 - 1][vert2 - 1] != 1){
        return 0;
    }
    else{
        return 1;
    }
}
