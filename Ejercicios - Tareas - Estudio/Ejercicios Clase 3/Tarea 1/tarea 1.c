#include <stdio.h>

int main(){
    int cantidad;
    printf("Ingrese el tamaño de los arreglos: ");
    scanf("%d", &cantidad);
    int arrayA[cantidad], arrayB[cantidad], i, productoP;
    for(int i = 0; i < cantidad; i++){
        printf("Ingrese el valor a almacenar en el arreglo A: ");
        scanf("%d", &arrayA[i]); 
    }
    for(int i = 0; i < cantidad; i++){
        printf("Ingrese el valor a almacenar en el arreglo B: ");
        scanf("%d", &arrayB[i]); 
    }
    i = 0;
    productoP = 0;
    while (i < cantidad)
    {
        productoP = productoP + arrayA[i] * arrayB[i];
        ++i;
    }
    printf("El producto punto entre los dos arreglos es: %d", productoP);

    return 0;
}
