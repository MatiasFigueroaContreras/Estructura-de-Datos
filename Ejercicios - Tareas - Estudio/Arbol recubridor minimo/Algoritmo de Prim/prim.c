#include <stdio.h>
#include <stdlib.h>
// #include "grafo_lista_ady.c"
#include "nodos.c"


int algoritmoPrim(Grafo grafo){
    int *verticeMarca = malloc(sizeof(int) * grafo->numV);
    int i;
    for(i = 0; i < grafo->numV; i++){
        verticeMarca[i] = 0;
    }
    arista solucion[grafo->numV - 1];
    arista newArista;
    link posiblesAristas = crearLista();
    link actual, nodoP;
    enlace adyacentes;
    int contAristas = 0, verticeA = 0, contCostos = 0;
    verticeMarca[verticeA] = 1;
    while (contAristas < grafo->numV - 1){
        for(adyacentes = grafo->adj[verticeA]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            if(verticeMarca[adyacentes->vertice] == 0){
                //Si el vertice no fue visitado entonces se agregan las aristas con costos ordenados de menor a mayor(para no generar un costo de más)
                for (actual = posiblesAristas; actual->siguiente != NULL && adyacentes->costo > actual->siguiente->aris.costo; actual = actual->siguiente){
                }
                newArista = crear_arista(verticeA, adyacentes->vertice, adyacentes->costo);
                nodoP = crearNodo(verticeA, newArista);
                nodoP->siguiente = actual->siguiente;
                actual->siguiente = nodoP;
            }
        }
        for(actual = posiblesAristas; verticeMarca[actual->siguiente->aris.w] == 1; eliminarNodoInicio(posiblesAristas)){
            //Eliminamos solo al inicio los vertices que ya fueron visitados (para no generar un costo de más)
        }
        verticeA = posiblesAristas->siguiente->aris.w;
        verticeMarca[verticeA] = 1;
        solucion[contAristas] = posiblesAristas->siguiente->aris;
        printf("Arista: (%d, %d) con costo: %d\n", solucion[contAristas].v, solucion[contAristas].w, solucion[contAristas].costo);
        eliminarNodoInicio(posiblesAristas);
        contCostos += solucion[contAristas].costo;
        contAristas++;
    }
    free(verticeMarca);
    liberarLista(posiblesAristas);
    return contCostos;
}

int main(){
    Grafo newGrafo = iniciar_grafo(9);
    arista newArista;
    //Aristas de 0
    newArista = crear_arista(0, 1, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 3, 7);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 7, 12);
    insertar_arista(newGrafo, newArista);

    //Aristas de 1
    newArista = crear_arista(1, 3, 6);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 2, 4);
    insertar_arista(newGrafo, newArista);

    //Aristas de 2
    newArista = crear_arista(2, 4, 9);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 3, 8);
    insertar_arista(newGrafo, newArista);

    //Aristas de 3
    newArista = crear_arista(3, 6, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(3, 5, 3);
    insertar_arista(newGrafo, newArista);

    //Aristas de 4
    newArista = crear_arista(4, 6, 7);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(4, 8, 10);
    insertar_arista(newGrafo, newArista);

    //Aristas de 5
    newArista = crear_arista(5, 7, 5);
    insertar_arista(newGrafo, newArista);

    //Aristas de 6
    newArista = crear_arista(6, 7, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(6, 8, 6);
    insertar_arista(newGrafo, newArista);
    
    //Aristas de 7
    newArista = crear_arista(7, 8, 11);
    insertar_arista(newGrafo, newArista);

    //Aristas de 8


    int costos;
    costos = algoritmoPrim(newGrafo);
    printf("Costos totales: %d", costos);

    return 0;
}