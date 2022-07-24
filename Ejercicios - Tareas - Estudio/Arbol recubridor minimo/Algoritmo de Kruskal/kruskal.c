#include <stdio.h>
#include <stdlib.h>
// #include "grafo_lista_ady.c"
#include "nodos.c"

int recorriendoCiclo(Grafo grafo, int vert, int dest){
    enlace adyacentes, nodoMarcar;
    int ciclo;
    if(vert != dest){
        for(adyacentes = grafo->adj[vert]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            if(adyacentes->marca == -1){
                nodoMarcar = buscar_nodo(grafo->adj[adyacentes->vertice], vert);
                nodoMarcar->marca = -2;
                adyacentes->marca = -2;
                return recorriendoCiclo(grafo, adyacentes->vertice, dest);
                // if(ciclo == 1){
                //     return 1;
                // }
                nodoMarcar->marca = -1;
                adyacentes->marca = -1;
            }
        }
        return 0;
    }
    else{
        return 1;
    }
}

int produceCiclo(Grafo grafo, arista aris){
    int ver;
    ver = recorriendoCiclo(grafo, aris.w, aris.v);
    return ver;
}

int algoritmoKruskal(Grafo grafo){
    
    arista newArista;
    link listaAristas = crearLista();
    link actual, nodoP;
    enlace adyacentes, nodoMarcar;
    int contVertices = 0;

    while (contVertices < grafo->numV){
        for(adyacentes = grafo->adj[contVertices]; adyacentes != NULL; adyacentes = adyacentes->siguiente){
            //Si el vertice no fue visitado entonces se agregan las aristas con costos ordenados de menor a mayor(para no generar un costo de más) //Volver a agregar
            if(adyacentes->marca == 0 && grafo->adj[adyacentes->vertice]->marca == 0){
                for (actual = listaAristas; actual->siguiente != NULL && adyacentes->costo > actual->siguiente->aris.costo; actual = actual->siguiente){
                }
                newArista = crear_arista(contVertices, adyacentes->vertice, adyacentes->costo);
                nodoP = crearNodo(contVertices, newArista);
                nodoP->siguiente = actual->siguiente;
                actual->siguiente = nodoP;
                adyacentes->marca = 1;
                nodoMarcar = buscar_nodo(grafo->adj[adyacentes->vertice], contVertices);
                nodoMarcar->marca = 1;
            }
        }
        contVertices++;
    }

    
    int contAristas = 0, contCostos = 0;
    arista solucion[grafo->numV - 1];
    int verticeW, verticeV, r;
    while(contAristas < grafo->numV - 1){
        //Buscar forma de verificar que no se forme un ciclo
        for(actual = listaAristas; r = produceCiclo(grafo, actual->siguiente->aris) == 1; eliminarNodoInicio(listaAristas)){
            //Eliminamos solo al inicio los vertices que ya fueron visitados (para no generar un costo de más)
        }
        solucion[contAristas] = listaAristas->siguiente->aris;
        verticeV = listaAristas->siguiente->aris.v;
        verticeW = listaAristas->siguiente->aris.w;
        nodoMarcar = buscar_nodo(grafo->adj[verticeV], verticeW);
        nodoMarcar->marca = -1;
        nodoMarcar = buscar_nodo(grafo->adj[verticeW], verticeV);
        nodoMarcar->marca = -1;
        printf("Arista: (%d, %d) con costo: %d\n", solucion[contAristas].v, solucion[contAristas].w, solucion[contAristas].costo);
        eliminarNodoInicio(listaAristas);
        contCostos += solucion[contAristas].costo;
        contAristas++;
    }
    liberarLista(listaAristas);
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
    costos = algoritmoKruskal(newGrafo);
    printf("Costos totales: %d", costos);

    return 0;
}