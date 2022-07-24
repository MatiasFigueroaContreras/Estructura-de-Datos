//Estructura vista en clase..
//Estructura de una lista simplemente enlazada
typedef struct nodo *enlace;

struct nodo
{
    int vertice;
    int tipo;
    int marca;
    enlace siguiente;
};

//Estructura de una arista la cual contiene los vertices que conecta(v y w)
typedef struct{
    int v;
    int w;
}arista;

//Estructura de un grafo que contiene la cantidad de vertices(numV), cantidad de 
// aristas(numA), y un arreglo de listas simplemente enlazadas el cual cada lista 
// representa a un vertice y los valores de esta lista a sus vertices adyacentes.
struct grafo
{
    int numV;
    int numA;
    enlace *adj;
};

typedef struct grafo *Grafo; //direccion al grafo
//Todas estas estructuras componen la lista de adyacencia para un grafo no dirigido

arista crear_arista(int v, int w);

enlace crear_nodo(int valor, enlace sig);

enlace buscar_nodo(enlace head, int valor);

enlace buscar_nodo_anterior(enlace head, int valor);

Grafo iniciar_grafo(int numV);

Grafo inicia_grafo_completo(int numV);

void insertar_arista(Grafo grafo, arista aris);

void remover_arista(Grafo grafo, arista aris);

int pertenece_arista(Grafo grafo, arista aris);

int obtener_aristas(Grafo grafo, arista aristas[]);

int obtener_grado(Grafo grafo, int vertice);

void grado_vertices(Grafo grafo, int grados[]);

int grado_maximo(Grafo grafo);

int grado_minimo(Grafo grafo);

int obtener_adyacentes(Grafo grafo, int ady[], int v);

int es_regular(Grafo grafo);

int es_grafo_simple(Grafo grafo);

int es_clique(Grafo grafo, int vertices[], int cant_vertices);

int es_tour(Grafo grafo, int vertices[], int cant_vertices);

int es_conjunto_independiente(Grafo grafo, int vertices[], int cant_vertices);

int es_cobertura_aristas(Grafo grafo, arista aristas[], int cant_aristas);

Grafo grafo_complemento(Grafo grafo);

void imprimir_conjunto_aristas(Grafo grafo);