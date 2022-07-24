//Estructura a ocupar en el TDA (Dominio)
typedef struct{
    int largoActual;
    int elementos[256];
}Lista;

//Funciones a ocupar en el TDA (Operaciones)

Lista crearLista();

void insertarElemFin(Lista *list, int elemento);

void insertarElemPos(Lista *list, int pos, int elemento);

void eliminarElemFin(Lista *list);

void eliminarElemPos(Lista *list, int pos);

void actualizarElemPos(Lista *list, int pos, int newElement);

void anularLista(Lista *list);

int largoLista(Lista *list);

int posicionElem(Lista *list, int elemento);

int recuperaElem(Lista *list, int pos);

char isVaciaLista(Lista *list);
