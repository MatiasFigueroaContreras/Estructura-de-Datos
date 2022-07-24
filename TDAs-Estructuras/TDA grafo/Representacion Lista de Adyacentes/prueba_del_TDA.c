#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista_ady.c"

int main(){
    //Inicializacion del grafo
    Grafo grafoP = iniciar_grafo(4);

    //Creacion de las aristas
    arista aris[5];
    aris[0] = crear_arista(0, 1);
    aris[1] = crear_arista(0, 2);
    aris[2] = crear_arista(0, 3);
    aris[3] = crear_arista(1, 2);
    aris[4] = crear_arista(3, 2);

    //Se incertan las aristas
    int i;
    for(i = 0; i <= 4; i++){
        insertar_arista(grafoP, aris[i]);
    }
    //Imprimimos para revisar, ademas en este se prueba el uso
    // de la operacion obtener_aristas()
    imprimir_conjunto_aristas(grafoP);

    printf("\n");

    //Removemos una arista
    remover_arista(grafoP, aris[4]);
    imprimir_conjunto_aristas(grafoP);

    //Pertenecia de arista
    printf("\n");
    int res;
    arista newArista = crear_arista(3, 2);
    res = pertenece_arista(grafoP, newArista);
    printf("Pertenece arista (%d, %d)?: %d\n", newArista.v, newArista.w, res);

    res = pertenece_arista(grafoP, aris[0]);
    printf("Pertenece arista (%d, %d)?: %d\n", aris[0].v, aris[0].w, res);

    //Obtencion de grados
    int grado[grafoP->numV];
    grado_vertices(grafoP, grado); //En esta funcion se ocupa la operacion obtener_grado
    for(i = 0; i < grafoP->numV; i++){
        printf("Grado de %i: %d\n", i, grado[i]);
    }
    int gradoMax = grado_maximo(grafoP);
    printf("El grado maximo es: %d\n", gradoMax);
    int gradoMin = grado_minimo(grafoP);
    printf("El grado minimo es: %d\n", gradoMin);

    //Vertices adyacentes
    int adyacentes[5];
    int largo = obtener_adyacentes(grafoP, &adyacentes, 0);
    printf("Adyacentes de 0: ");
    for(i = 0; i < largo; i++){
        printf("%d  ", adyacentes[i]);
    }

    printf("\n");
    //Es o no es para distintas terminologias de grafos
    // 0 y - 1 significan que no lo es, y  1 o mas que si lo es
    int conjunto_vertices1[3] = {0, 1, 2};
    int conjunto_vertices2[4] = {0, 3, 1, 2};

    //Es regular
    res = es_regular(grafoP);
    printf("Es regular el grafo?: %d\n", res);

    //Es grafo simple
    res = es_grafo_simple(grafoP);
    printf("Es un grafo simple?: %d\n", res);
    
    //Es clique
    res = es_clique(grafoP, conjunto_vertices1, 3);
    printf("El conjunto de vertice es clique?: %d\n", res);
    res = es_clique(grafoP, conjunto_vertices2, 4);
    printf("El conjunto de vertice es clique?: %d\n", res);

    //Es tour
    res = es_tour(grafoP, conjunto_vertices1, 3);
    printf("El conjunto de vertice es tour?: %d\n", res);
    res = es_tour(grafoP, conjunto_vertices2, 4);
    printf("El conjunto de vertice es tour?: %d\n", res);

    //Es conjunto independiente
    res = es_conjunto_independiente(grafoP, conjunto_vertices1, 3);
    printf("El conjunto de vertice es independiente?: %d\n", res);
    int conjunto_vertices3[2] = {0, 3};
    remover_arista(grafoP, aris[2]);
    res = es_conjunto_independiente(grafoP, conjunto_vertices3, 2);
    printf("El conjunto de vertice es independiente?: %d\n", res);
    insertar_arista(grafoP, aris[2]);

    //Es cobertura de aristas
    arista conjunto_aristas[2];
    conjunto_aristas[0] = crear_arista(0, 3);
    conjunto_aristas[1] = crear_arista(1, 2);
    res = es_cobertura_aristas(grafoP, conjunto_aristas, 2);
    printf("El conjunto de aristas es cobertura?: %d\n", res);
    conjunto_aristas[1] = crear_arista(0, 1);
    res = es_cobertura_aristas(grafoP, conjunto_aristas, 2);
    printf("El conjunto de aristas es cobertura?: %d\n", res);

    printf("\n");
    imprimir_conjunto_aristas(grafoP);
    printf("\n");
    Grafo grafoC = grafo_complemento(grafoP);
    imprimir_conjunto_aristas(grafoC);
    printf("%d", grafoC->adj[2]->siguiente->vertice);
    
    return 0;
}