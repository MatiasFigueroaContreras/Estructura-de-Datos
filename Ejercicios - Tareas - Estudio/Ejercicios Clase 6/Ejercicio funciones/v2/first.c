#include <stdio.h>
#include <stdlib.h>

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

// void readArray3(int *array, int largo){
//     int i;
//     for (i = 0; i <= largo - 1; i++){
//         if (i == largo - 1){
//             printf("%d ", array[i]);
//         }
//         else{
//             printf("%d, ", array[i]);
//         }
//     }
// }

// void readArray2(int array[], int lenght){
//     int i;
//     for (i = 0; i < lenght; i++){
//         if (i == lenght - 1){
//             printf("%d ", array[i]);
//         }
//         else{
//             printf("%d, ", array[i]);
//         }
//     }
// }

int sumaArray(int *array, int largoA){
    int i, suma;
    suma = 0;
    for(i = 0; i <= largoA - 1; i++){
        suma += *(array + i);
    }

    return suma;
}

int readSaveFile(char nameFile[], int *lenght){
    FILE *rfile;
    int n, i;

    rfile = fopen(nameFile, "r");
    if (rfile == NULL){
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return;
    }

    fscanf(rfile, "%d", &n);
    int *arrayR = (int *)malloc(sizeof(int) * n);
    for (i = 0; i <= n - 1; i++){
        fscanf(rfile, "%d", &arrayR[i]);
    }
    fclose(rfile);
    *lenght = n;
    return arrayR;
}

// void readSaveFile(char nameFile[], int *arrayP){
//     FILE *rfile;
//     int n, i;

//     rfile = fopen(nameFile, "r");
//     if (rfile == NULL){
//         printf("Error al abrir el archivo, porfavor verifique el nombre.");
//         return;
//     }

//     fscanf(rfile, "%d", &n);
//     int array[n];
//     for (i = 0; i <= n - 1; i++){
//         fscanf(rfile, "%d", &array[i]);
//         *(arrayP + i) = array[i];
//         // printf("%d\n", array[i]);
//     }
//     // *(arrayP + 1) = n;
//     // *arrayP = &array[0];
//     fclose(rfile);
    
// }

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

void crearArrays(int *array, int *largo){
    int i;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", largo);
    *array = (int *) malloc (sizeof(int) * (*largo));
    for(int i = 0; i < *largo; i++){
        printf("Ingrese el valor a almacenar en el arreglo: ");
        scanf("%d", &array[i]); 
    }
}

void fillArray(int array[], int lenght){
    int i;
    for (i = 0; i < lenght; i++){
        printf("Ingrese el valor del arreglo con pos n%i: ", i + 1);
        scanf("%d", &array[i]);
    }
}


