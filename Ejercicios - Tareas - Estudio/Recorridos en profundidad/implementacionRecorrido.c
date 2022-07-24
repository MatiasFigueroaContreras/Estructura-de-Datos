#include <stdio.h>
#include <stdlib.h>
#include "pila.c"
#include "grafo_lista_ady.c"

int sonConsecutivos(Pila pilaS, int v, int w){
    Pila tempPila = crearPila();
    int ver, elem;
    ver = 0;
    while (isEmpty(pilaS) != 1){
        elem = elemTop(pilaS);
        if(elem == v || elem == w){
            push(tempPila, elem);
            pop(pilaS);
            elem = elemTop(pilaS);
            if((elem == v || elem == w) && isEmpty(pilaS) != 1){
                ver = 1;
                push(tempPila, elem);
                pop(pilaS);
            }
        }
        else{
            push(tempPila, elem);
            pop(pilaS);
        }
        
        
    }
    while (isEmpty(tempPila) != 1){
        elem = elemTop(tempPila);
        push(pilaS, elem);
        pop(tempPila);
    }

    return ver;
}

void procedimiento_recorrido(Grafo grafo, Pila pilaS, int v){
    //Reviasar lo que hace la ->marca, si es que esta mal probar con un arreglo de enteros con valor incial 0
    enlace adyacentes;
    grafo->adj[v]->marca = 1;
    push(pilaS, v);
    // printf("Elemento pusheado: %d\n", v);
    for(adyacentes = grafo->adj[v]->siguiente; adyacentes != NULL; adyacentes = adyacentes->siguiente){
        // printf("Dentro for\n");
        // printf("    Arista siendo vista: %d, %d\n", v, adyacentes->vertice);
        if (grafo->adj[adyacentes->vertice]->marca != 1){
                printf("    marque tipo 1: %d, %d\n", v, adyacentes->vertice);
                adyacentes->tipo = 1;
                adyacentes->marca = 1;
                procedimiento_recorrido(grafo, pilaS, adyacentes->vertice);
            }
        else{
            if (estaEnPila(pilaS, adyacentes->vertice) == 1 && sonConsecutivos(pilaS, v, adyacentes->vertice) == 0){
                printf("    marque tipo 2: %d, %d\n", v, adyacentes->vertice);
                adyacentes->tipo = 2;
            }
        }
    }
    // printf("elemento popeado: %d\n", elemTop(pilaS));
    pop(pilaS);
    // printf("Sali for\n");
}

void recorrido_profundidad(Grafo grafo){
    Pila pilaS = crearPila();
    int raiz = 0;
    procedimiento_recorrido(grafo, pilaS, raiz);
}


int main(){
    Pila newPila = crearPila();
    // printf("primero: %d\n", isEmpty(newPila));
    // push(newPila, 1);
    // printf("segundo: %d\n", isEmpty(newPila));
    // pop(newPila);
    // printf("tercero: %d\n", isEmpty(newPila));
    // int i, ver;
    // for(i = 1; i <= 3; i++){
    //     push(newPila, i);
    //     printf("Valor pusheado: %d\n", elemTop(newPila));
    // }
    // ver = estaEnPila(newPila, 1);
    // printf("esta en pila?: %d\n", ver);
    // ver = sonConsecutivos(newPila, 2, 3);
    // printf("son consecutivos?: %d\n", ver);
    // for(i = 1; i <= 3; i++){
    //     printf("Valor popeado: %d\n", elemTop(newPila));
    //     pop(newPila);
    // }
    // push(newPila, 0);
    // push(newPila, 2);
    // push(newPila, 4);
    // push(newPila, 6);
    // push(newPila, 1);
    // int ver = estaEnPila(newPila, 0);
    // printf("esta en pila?: %d\n", ver);
    // ver = sonConsecutivos(newPila, 1, 0);
    // printf("son consecutivos?: %d\n", ver);

    Grafo newGrafo = iniciar_grafo(9);
    arista newArista;

    //Aristas de 0 "d"
    newArista = crear_arista(0, 1);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 2);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 0);
    insertar_arista(newGrafo, newArista);

    //Aristas de 2 "f"
    newArista = crear_arista(2, 3);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 2);
    insertar_arista(newGrafo, newArista);


    //Aristas de 1 "c"
    newArista = crear_arista(1, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 5);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 6);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(1, 1);
    insertar_arista(newGrafo, newArista);
    
    //Aristas de 4 "e"
    newArista = crear_arista(4, 3);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(4, 6);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(4, 4);
    insertar_arista(newGrafo, newArista);

    //Aristas de 3 "g"
    newArista = crear_arista(3, 7);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(3, 3);
    insertar_arista(newGrafo, newArista);

    //Aristas de 6 "i"
    newArista = crear_arista(6, 6);
    insertar_arista(newGrafo, newArista);

    //Aristas de 5 "b"
    newArista = crear_arista(5, 8);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(5, 5);
    insertar_arista(newGrafo, newArista);

    //Aristas de 7 "h"
    newArista = crear_arista(7, 7);
    insertar_arista(newGrafo, newArista);

    //Aristas de 8 "a"
    newArista = crear_arista(8, 8);
    insertar_arista(newGrafo, newArista);

    recorrido_profundidad(newGrafo);
    printf("sali");

    return 0;
}