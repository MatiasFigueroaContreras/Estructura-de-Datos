#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista_ady.c"
#include "nodos.c"

int minimo(int a, int b){
    if(a == -1){
        return b;
    }
    if(b == -1){
        return a;
    }
    
    if(a >= b){
        return b;
    }
    else{
        return a;
    }
}

int **algoritmo_dijkstra(Grafo grafo, int origen){
    link vertices = crearLista();
    link newNodo;
    int **costos_solucion = malloc(sizeof(int *) * grafo->numV);
    int i;
    for(i = 0; i < grafo->numV; i++){
        costos_solucion[i] = malloc(sizeof(int) * 2);
        costos_solucion[i][0] = -1; //-1 Representa infinito
        costos_solucion[i][1] = -1; //-1 Representa el indefinido
        newNodo = crearNodo(grafo->numV - i - 1);
        insertarNodoInico(vertices, newNodo);
    }
    eliminarNodoNum(vertices, origen);

    costos_solucion[origen][0] = 0;
    costos_solucion[origen][1] = 0;

    enlace adyacentes;
    for(adyacentes = grafo->adj[origen]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
        costos_solucion[adyacentes->vertice][0] = adyacentes->costo;
        costos_solucion[adyacentes->vertice][1] = origen; 
    }
    link Vertice;
    int vert, min;
    int valor;
    while(isVaciaLista(vertices) != 1){
        min = -1;
        vert = -1;
        for(Vertice = vertices->siguiente; Vertice != NULL; Vertice = Vertice->siguiente){
            valor = costos_solucion[Vertice->numero][0];
            min = minimo(min, valor);
            if(min == costos_solucion[Vertice->numero][0]){
                vert = Vertice->numero;
            }
        }
        
        eliminarNodoNum(vertices, vert);
        for(adyacentes = grafo->adj[vert]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            costos_solucion[adyacentes->vertice][0] = minimo(costos_solucion[adyacentes->vertice][0], costos_solucion[vert][0] + adyacentes->costo);
            if(costos_solucion[adyacentes->vertice][0] == costos_solucion[vert][0] + adyacentes->costo){
                costos_solucion[adyacentes->vertice][1] = vert;
            }
        }
    }

    return costos_solucion;
}



int main(){
    Grafo newGrafo = iniciar_grafo(7);
    arista newArista;

    //Para 0 "O"
    newArista = crear_arista(0, 1, 2);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 2, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 3, 4);
    insertar_arista(newGrafo, newArista);

    //Para 1 "A"
    newArista = crear_arista(1, 2, 2);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 4, 7);
    insertar_arista(newGrafo, newArista);

    //Para 2 "B"
    newArista = crear_arista(2, 4, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 3, 1);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 5, 3);
    insertar_arista(newGrafo, newArista);

    //Para 3 "C"
    newArista = crear_arista(3, 5, 4);
    insertar_arista(newGrafo, newArista);

    //Para 4 "D"
    newArista = crear_arista(4, 6, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(4, 5, 1);
    insertar_arista(newGrafo, newArista);

    //Para 5 "E"
    newArista = crear_arista(5, 6, 7);
    insertar_arista(newGrafo, newArista);

    //Para 6 "T"


    int **soluciones = malloc(sizeof(int *) * newGrafo->numV);
    int i;
    for(i = 0; i < newGrafo->numV; i++){
        soluciones[i] = malloc(sizeof(int) * 2);
    }

    int numero_vertices = newGrafo->numV;
    printf("Numero vertices: %d\n", numero_vertices);
    

    soluciones = algoritmo_dijkstra(newGrafo, 0);

    for(i = 0; i < newGrafo->numV; i++){
        printf("Para: %i Antecesor: %d, Costo: %d\n", i, soluciones[i][1], soluciones[i][0]);
    }

    return 0;
}