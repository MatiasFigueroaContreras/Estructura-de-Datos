// typedef struct nodo *Cola;

// struct nodo{
//     int numero;
//     Cola siguiente;
//     Cola top;
//     Cola bot;
// };

// Cola crearCola(){

// }

// typedef struct nodo *sig;

// struct nodo{
//     int numero;
//     sig siguiente;
// };

typedef struct{
    int numero;
    sigN *siguiente;
}sigN;

typedef sigN *nodo;

typedef struct{
    nodo top;
    nodo bot;
}cola;

typedef cola *Cola;


Cola crearCola();

nodo crearNodo(int num);

int isEmpty(Cola cola);

void encolar(Cola cola, int num);

void desencolar(Cola cola);
