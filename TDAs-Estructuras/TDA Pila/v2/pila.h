typedef struct nodo *link;

struct nodo{
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
