typedef struct grafo *Grafo;

struct grafo{
    int vertices[512][512];
    int largo;
};

Grafo crearGrafo();

void insertarVertice(Grafo grafo);

void insertarArista(Grafo grafo, int vertN1, int vertN2);

void eliminarArista(Grafo grafo, int vert1, int vert2);

void obtenerAristas(Grafo grafo, int vert);

int consultarArista(Grafo grafo, int vert1, int vert2);

int tieneAristas(Grafo grafo);

int esVacio(Grafo grafo);