int main(){
    // int *arrayPA, *arrayPB, *arrayPC, *arrayPD;
    int r, r1, r2, r3, r4, seleccion, seleccion1, seleccion2;
    int *lenghtArrays = (int *) malloc(sizeof(int) * 5); 
    lenghtArrays[0] = 0;
    lenghtArrays[1] = 0;
    lenghtArrays[2] = 0;
    lenghtArrays[3] = 0;
    lenghtArrays[4] = 0;
    char nameFile[30];
    int si_no;
    int menu_opcion;
    int opcion = 0;
    int arraySelected;
    int **arrayP = (int **) malloc(sizeof(int *) * 5); 
    do{
        if(opcion == 0){
            printf("\n\tBienvenido, porfavor seleccione la opcion que desea: \n");
        }
        printf("\n\n\t\tMenu de Opciones:\n");
        printf("1.- Menu de arreglos\n");
        printf("2.- Suma de elementos de un arreglo\n");
        printf("3.- Lectura de archivo y almacenamiento de arreglo\n");
        printf("4.- Comparar dos arreglos\n");
        printf("5.- Producto punto de arreglos\n");
        printf("6.- Salir\n");
        scanf("%d", &opcion);

        switch (opcion){
            case 1:
                printf("\n\tSeleccionaste Menu de arreglos, seleccione la opcion que desea:\n\n");
                printf("1.- Volver al Menu de opciones\n");
                printf("2.- Ver arreglos existentes\n");
                printf("3.- Crear arreglos (maximo 4)\n");
                printf("4.- Salir\n");
                scanf("%d", &menu_opcion);
                switch (menu_opcion){
                case 1:
                    break;
                case 2:
                    if (lenghtArrays[0] != 0){
                        printf("\nEl arreglo A tiene los siguientes valores:\n");
                        readArray(arrayP[0], lenghtArrays[0]);
                    }
                    if (lenghtArrays[1] != 0){
                        printf("\n\nEl arreglo B tiene los siguientes valores:\n");
                        readArray(arrayP[1], lenghtArrays[1]);
                    }
                    if (lenghtArrays[2] != 0){
                        printf("\n\nEl arreglo C tiene los siguientes valores:\n");
                        readArray(arrayP[2], lenghtArrays[2]);
                    }
                    if (lenghtArrays[3] != 0){
                        printf("\n\nEl arreglo D tiene los siguientes valores:\n");
                        readArray(arrayP[3], lenghtArrays[3]);
                    }
                    if (lenghtArrays[4] != 0){
                        printf("\n\nEl arreglo F tiene los siguientes valores:\n");
                        readArray(arrayP[4], lenghtArrays[4]);
                    }
                    if ((lenghtArrays[0] == 0) && (lenghtArrays[1] == 0) && (lenghtArrays[2] == 0) && (lenghtArrays[3] == 0) && (lenghtArrays[4] == 0)){
                        printf("\nNo se ha creado ningun arreglo\n");
                    }
                    break;
                case 3:
                    printf("Ingrese con el que desea operar:\n1.-A\n2.-B\n3.-C\n4.-D\n5.-F\n");
                    scanf("%d", &seleccion1);
                    seleccion = seleccion1 - 1;
                    if(lenghtArrays[seleccion1 - 1] == 0){
                        printf("\nIngrese el tamaño del arreglo: ");
                        scanf("%d", &lenghtArrays[seleccion]);
                        arrayP[seleccion] = (int *) malloc (sizeof(int) * lenghtArrays[seleccion]);
                        fillArray(arrayP[seleccion], lenghtArrays[seleccion]);
                    }
                    else{
                        printf("\nEl arreglo que ingreso ya fue creado");
                        printf("\n¿Desea sobreescribirlo?\n1.-Si\n2.-No\n");
                        scanf("%d", &si_no);
                        if(si_no == 1){
                            free(arrayP[seleccion]);
                            printf("\nIngrese el tamaño del arreglo: ");
                            scanf("%d", &lenghtArrays[seleccion]);
                            arrayP[seleccion] = (int *) malloc (sizeof(int) * lenghtArrays[seleccion]);
                            fillArray(arrayP[seleccion], lenghtArrays[seleccion]);
                        }
                        else if(si_no != 2){
                            printf("\nLa opcion ingresada no es valida\n");
                        }
                    }
                    // if (lenghtArrays[0] == 0){
                    //     printf("\nEl arreglo A no tiene asignado valores\n");
                    //     printf("\nDesea asignarle?\n");
                    //     printf("\n1.- Si\n2.- No\n");
                    //     scanf("%d", &si_no);
                    //     switch (si_no){
                    //     case 1:
                    //         printf("\nIngrese el tamaño del arreglo: ");
                    //         scanf("%d", &lenghtArrays[0]);
                    //         arrayP[0] = (int *) malloc (sizeof(int) * lenghtArrays[0]);
                    //         fillArray(arrayP[0], lenghtArrays[0]);
                    //         break;
                    //     case 2:
                    //         break;
                    //     default:
                    //         printf("\nIngrese un opcion valida\n");
                    //         break;
                    //     }
                    // }
                    // if (lenghtArrays[1] == 0){
                    //     printf("\nEl arreglo B no tiene asignado valores\n");
                    //     printf("\nDesea asignarle?\n");
                    //     printf("\n1.- Si\n2.- No\n");
                    //     scanf("%d", &si_no);
                    //     switch (si_no){
                    //     case 1:
                    //         printf("\nIngrese el tamaño del arreglo: ");
                    //         scanf("%d", &lenghtArrays[1]);
                    //         arrayP[1] = (int *) malloc (sizeof(int) * lenghtArrays[1]);
                    //         fillArray(arrayP[1], lenghtArrays[1]);
                    //         break;
                    //     default:
                    //         si_no = 2;
                    //         break;
                    //     }
                    // }
                    // if (lenghtArrays[2] == 0){
                    //     printf("\nEl arreglo C no tiene asignado valores\n");
                    //     printf("\nDesea asignarle?\n");
                    //     printf("\n1.- Si\n2.- No\n");
                    //     scanf("%d", &si_no);
                    //     switch (si_no){
                    //     case 1:
                    //         printf("\nIngrese el tamaño del arreglo: ");
                    //         scanf("%d", &lenghtArrays[2]);
                    //         arrayP[2] = (int *) malloc (sizeof(int) * lenghtArrays[2]);
                    //         fillArray(arrayP[2], lenghtArrays[2]);
                    //         break;
                    //     default:
                    //         si_no = 2;
                    //         break;
                    //     }
                    // }
                    // if (lenghtArrays[3] == 0){
                    //     printf("\nEl arreglo D no tiene asignado valores\n");
                    //     printf("\nDesea asignarle?\n");
                    //     printf("\n1.- Si\n2.- No\n");
                    //     scanf("%d", &si_no);
                    //     switch (si_no){
                    //     case 1:
                    //         printf("\nIngrese el tamaño del arreglo: ");
                    //         scanf("%d", &lenghtArrays[3]);
                    //         arrayP[3] = (int *) malloc (sizeof(int) * lenghtArrays[3]);
                    //         fillArray(arrayP[3], lenghtArrays[3]);
                    //         break;
                    //     default:
                    //         si_no = 2;
                    //         break;
                    //     }
                    // }
                    // if ((lenghtArrays[0] != 0) && (lenghtArrays[1] != 0) && (lenghtArrays[2] != 0) && (lenghtArrays[3] != 0)){
                    //     printf("\nYa lleno todos los espacios para asignar arreglos, si desea asignar nuevos arreglos necesitara reiniciar el programa\n");
                    // }
                    break;
                case 4:
                    opcion = 6;
                    break;
                default:
                    printf("\nIngrese una opcion valida: \n");
                    break;
                }
                break;
            case 2:
                printf("\n\tSeleccionaste suma de elementos de un arreglo:\n\n");
                printf("Seleccione con el que desea operar:\n1.-A\n2.-B\n3.-C\n4.-D\n5.-F\n");
                scanf("%d", &seleccion1);
                r1 = sumaArray(arrayP[seleccion1 - 1], lenghtArrays[seleccion1 - 1]);
                printf("\nEl valor de la suma de los elementos es: %d\n", r1);
                break;
            case 3:
                printf("\n\tSeleccionaste lectura de archivo y almacenamiento de arreglo:\n\n");
                
                printf("Ingrese el nombre del archivo a leer: ");
                scanf("%s", nameFile);
                int *prueba;
                arrayP[4] = readSaveFile(nameFile, &lenghtArrays[4]);
                readArray(arrayP[4], lenghtArrays[4]);
                printf("\nLos valores del archivo fueron guardados correctamente en el arreglo F");
                break;
            case 4:
                printf("\n\tSeleccionaste comparar dos arreglos:\n\n");
                printf("Ingrese con los que desea operar (separados por un espacio):\n1.-A\n2.-B\n3.-C\n4.-D\n5.-F\n");
                scanf("%d %d", &seleccion1, &seleccion2);
                printf("\n");
                comparacionArrays(arrayP[seleccion1 - 1], arrayP[seleccion2 - 1], lenghtArrays[seleccion1 - 1]);
                break;
            case 5:
                printf("\n\tSeleccionaste producto punto de arreglos:\n\n");
                printf("Ingrese con los que desea operar (separados por un espacio):\n1.-A\n2.-B\n3.-C\n4.-D\n5.-F\n");
                scanf("%d %d", &seleccion1, &seleccion2);
                if(lenghtArrays[seleccion1 - 1] == lenghtArrays[seleccion2 - 1]){
                    r3 = productoPunto(arrayP[seleccion1 - 1], arrayP[seleccion2 - 1], lenghtArrays[seleccion1 - 1]);
                    printf("\nEl producto punto es: %d", r3);
                }
                else{
                    printf("\nEl largo de los arreglos tiene que ser el mismo, porfavor verifique sus tamaños.\n");
                }
                
                break;
            case 6:
                break;
            default:
                printf("\nIngrese una opcion valida: \n");
                break;
        }
    }while ((opcion != 6));
    return 0;
}
