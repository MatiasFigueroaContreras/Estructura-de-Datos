#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista_ady.h"

arista crear_arista(int v, int w, int costo){
    //Crea una arista con los valores entregados en la entrada.
    arista newArista;
    newArista.v = v;
    newArista.w = w;
    newArista.costo = costo;
    return newArista;
}

enlace crear_nodo(int valor, enlace sig, int costo){
    //Esta funcion crea un nodo con un valor de vertice dado en la entrada
    // y siendo el siguiente valor el enlace entregado.
    enlace newNodo = malloc(sizeof * newNodo);
    newNodo->vertice = valor;
    newNodo->siguiente = sig;
    newNodo->marca = 0;
    newNodo->costo = costo;
    return newNodo;
}

enlace buscar_nodo(enlace head, int valor){
    //Esta funcion busca un nodo por su valor entregando su direccion
    // en caso de que la lista este vacia o no se encuentre el nodo
    // entonces devolvera nulo
    enlace pos = head;
    while (pos != NULL && pos->vertice != valor){
        pos = pos->siguiente;
    }
    return pos;
}

enlace buscar_nodo_anterior(enlace head, int valor){
    //Esta funcion busca la direccion anterior a un nodo por su valor
    // en caso de que la lista este vacia o no se encuentre el nodo
    // entonces devolvera nulo, y si el valor esta en el inicio entonces
    // se devolvera esta direccion.
    enlace pos = head;
    if(pos == NULL){
        return NULL;
    }
    if(pos->vertice == valor){
        return head;
    }
    else{
        while (pos->siguiente != NULL && pos->siguiente->vertice != valor){
            pos = pos->siguiente;
        }
        if(pos->siguiente == NULL){
            return NULL;
        }
        return pos;
    }
}

Grafo iniciar_grafo(int numV){
    //Esta funcion crea un grafo con una cantidad de vertices dados
    // y sin aristas.
    int i;
    Grafo newGrafo = malloc(sizeof * newGrafo);
    newGrafo->numV = numV;
    newGrafo->numA = 0;
    newGrafo->adj = malloc(sizeof(enlace) * numV);
    for(i = 0; i < numV; i++){
        newGrafo->adj[i] = NULL;
    }
    return newGrafo;
}

Grafo inicia_grafo_completo(int numV){
    //Esta funcion crea un grafo con una cantidad de vertices dados
    // y con todos sus vertices conectados(excepto entre ellos(bucles)).
    int i, j;
    Grafo newGrafo = malloc(sizeof * newGrafo);
    newGrafo->numV = numV;
    newGrafo->numA = (numV * numV - numV)/2;
    newGrafo->adj = malloc(sizeof(enlace) * numV);
    for(i = 0; i < numV; i++){
        newGrafo->adj[i] = NULL;
        for(j = 0; j < numV; j++){
            if(j != i){
                newGrafo->adj[i] = crear_nodo(j, newGrafo->adj[i], -1);
            }
        }
    }
    return newGrafo;
}

void insertar_arista(Grafo grafo, arista aris){
    //Esta funcion inserta una arista en el inicio de la lista enlazada
    // que representa al vertice dado por la arista, 
    if(aris.v < grafo->numV && aris.w < grafo->numV){
        //Verificamos que el vertice existe en nuestra lista de adyacencia
        grafo->adj[aris.v] = crear_nodo(aris.w, grafo->adj[aris.v], aris.costo);
        grafo->adj[aris.w] = crear_nodo(aris.v, grafo->adj[aris.w], aris.costo);
        grafo->numA++;
    }
}

void remover_arista(Grafo grafo, arista aris){
    //Esta funcion remueve una arista buscando la direccion anterior
    // a los vertices que la componen a esta para asi poder
    // desenlazrla y liberarla, y guarda la nueva cantidad en el grafo.
    int v = aris.v;
    int w = aris.w;
    enlace posV_W = buscar_nodo_anterior(grafo->adj[v], w);
    enlace posW_V = buscar_nodo_anterior(grafo->adj[w], v);
    if(posV_W != NULL || posW_V != NULL){
        enlace tempV_W;
        if(posV_W->vertice == w){
            tempV_W = posV_W;
            grafo->adj[v] = posV_W->siguiente;
        }
        else{
            tempV_W = posV_W->siguiente;
            posV_W->siguiente = posV_W->siguiente->siguiente;
        }

        enlace tempW_V;
        if(posW_V->vertice == v){
            tempW_V = posW_V;
            grafo->adj[w] = posW_V->siguiente;
        }
        else{
            tempW_V = posW_V->siguiente;
            posW_V->siguiente = posW_V->siguiente->siguiente;
        }
        free(tempV_W);
        free(tempW_V);
        grafo->numA--;
    }
}

