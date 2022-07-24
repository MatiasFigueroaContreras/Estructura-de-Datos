typedef struct nodo *Pila;

struct nodo{
    int numero;
    Pila siguiente;
};

Pila crearPila();

Pila crearNodo(int num);

int isEmpty(Pila top);

// 1era forma
// void push(Pila top, Pila newNodo);

// 2da forma
void push(Pila top, int newNodo);

int pop(Pila top);