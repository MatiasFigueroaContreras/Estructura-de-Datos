typedef struct nodoP *link;

struct nodoP{
    int numero;
    link siguiente;
};

typedef struct pila *Pila;

struct pila{
    link top;
};


Pila crearPila();

link crearNodo(int num);

int isEmpty(Pila top);

void push(Pila top, int newNodo);

void pop(Pila top);

int elemTop(Pila pila);

int estaEnPila(Pila pila, int num);
