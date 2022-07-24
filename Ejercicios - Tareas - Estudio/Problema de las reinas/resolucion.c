#include <stdio.h>
#include <stdlib.h>
#include "grafo.c"

void restringirCeldas(Grafo newGrafo, int i, int j, int val){
    int z, x;
    // 1.1 diagonal |_
    z = i + 1;
    x = j + 1;
    while (z < newGrafo->largo && x < newGrafo->largo){
        newGrafo->vertices[z][x] = val;
        z++;
        x++;
    }
    // 1.2 Diagonal -|
    z = i - 1;
    x = j - 1;
    while (z >= 0 && x >= 0){
        newGrafo->vertices[z][x] = val;
        z--;
        x--;
    }
    // 2.1 Diagonal _|
    z = i + 1;
    x = j - 1;
    while (z < newGrafo->largo && x >= 0){
        newGrafo->vertices[z][x] = val;
        z++;
        x--;
    }
    // 2.2. Diagonal |-
    z = i - 1;
    x = j + 1;
    while (z >= 0 && x < newGrafo->largo){
        newGrafo->vertices[z][x] = val;
        z--;
        x++;
    }
    
    //Se restringen la columna y la fila
    // Fila
    for(x = j + 1; x < newGrafo->largo; x++){
        newGrafo->vertices[i][x] = val;
    }
    for(x = j - 1; x >= 0; x--){
        newGrafo->vertices[i][x] = val;
    }
    // Columna
    for(z = i + 1; z < newGrafo->largo; z++){
        newGrafo->vertices[z][j] = val;
    }
    for(z = i - 1; z >= 0; z--){
        newGrafo->vertices[z][j] = val;
    }    
}

void algoritmoRetroceso(Grafo newGrafo, int largoTablero){
    int i, j, tempJ, tempI;
    if(newGrafo->largo == 0){
        for (i = 1; i <= largoTablero; i++){
            insertarVertice(newGrafo);
        }
    }
    j = 0;
    i = 0;
    while (i < newGrafo->largo && i >= 0){
        while (j < newGrafo->largo && newGrafo->vertices[i][j] != 0){
            j++;
        }
        if(j == newGrafo->largo){
            i--;
            j = 0;
            if (i >= 0){
                while (j < newGrafo->largo && newGrafo->vertices[i][j] != 1){
                    j++;
                }
                restringirCeldas(newGrafo, i, j, 0);
                eliminarArista(newGrafo, i + 1, j + 1);
            }
            tempJ = j + 1;
            tempI = i - 1;

            for(i = i - 1; i >= 0; i--){
                j = 0;
                while (j < newGrafo->largo && newGrafo->vertices[i][j] != 1){
                    j++;
                }
                restringirCeldas(newGrafo, i, j, -1);
            }
            j = tempJ;
            i = tempI;
        }
        else{
            insertarArista(newGrafo, i + 1, j + 1);
            restringirCeldas(newGrafo, i, j, -1);
            j = 0;
        }
        i++;
    }
}



int main(){
    Grafo newGrafo = crearGrafo();
    int i;
    algoritmoRetroceso(newGrafo, 4);
    for (i = 1; i <= newGrafo->largo; i++){
        printf("\n");
        obtenerAristas(newGrafo, i);
    }
    printf("\n");
    // algoritmoRetroceso(newGrafo, 4);
    // for (i = 1; i <= newGrafo->largo; i++){
    //     printf("\n");
    //     obtenerAristas(newGrafo, i);
    // }
    return 0;
}