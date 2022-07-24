#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista_ady.c"

int minArist(enlace aristas[], int largoA){
    if(largoA >= 0){
        int min, i;
        min = aristas[0]->flujo;
        for(i = 1; i < largoA; i++){
            if(min > aristas[i]->flujo){
                min = aristas[i]->flujo;
            }
        }
        return min;
    }
    else{
        return 0;
    }
}

int recorridoFF(Grafo grafo, int orig, int dest, enlace aristas[], int largoA){
    enlace adyacentes;
    if(orig != dest){
        int flujoMax = 0;
        for(adyacentes = grafo->adj[orig]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            if(adyacentes->flujo != 0){
                //Se puede mejorar ya que hace recorridos de mas cuando en el arreglo de aristas hay un flujo 0
                aristas[largoA] = adyacentes;
                flujoMax += recorridoFF(grafo, adyacentes->vertice, dest, aristas, largoA + 1);
            }
        }
        return flujoMax;
    }
    else{
        int min, i;
        min = minArist(aristas, largoA);
        for(i = 0; i < largoA; i++){
            aristas[i]->flujo -= min;
        }
        return min;
    }
}

int fordFulkerson(Grafo grafo, int orig, int dest){
    enlace *aristas = malloc(sizeof(enlace) * grafo->numA);
    int flujoMax;
    flujoMax = recorridoFF(grafo, orig, dest, aristas, 0);
    free(aristas);
    return flujoMax;
}



int main(){
    Grafo newGrafo;
    newGrafo = iniciar_grafo(7);
    arista newArista;
    //Aristas de 0 "o" es el origen
    newArista = crear_arista(0, 1, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 2, 7);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 3, 4);
    insertar_arista(newGrafo, newArista);

    //Aristas de 1 "A"
    newArista = crear_arista(1, 4, 3);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 2, 1);
    insertar_arista(newGrafo, newArista);

    //Aristas de 2 "B"
    newArista = crear_arista(2, 4, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 5, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 3, 2);
    insertar_arista(newGrafo, newArista);

    //Aristas de 3 "C"
    newArista = crear_arista(3, 5, 4);
    insertar_arista(newGrafo, newArista);

    //Aristas de 4 "D"
    newArista = crear_arista(4, 6, 9);
    insertar_arista(newGrafo, newArista);

    //Aristas de 5 "E"
    newArista = crear_arista(5, 4, 1);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(5, 6, 6);
    insertar_arista(newGrafo, newArista);

    //Aristas de 6 "T" es el destino

    int flujoMax;
    flujoMax = fordFulkerson(newGrafo, 0, 6);
    printf("Flujo Maximo: %d", flujoMax);

    return 0;
}
