typedef struct nodoC *link;

struct nodoC{
    int numero;
    link siguiente;
};

typedef struct cola *Cola;

struct cola{
    link top;
    link bot;
};

Cola crearCola();

link crearNodo(int num);

int isEmpty(Cola cola);

void encolar(Cola cola, int num);

void desencolar(Cola cola);

int elemTop(Cola cola);

int elemBot(Cola cola);

int estaEnCola(Cola cola, int num);