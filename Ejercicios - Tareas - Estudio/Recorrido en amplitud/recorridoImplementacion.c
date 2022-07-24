#include <stdio.h>
#include <stdlib.h>
#include "cola.c"
#include "grafo_lista_ady.c"

void recorrido_amplitud(Grafo grafo){
    Cola colaS = crearCola();
    enlace adyacentes;
    int v;
    int raiz = 5;
    encolar(colaS, raiz);
    printf("encole: %d\n", raiz);
    grafo->adj[raiz]->marca = 1;
    while(isEmpty(colaS) != 1){
        v = elemTop(colaS);
        for(adyacentes = grafo->adj[v]->siguiente; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            if (grafo->adj[adyacentes->vertice]->marca != 1){
                printf("    marque tipo 1: %d, %d\n", v, adyacentes->vertice);
                adyacentes->marca = 1;
                grafo->adj[adyacentes->vertice]->marca = 1;
                adyacentes->tipo = 1;
                encolar(colaS, adyacentes->vertice);
                printf("encole: %d\n", adyacentes->vertice);
            }
            else{
                if (estaEnCola(colaS, adyacentes->vertice) == 1){
                    printf("    marque tipo 2: %d, %d\n", v, adyacentes->vertice);
                    adyacentes->tipo = 2;
                }
            }
        }
        desencolar(colaS);
        printf("desencole: %d\n", elemTop(colaS));
    }
}

int main(){
    // Cola newCola = crearCola();
    // int i; 
    // printf("primero: %d\n", isEmpty(newCola));
    // encolar(newCola, 1);
    // printf("segundo: %d\n", isEmpty(newCola));
    // desencolar(newCola);
    // printf("tercero: %d\n", isEmpty(newCola));
    // for(i = 1; i <= 3; i++){
    //     encolar(newCola, i);
    //     printf("%s", newCola->bot->siguiente);
    //     printf("Valor encolado: %d\n", elemBot(newCola));
    // }
    // int ver;
    // ver = estaEnCola(newCola, 2);
    // printf("%d\n", ver);

    // for(i = 1; i <= 3; i++){
    //     printf("Valor desencolado: %d\n", elemTop(newCola));
    //     desencolar(newCola);
    // }
    Grafo newGrafo = iniciar_grafo(12);
    arista newArista;
    // //Aristas de 0 "d"
    // newArista = crear_arista(0, 1);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(0, 2);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(0, 0);
    // insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 3);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 2);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(0, 1);
    insertar_arista(newGrafo, newArista);


    newArista = crear_arista(1, 5);
    insertar_arista(newGrafo, newArista);



    newArista = crear_arista(2, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(2, 5);
    insertar_arista(newGrafo, newArista);


    newArista = crear_arista(3, 4);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(3, 11);
    insertar_arista(newGrafo, newArista);

    newArista = crear_arista(4, 7);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(4, 11);
    insertar_arista(newGrafo, newArista);


    newArista = crear_arista(6, 7);
    insertar_arista(newGrafo, newArista);

    newArista = crear_arista(7, 10);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(7, 8);
    insertar_arista(newGrafo, newArista);
    newArista = crear_arista(7, 9);
    insertar_arista(newGrafo, newArista);

    newArista = crear_arista(8, 9);
    insertar_arista(newGrafo, newArista);

    newArista = crear_arista(9, 10);
    insertar_arista(newGrafo, newArista);

    newArista = crear_arista(10, 11);
    insertar_arista(newGrafo, newArista);
    // //Aristas de 2 "f"
    // newArista = crear_arista(2, 3);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(2, 4);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(2, 2);
    // insertar_arista(newGrafo, newArista);


    // //Aristas de 1 "c"
    // newArista = crear_arista(1, 4);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(1, 5);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(1, 6);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(1, 1);
    // insertar_arista(newGrafo, newArista);
    
    // //Aristas de 4 "e"
    // newArista = crear_arista(4, 3);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(4, 6);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(4, 4);
    // insertar_arista(newGrafo, newArista);

    // //Aristas de 3 "g"
    // newArista = crear_arista(3, 7);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(3, 3);
    // insertar_arista(newGrafo, newArista);

    // //Aristas de 6 "i"
    // newArista = crear_arista(6, 6);
    // insertar_arista(newGrafo, newArista);

    // //Aristas de 5 "b"
    // newArista = crear_arista(5, 8);
    // insertar_arista(newGrafo, newArista);
    // newArista = crear_arista(5, 5);
    // insertar_arista(newGrafo, newArista);

    // //Aristas de 7 "h"
    // newArista = crear_arista(7, 7);
    // insertar_arista(newGrafo, newArista);

    // //Aristas de 8 "a"
    // newArista = crear_arista(8, 8);
    // insertar_arista(newGrafo, newArista);

    recorrido_amplitud(newGrafo);
    
    return 0;
}