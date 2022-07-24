typedef struct diccionario *link;

struct diccionario{
    char *palabra;
    char *definicion;
    char *sinonimos;
    link siguiente;
};

link last_link(link head);

link link_palabra(link head, char palabra[]);

link post_link_palabra(link head, char palabra[]);

link crearDiccionario();

void insertarPalabraDi(link head, char *palabra, char *definicion, char *sinonimos);

void eliminarPalabraDi(link head, char *palabra);

void actualizarDef(link head, char *palabra, char *definicion);

void actualizarSin(link head, char *palabra, char *sinonimos);

char *buscarDef(link head, char *palabra);

char *buscarSin(link head, char *palabra);

void imprimirDiccionario(link head);