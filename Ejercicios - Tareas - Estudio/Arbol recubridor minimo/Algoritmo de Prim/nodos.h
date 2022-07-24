//Estructura a ocupar en el TDA (Dominio)
#include "grafo_lista_ady.c"
typedef struct nodoL *link;

struct nodoL{
    int numero;
    arista aris;
    link siguiente;
};

// typedef struct nodo *lista;

// struct lista{
//     link head;
// };


//Funciones a ocupar en el TDA (Operaciones)

link last_link(link head);

link pos_link(link head, int pos, int inicio);

link link_num(link head, int num);

link posA_link_num(link head, int num);

link crearLista();

link crearNodo(int num, arista aris);

void insertarNodoInico(link head, link newNodo);

void insertarNodoFinal(link head, link newNodo);

void insertarNodoPos(link head, link newNodo, int pos);

void insertarNodoNum(link head, link newNodo, int num);

void recorrerLista(link head);

link primeroLista(link head);

link ultimoLista(link head);

void eliminarNodoInicio(link head);

void eliminarNodoFinal(link head);

void eliminarNodoNum(link head, int num);

void eliminarNodoPos(); //terminar

void actualizarNodo(link head, int oldNum, int newNum);

int largoLista(link head);

int isVaciaLista(link head);

link liberarLista(link actual);

void anularLista(link head);
