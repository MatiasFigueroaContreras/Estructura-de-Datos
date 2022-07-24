#include <stdio.h>

struct datos{
    char nombre[100];
    int edad;
    float altura;
};

int main(){
    int i, cantidad;
    char elemento[20];
    int *DatosP;

    //Funcion que pide datos y cantidad de individuos a almacenar
    printf("Ingrese la cantidad de individuos que desea almacenar:\n");
    scanf("%d", &cantidad);
    struct datos Datos[cantidad];
    for(i = 0; i < cantidad; i++){
        printf("\nIngrese el nombre del individuo n%i: ", i + 1);
        scanf("%s", &Datos[i].nombre);
        printf("Ingrese la edad del individuo n%i: ", i + 1);
        scanf("%d", &Datos[i].edad);
        printf("Ingrese la altura del individuo n%i: ", i + 1);
        scanf("%f", &Datos[i].altura);
    }

    // Funcion que busca los elementos en el arreglo por el nombre del individuo
    printf("Ingrese el nombre del individuo que desea buscar: \n");
    scanf("%s", elemento);
    for(i = 0; i < cantidad; i++){
        if (strcmp(Datos[i].nombre, elemento) == 0){
            printf("Individuo encontrado con los siguientes datos\n");
            printf("Numero %i\n", i + 1);
            printf("Nombre: %s\n", Datos[i].nombre);
            printf("Edad: %d\n", Datos[i].edad);
            printf("Altura: %.2f\n", Datos[i].altura);
        }
    }

    // DatosP = &Datos[0];
    // for(i = 0; i < cantidad; i++){
        
    //     if (strcmp((*(DatosP + i)).nombre, elemento) == 0){
    //         printf("Individuo encontrado con los siguientes datos\n");
    //         printf("Numero %i\n", i + 1);
    //         printf("Nombre: %s\n", Datos[i].nombre);
    //         printf("Edad: %d\n", Datos[i].edad);
    //         printf("Altura: %.2f\n", Datos[i].altura);
    //     }
    // }

    return 0;
}
