//Estructura vista en clase..
//Estructura de una arista la cual contiene los vertices que conecta(v y w)
typedef struct{
    int v;
    int w;
}arista;

//Estructura de un grafo que contiene la cantidad de vertices(numV), cantidad de 
// aristas(numA), y un matriz en donde la fila representa los vertices y
// las columnas sus vertices adyacentes.
struct grafo{
    int numV;
    int numA;
    int **adj;
};

typedef struct grafo *Grafo; //direccion al grafo

arista crear_arista(int v, int w);

int **inicia_matriz(int filas, int columnas, int valor);

void modificar_bucles(Grafo grafo, int valor);

int tiene_bucles(Grafo grafo);

Grafo iniciar_grafo(int cant_vertices);

Grafo iniciar_grafo_completo(int cant_vertices, int valor);

void insertar_arista(Grafo grafo, arista A);

void remover_arista(Grafo grafo, arista A);

int pertenece_arista(Grafo grafo, arista a);

int obtener_aristas(Grafo grafo, arista aristas[]);

int obtener_grado(Grafo grafo, int vertice);

void grado_vertices(Grafo grafo, int grados[]);

int grado_maximo(Grafo grafo);

int grado_minimo(Grafo grafo);

int obtener_adyacentes(Grafo grafo, int ady[], int v);

int es_regular(Grafo grafo);

Grafo grafo_complemento(Grafo grafo);

int es_grafo_simple(Grafo grafo);

int es_clique(Grafo grafo, int vertices[], int cant_vertices);

int es_tour(Grafo grafo, int vertices[], int cant_vertices);

int es_conjunto_independiente(Grafo grafo, int vertices[], int cant_vertices);

int es_cobertura_aristas(Grafo grafo, arista aristas[], int cant_aristas);

void imprimir_conjunto_aristas(Grafo grafo);