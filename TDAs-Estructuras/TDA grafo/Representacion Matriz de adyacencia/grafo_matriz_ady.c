#include <stdio.h>
#include <stdlib.h>
#include "grafo_matriz_ady.h"

arista crear_arista(int v, int w){
    //Crea una arista con los valores entregados en la entrada.
    arista newArista;
    newArista.v = v;
    newArista.w = w;
    return newArista;
}

int **inicia_matriz(int filas, int columnas, int valor){
    //Esta funcion crea una matriz con de filas * columnas (dados en la entrada)
    // y poniendo el valor de entrada en toda la matriz, luego retorna esta matriz.
    int i, j;
    int **matriz = (malloc(sizeof(int *) * filas));
    for(i = 0; i < filas; i++){
        matriz[i] = (malloc(sizeof(int) * columnas));
    }
    for(i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            matriz[i][j] = valor;
        }
    }
    return matriz;
}

void modificar_bucles(Grafo grafo, int valor){
    //Esta funcion modifica el valor de los bucles de un grafo, es decir
    // las posiciones en donde se cumple que la fila = vertice y columna = vertice.
    int i;
    for(i = 0; i < grafo->numV; i++){
        grafo->adj[i][i] = valor;
    }
}

int tiene_bucles(Grafo grafo){
    //Esta funcion verifica si un grafo presenta bucles o no, revisando las
    // posiciones en donde se cumple que la fila = vertice y columna = vertice.
    int i;
    for(i = 0; i < grafo->numV; i++){
        if(grafo->adj[i][i] == 1){
            return 1;
        }
    }
    return 0;
}

Grafo iniciar_grafo(int cant_vertices){
    //Esta funcion crea un grafo con una cantidad de vertices dados
    // y sin aristas.
    Grafo newGrafo = malloc(sizeof * newGrafo);
    newGrafo->numV = cant_vertices;
    newGrafo->numA = 0;
    newGrafo->adj = inicia_matriz(cant_vertices, cant_vertices, 0);
    return newGrafo;
}

Grafo iniciar_grafo_completo(int cant_vertices, int valor){
    //Esta funcion crea un grafo con una cantidad de vertices dados
    // y con todos sus vertices conectados(excepto entre ellos(bucles)).
    Grafo newGrafo = malloc(sizeof * newGrafo);
    newGrafo->numV = cant_vertices;
    newGrafo->numA = (cant_vertices * cant_vertices - cant_vertices)/2;
    newGrafo->adj = inicia_matriz(cant_vertices, cant_vertices, 1);
    modificar_bucles(newGrafo, valor);

    return newGrafo;
}

void insertar_arista(Grafo grafo, arista arist){
    //Esta funcion inserta una arista asignado el valor 1 a las
    // posiciones de la matriz del grafo que representan 
    // a los vertices contenidos en la arista dada en la entrada, 
    // y guarda la nueva cantidad en el grafo.
    if (grafo->adj[arist.v][arist.w] == 0){
        grafo->numA++;
    }
    grafo->adj[arist.v][arist.w] = 1;
    grafo->adj[arist.w][arist.v] = 1;
}

void remover_arista(Grafo grafo, arista arist){
    //Esta funcion remuve una arista asignado el valor 0 a las
    // posiciones de la matriz del grafo que representan 
    // a los vertices contenidos en la arista dada en la entrada, 
    // y guarda la nueva cantidad en el grafo.
    if (grafo->adj[arist.v][arist.w] == 1){
        grafo->numA--;
    }
    grafo->adj[arist.v][arist.w] = 0;
    grafo->adj[arist.w][arist.v] = 0;
}