int pertenece_arista(Grafo grafo, arista aris){
    // Esta funcion vertifica si una arista pertenece al grafo
    int v = aris.v;
    int w = aris.w;
    enlace ver = buscar_nodo(grafo->adj[v], w);
    if (ver != NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int comparar_aristas(arista A1, arista A2){
    //Compara dos aristas en donde si son iguales retorna 1, sino 0.
    if(A1.v == A2.v){
        if(A1.w == A2.w){
            return 1;
        }
    }
    else if(A1.w == A2.v){
        if (A1.v == A2.w){
            return 1;
        }
    }
    return 0;
}

int obtener_aristas(Grafo grafo, arista aristas[]){
    //Esta funcion ingresa todas las aristas de un grafo a un
    // arreglo de aristas dado, y retorna el largo de este arreglo
    int v, t, z = 0, ver;
    enlace w;
    arista aris;
    for(v = 0; v < grafo->numV; v++){
        for(w = grafo->adj[v]; w != NULL; w = w->siguiente){
            aris = crear_arista(v, w->vertice, 0);
            ver = 1;
            for(t = 0; t < z; t++){
                if(comparar_aristas(aristas[t], aris) == 1){
                    ver = 0;
                    break;
                }
            }
            if(ver == 1){
                aristas[z++] = aris;
            }
        }
    }
    return z;
}

int obtener_grado(Grafo grafo, int vertice){
    //Esta funcion entrega el grado de un vertice perteneciente a un grafo dado.
    int grado = 0;
    enlace pos;
    for(pos = grafo->adj[vertice]; pos != NULL; pos = pos->siguiente){
        grado++;
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
    int j = 0;
    enlace pos;
    for(pos = grafo->adj[v]; pos != NULL; pos = pos->siguiente){
        ady[j++] = pos->vertice;
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

int es_grafo_simple(Grafo grafo){
    //Esta funcion verifica si un grafo es simple, retornando 1 si lo es,
    // y por el contrario 0.
    int i;
    int max_aristas = (grafo->numV*(grafo->numV - 1))/2; 
    enlace posV, posC;
    if (max_aristas >= grafo->numA){
        //Se verifica la propiedad de un grafo simple
        // del maximo de arista en funcion de sus vertices
        for(i = 0; i < grafo->numV; i++){
            for(posV = grafo->adj[i]; posV != NULL; posV = posV->siguiente){
                for(posC = posV->siguiente; posC != NULL; posC = posC->siguiente){
                    if(posV->vertice == posC->vertice){
                        //Con este triple for se verifica que el grafo no presente
                        // bucles y que este no tenga aristas paralelas
                        return 0;
                    }
                }
            }
        }
        return 1;
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
            if(buscar_nodo(grafo->adj[vert], vert_ady) == NULL){
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
        if(buscar_nodo(grafo->adj[vert], vert_ady) == NULL){
            return 0;
        }
    }
    if(buscar_nodo(grafo->adj[vert_ady], vertices[0]) == NULL){
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
            if(buscar_nodo(grafo->adj[vert], vert_ady) != NULL){
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

Grafo grafo_complemento(Grafo grafo){
    //Esta funcion crea un grafo complemento, para esto se crea
    // un grafo completo con la cantidad de vertices del grafo entregado
    // y se le eliminan las aristas que el grafo entregado contiene
    // generando asi el grafo complemento y retornando este.
    int v;
    Grafo grafo_final = inicia_grafo_completo(grafo->numV);
    arista aristas[grafo->numA];
    int largo = obtener_aristas(grafo, &aristas);
    for(v = 0; v < largo; v++){
        remover_arista(grafo_final, aristas[v]);
        printf("%d\n", grafo_final->adj[1]->vertice);
    }
    return grafo_final;
}

void imprimir_conjunto_aristas(Grafo grafo){
    //Esta funcion obtiene todas las aristas de un grafo
    // y las imprime.
    int i;
    arista aristas[grafo->numA];
    int largo = obtener_aristas(grafo, &aristas);
    printf("Conjunto de Aristas del grafo:\n");
    for(i = 0; i < largo; i++){
        printf("arista n%i: (%d, %d)\n", i+1, aristas[i].v, aristas[i].w);
    }
}