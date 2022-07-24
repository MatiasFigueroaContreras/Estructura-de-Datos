#include <stdio.h>

void readArray(int *array, int largo){
    int i;
    for (i = 0; i <= largo - 1; i++){
        if (i == largo - 1){
            printf("%d ",*(array + i));
        }
        else{
            printf("%d, ",*(array + i));
        }
    }
}

int sumaArray(int *array, int largoA){
    int i, suma;
    suma = 0;
    for(i = 0; i <= largoA - 1; i++){
        suma += *(array + i);
    }

    return suma;
}

void readSaveFile(char nameFile[50], int *arrayP){
    FILE *rfile;
    int n, i;

    rfile = fopen(nameFile, "r");
    if (rfile == NULL){
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return;
    }

    fscanf(rfile, "%d", &n);
    int array[n];
    for (i = 0; i <= n - 1; i++){
        fscanf(rfile, "%d", &array[i]);
        *(arrayP + i) = array[i];
        // printf("%d\n", array[i]);
    }
    // *(arrayP + 1) = n;
    // *arrayP = &array[0];
    fclose(rfile);
    
}

int comparacionArrays(int *arrayA, int *arrayB, int largo){
    int i;
    for (i = 0; i <= largo - 1; i++){
        if (arrayA[i] > arrayB[i]){
            printf("En la posicion %d, el valor del arreglo A: %d, es MAYOR que el valor del arreglo B: %d\n", i, arrayA[i], arrayB[i]);
        }
        else if (arrayA[i] > arrayB[i]){
            printf("En la posicion %d, el valor del arreglo A: %d, es MENOR que el valor del arreglo B: %d\n", i, arrayA[i], arrayB[i]);
        }
        else{
            printf("En la posicion %d, el valor del arreglo A: %d, es IGUAL a el valor del arreglo B: %d\n", i, arrayA[i], arrayB[i]);
        }
    }
}


int productoPunto(int *arrayA, int *arrayB,int largo){
    int i, productoP;
    i = 0;
    productoP = 0;
    while (i < largo ){
        productoP = productoP + arrayA[i] * arrayB[i];
        ++i;
    }

    return productoP;
}


int main(){
    int *arrayPA, *arrayPB, *arrayPC;
    int arrayA[5] = {1, 3, 6, 4, 2};
    int arrayB[5] = {4, 2, 9, 7, 8};
    int arrayC[5];
    int r, r1, r2, r3, r4;
    char nameFile[10] = "array.txt";
    arrayPA = &arrayA[0];
    arrayPB = &arrayB[0];
    arrayPC = &arrayC[0];
    // r = productoPunto(arrayPA, arrayPB, 5);
    // printf("%d", r);
    // readSaveFile(nameFile, arrayPC);
    // printf("%d\n", *(arrayPC + 1));
    // readArray(arrayPC, 5);

    int opcion = 0;
    int arraySelected;
    do{
        if(opcion == 0){
            printf("\n\tBienvenido, porfavor seleccione la opcion que desea: \n");
        }
        printf("\n\n\t\tMenu de Opciones:\n");
        printf("1.- Ver arreglos\n");
        printf("2.- Suma de elementos de un arreglo\n");
        printf("3.- Lectura de archivo y almacenamiento de arreglo\n");
        printf("4.- Comparar dos arreglos\n");
        printf("5.- Producto punto de arreglos\n");
        printf("6.- Salir\n");
        scanf("%d", &opcion);

        switch (opcion){
            case 1:
                printf("\n\tSeleccionaste ver arreglos:\n\n");

                printf("El arreglo A tiene los siguientes valores:\n");
                readArray(arrayPA, 5);
                printf("\nEl arreglo B tiene los siguientes valores:\n");
                readArray(arrayPB, 5);
            break;
            case 2:
                printf("\n\tSeleccionaste suma de elementos de un arreglo:\n\n");

                printf("Para el arreglo A:\n");
                r1 = sumaArray(arrayPA, 5);
                printf("El valor de la suma de los elementos es: %d\n", r1);

                printf("Para el arreglo B:\n");
                r2 = sumaArray(arrayPB, 5);
                printf("El valor de la suma de los elementos es: %d", r2);
            break;
            case 3:
                printf("\n\tSeleccionaste lectura de archivo y almacenamiento de arreglo:\n\n");
                
                printf("El nombre del archivo a leer tiene que ser: array.txt\n");
                readSaveFile(nameFile, arrayPC);
                printf("Los valores del archivo fueron guardados correctamente en un arreglo");
            break;
            case 4:
                printf("\n\tSeleccionaste comparar dos arreglos:\n\n");

                printf("Los arreglos a comparar son A y B:\n");
                comparacionArrays(arrayPA, arrayPB, 5);
            break;
            case 5:
                printf("\n\tSeleccionaste producto punto de arreglos:\n\n");
                printf("Se calculara el producto punto entre los arreglos A y B:\n");
                r3 = productoPunto(arrayPA, arrayPB, 5);
                printf("El producto punto es: %d", r3);
            break;
            case 6:
            break;
            default:
                printf("\nIngrese una opcion valida: \n");
            break;
        }
    }while (opcion != 6);
    return 0;
}
