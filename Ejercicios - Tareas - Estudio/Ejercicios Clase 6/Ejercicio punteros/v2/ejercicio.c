#include <stdio.h>

struct datos{
    char nombre[100];
    int edad;
    float altura;
};

void almacenDeIndividuos(struct datos *Datos, int cantidad){
    int i;
    for(i = 0; i < cantidad; i++){
        printf("\nIngrese el nombre del individuo n%i: ", i + 1);
        scanf("%s", &Datos[i].nombre);
        printf("Ingrese la edad del individuo n%i: ", i + 1);
        scanf("%d", &Datos[i].edad);
        printf("Ingrese la altura del individuo n%i: ", i + 1);
        scanf("%f", &Datos[i].altura);
    } 
}

void buscadorElementosN(struct datos *Datos, int cantidad, char elemento[20]){
    int i;
    for(i = 0; i < cantidad; i++){
        if ((strcmp(Datos[i].nombre, elemento)) == 0){
            printf("\nIndividuo encontrado con los siguientes datos\n");
            printf("Numero %i\n", i + 1);
            printf("Nombre: %s\n", Datos[i].nombre);
            printf("Edad: %d\n", Datos[i].edad);
            printf("Altura: %.2f\n", Datos[i].altura);
        }
    }
}

void buscadorElementosP(struct datos *Datos, int cantidad, char elemento[20]){
    int i;
    for(i = 0; i < cantidad; i++){
        if ((strcmp((Datos + i)->nombre, elemento)) == 0){
            printf("\nIndividuo encontrado con los siguientes datos\n");
            printf("Numero %i\n", i + 1);
            printf("Nombre: %s\n", Datos[i].nombre);
            printf("Edad: %d\n", Datos[i].edad);
            printf("Altura: %.2f\n", Datos[i].altura);
        }
    }
}

int main(){
    int cantidad;
    char elemento[20];
    int * punteroDatos;
    
    printf("Ingrese la cantidad de individuos que desea almacenar:\n");
    scanf("%d", &cantidad);
    struct datos Datos[cantidad];
    almacenDeIndividuos(&Datos, cantidad);

    printf("Ingrese el nombre del individuo que desea buscar: \n");
    scanf("%s", elemento);
    // se le pasa la direccion del arreglo de las estructuras Datos al puntero *Datos definido en la funcion
    buscadorElementosN(&Datos, cantidad, elemento);
    // se le pasa la direccion de la estructura Datos[0] al puntero *Datos definido en la funcion
    buscadorElementosP(&Datos[0], cantidad, elemento);
}