int pertenece_arista(Grafo grafo, arista arist){
    // Esta funcion vertifica si una arista pertenece al grafo
    if (grafo->adj[arist.v][arist.w] == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int obtener_aristas(Grafo grafo, arista aristas[]){
    //Esta funcion ingresa todas las aristas de un grafo a un
    // arreglo de aristas dado, y retorna el largo de este arreglo
    int v, w, z = 0;
    for(v = 0; v < grafo->numV; v++){
        for(w = v + 1; w < grafo->numV; w++){
            if(grafo->adj[v][w] == 1){
                aristas[z++] = crear_arista(v, w);
            }
        }
    }
    return z;
}

int obtener_grado(Grafo grafo, int vertice){
    //Esta funcion entrega el grado de un vertice perteneciente a un grafo dado.
    int v_ady, grado = 0;
    for(v_ady = 0; v_ady < grafo->numV; v_ady++){
        grado += grafo->adj[vertice][v_ady];
    }
    return grado;
}

void grado_vertices(Grafo grafo, int grados[]){
    //Esta funcion guarda el grado de todos los vertices de un grafo, en
    // un arreglo de enteros dado en la entrada.
    int i;
    for(i = 0; i < grafo->numV; i++){
        grados[i] = obtener_grado(grafo, i);
    }
}

int grado_maximo(Grafo grafo){
    //Esta funcion entrega el grado maximo de un grafo.
    int i;
    int max = obtener_grado(grafo, 0);
    int comp;
    for(i = 1; i < grafo->numV; i++){
        comp = obtener_grado(grafo, i);
        if(max < comp){
            max = comp;
        }
    }
    return max;
}

int grado_minimo(Grafo grafo){
    //Esta funcion entrega el grado minimo de un grafo.
    int i;
    int min = obtener_grado(grafo, 0);
    int comp;
    for(i = 1; i < grafo->numV; i++){
        comp = obtener_grado(grafo, i);
        if(min > comp){
            min = comp;
        }
    }
    return min;
}

int obtener_adyacentes(Grafo grafo, int ady[], int v){
    //Esta funcion guarda todos los vertices adyacente de uno dado, en
    // un arreglo de enteros, y ademas entrega el largo de este arreglo.
    int v_ady, j = 0;
    for (v_ady = 0; v_ady < grafo->numV; v_ady++){
        if(grafo->adj[v][v_ady] == 1){
            ady[j++] = v_ady;
        }
    }
    return j;
}

int es_regular(Grafo grafo){
    //Esta funcion verifica si un grafo es regular, retornando
    // su grado si este es regular, y sino lo es retorna -1.
    int v;
    int gradoC = obtener_grado(grafo, 0);
    for (v = 1; v < grafo->numV; v++){
        if(gradoC != obtener_grado(grafo, v)){
            return -1;
        }
    }
    return gradoC;
}

Grafo grafo_complemento(Grafo grafo){
    //Esta funcion crea un grafo complemento, para esto se crea
    // un grafo completo con la cantidad de vertices del grafo entregado
    // y se le eliminan las aristas que el grafo entregado contiene
    // generando asi el grafo complemento y retornando este.
    int v, w, z = 0;
    Grafo grafo_final = iniciar_grafo_completo(grafo->numV, 0);
    for(v = 0; v < grafo->numV; v++){
        for(w = v + 1; w < grafo->numV; w++){
            if(grafo->adj[v][w] == 1){
                remover_arista(grafo_final, crear_arista(v, w));
            }
        }
    }
    return grafo_final;
}

int es_grafo_simple(Grafo grafo){
    //Esta funcion verifica si un grafo es simple, retornando 1 si lo es,
    // y por el contrario 0.
    int max_aristas = (grafo->numV*(grafo->numV - 1))/2; //Propiedad de un grafo simple del maximo de arista en funciond esus vertices
    if (max_aristas >= grafo->numA){
        if(tiene_bucles(grafo) == 0){
            return 1;
        }
    }
    return 0;
}

int es_clique(Grafo grafo, int vertices[], int cant_vertices){
    //Esta funcion verifica si un conjunto de vertices pertenecientes 
    // al grafo(se asume), es un clique, retorando 1 si este lo es,
    // y un 0 sino. 
    int i, j, vert, vert_ady;
    for(i = 0; i < cant_vertices; i++){
        vert = vertices[i];
        for(j = i + 1; j < cant_vertices; j++){
            vert_ady = vertices[j];
            if(grafo->adj[vert][vert_ady] == 0){
                return 0;
            }
        }
    }
    return 1;
}

int es_tour(Grafo grafo, int vertices[], int cant_vertices){
    //Esta funcion verifica si un camino de vertices dado por un arreglo de
    // vertices es tour o no, retorando 1 si este lo es, y un 0 sino
    // (se asume que los vertices entregados vienen ordenados con su
    // recorrido, y ademas son todos los pertenecientes al grafo).
    int i, vert, vert_ady;
    for(i = 0; i < cant_vertices - 1; i++){
        vert = vertices[i];
        vert_ady = vertices[i + 1];
        if(grafo->adj[vert][vert_ady] == 0){
            return 0;
        }
    }
    if(grafo->adj[vert_ady][vertices[0]] == 0){
        return 0;
    }
    return 1;
}

int es_conjunto_independiente(Grafo grafo, int vertices[], int cant_vertices){
    //Esta funcion verifica si un conjunto de vertices es independiente o no,
    // verificando si alguno de estos vertices esta conectado o no, en donde
    // retornara 0 si se presenta alguna conexion(arista) entre estos, y si
    // ninguno se encuentra conectado entonces retornara 1.
    int i, j, vert, vert_ady;
    for(i = 0; i < cant_vertices; i++){
        vert = vertices[i];
        for(j = i + 1; j < cant_vertices; j++){
            vert_ady = vertices[j];
            if(grafo->adj[vert][vert_ady] == 1){
                return 0;
            }
        }
    }
    return 1;
}

int es_cobertura_aristas(Grafo grafo, arista aristas[], int cant_aristas){
    //Esta funcion verifica si un conjunto de arista es cobertura, en donde
    // comprueba que todos los vertices esten en este conjunto, retornando 1
    // si se cumple que estan todos, y 0 sino (se supone que las aristas
    // entregadas son pertenecientes al grafo).
    int i, j, ver_v, ver_w, z = 0;
    int vertices[grafo->numV];
    for(i = 0; i < cant_aristas; i++){
        ver_v = 1;
        for (j = 0; j < z; j++){
            if(aristas[i].v == vertices[j]){
                ver_v = 0;
            }
        }
        ver_w = 1;
        for (j = 0; j < z; j++){
            if(aristas[i].w == vertices[j]){
                ver_w = 0;
            }
        }
        
        if (ver_v == 1){
            vertices[z++] = aristas[i].v;
        }
        if (ver_w == 1){
            vertices[z++] = aristas[i].w;
        }
    }
    if(z == grafo->numV){
        return 1;
    }
    return 0;
}


void imprimir_conjunto_aristas(Grafo grafo){
    //Esta funcion obtiene todas las aristas de un grafo
    // y las imprime
    int i;
    arista aristas[grafo->numA];
    int largo = obtener_aristas(grafo, &aristas);
    printf("Conjunto de Aristas del grafo:\n");
    for(i = 0; i < largo; i++){
        printf("arista n%i: (%d, %d)\n", i+1, aristas[i].v, aristas[i].w);
    }
}