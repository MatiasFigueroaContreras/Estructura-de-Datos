#include <stdio.h>
#include <stdlib.h>

void readArray(int *array, int largo){
    //Funcion que lee el arreglo y lo imprime en formato num1, num2, num3...
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
    //Funcion que suma los elementos de un arreglo y retorna el resultado de este
    int i, suma;
    suma = 0;
    for(i = 0; i <= largoA - 1; i++){
        suma += *(array + i);
    }

    return suma;
}

int readSaveFile(char nameFile[], int *lenght){
    //Funcion que lee los elementos de un archivo y los guarda en un arreglo el cuales retornado
    // ademas guarda en la direccion de memoria pasada el largo de este arreglo
    FILE *rfile;
    int n, i;

    rfile = fopen(nameFile, "r");
    if (rfile == NULL){
        printf("\nError al abrir el archivo, porfavor verifique el nombre.");
        return 0;
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

int comparacionArrays(int *arrayA, int *arrayB, int largo, char cArrayA, char cArrayB){
    //Funcion que compara dos arreglos por posicion, entregando por pantalla cual es mayor o si son iguales.
    int i;
    for (i = 0; i <= largo - 1; i++){
        if (arrayA[i] > arrayB[i]){
            printf("En la posicion %d, el valor del arreglo %c: %d, es MAYOR que el valor del arreglo %c: %d\n", i + 1, cArrayA, arrayA[i], cArrayB, arrayB[i]);
        }
        else if (arrayA[i] < arrayB[i]){
            printf("En la posicion %d, el valor del arreglo %c: %d, es MENOR que el valor del arreglo %c: %d\n", i + 1, cArrayA, arrayA[i], cArrayB, arrayB[i]);
        }
        else{
            printf("En la posicion %d, el valor del arreglo %c: %d, es IGUAL a el valor del arreglo %c: %d\n", i + 1, cArrayA, arrayA[i], cArrayB, arrayB[i]);
        }
    }
}


int productoPunto(int *arrayA, int *arrayB,int largo){
    //Funcion que calcula el producto punto entre dos arreglos, retornado el valor de este resultado.
    int i, productoP;
    i = 0;
    productoP = 0;
    while (i < largo ){
        productoP = productoP + arrayA[i] * arrayB[i];
        ++i;
    }

    return productoP;
}

char letraArray(pos){
    //Funcion que compara el valor de la posicion seleccionada, para entregar el caracter correspondiente.
    if(pos == 1){
        return 'A';
    }
    else if(pos == 2){
        return 'B';
    }
    else if(pos == 3){
        return 'C';
    }
    else if(pos == 4){
        return 'D';
    }
    else if(pos == 5){
        return 'E';
    }
}

void fillArray(int array[], int lenght){
    //Funcion que le pregunta al usuario que valores quiere asignarle a su arreglo, para almacenarlos en este. 
    int i;
    for (i = 0; i < lenght; i++){
        printf("Ingrese el valor del arreglo con pos n%i: ", i + 1);
        scanf("%d", &array[i]);
    }
}


int main(){
    int r, r1, r2, r3, r4, seleccion, seleccion1, seleccion2;
    int *lenghtArrays = (int *) malloc(sizeof(int) * 5);
    int i;
    char nameFile[30];
    char letra1, letra2;
    int si_no, menu_opcion, arraySelected;
    int opcion = 0;
    int **arrayP = (int **) malloc(sizeof(int *) * 5);
    for(i = 0; i < 5; i++){
        //Iteracion para setear el valor del largo de los arreglos en 0.
        lenghtArrays[i] = 0;
    }
    do{
        //Iteracion que verifica si el usuario quiere salir o no del programa.
        if(opcion == 0){
            printf("\n\tBienvenido, porfavor seleccione la opcion que desea:");
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
            //Se asigna el codigo correspondiente para la opcion seleccionada.
            case 1:
                printf("\n\tSeleccionaste Menu de arreglos, seleccione la opcion que desea:\n\n");
                printf("1.- Volver al Menu de opciones\n");
                printf("2.- Ver arreglos existentes\n");
                printf("3.- Crear/sobreescribir arreglos (max 4 creados)\n");
                printf("4.- Salir\n");
                scanf("%d", &menu_opcion);
                switch (menu_opcion){
                    //Se asigna el codigo correspondiente para la opcion seleccionada.
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
                        printf("\n\nEl arreglo E tiene los siguientes valores:\n");
                        readArray(arrayP[4], lenghtArrays[4]);
                    }
                    if ((lenghtArrays[0] == 0) && (lenghtArrays[1] == 0) && (lenghtArrays[2] == 0) && (lenghtArrays[3] == 0) && (lenghtArrays[4] == 0)){
                        printf("\nNo se ha creado ningun arreglo\n");
                    }
                    break;
                case 3:
                    printf("\nIngrese el arreglo que desea:\n1.-A\n2.-B\n3.-C\n4.-D\n");
                    scanf("%d", &seleccion1);
                    seleccion = seleccion1 - 1;
                    if(seleccion >= 4){
                        printf("\nLa opcion ingresada no es valida.\n");
                    }
                    else if(lenghtArrays[seleccion1 - 1] == 0){
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
                            printf("\nLa opcion ingresada no es valida.\n");
                        }
                    }
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
                printf("Seleccione con el que desea operar:\n1.-A\n2.-B\n3.-C\n4.-D\n5.-E\n");
                scanf("%d", &seleccion1);
                if((seleccion1 > 5)){
                    printf("\nLa opcion ingresada no es valida.\n");
                }
                else if(lenghtArrays[seleccion1 - 1] == 0){
                    printf("EL arreglo no ha sido creados.");
                }
                else{
                    r1 = sumaArray(arrayP[seleccion1 - 1], lenghtArrays[seleccion1 - 1]);
                    letra1 = letraArray(seleccion1);
                    printf("\nEl valor de la suma de los elementos para el arreglo %c es: %d", letra1, r1);
                }
                break;
            case 3:
                printf("\n\tSeleccionaste lectura de archivo y almacenamiento de arreglo:\n\n");
                if(lenghtArrays[4] != 0){
                    printf("\nEl arreglo por lectura ya fue ingresado");
                    printf("\n¿Desea sobreescribirlo?\n1.-Si\n2.-No\n");
                    scanf("%d", &si_no);
                    if(si_no == 1){
                        free(arrayP[4]);
                        lenghtArrays[4] = 0;
                        printf("Ingrese el nombre del archivo a leer: ");
                        scanf("%s", nameFile);
                        arrayP[4] = readSaveFile(nameFile, &lenghtArrays[4]);
                        if(lenghtArrays[4] != 0){
                            printf("\nLos valores del archivo fueron guardados correctamente en el arreglo E.");
                        }
                    }
                    else if(si_no != 2){
                        printf("\nLa opcion ingresada no es valida.\n");
                    }
                }
                else{
                    printf("Ingrese el nombre del archivo a leer: ");
                    scanf("%s", nameFile);
                    arrayP[4] = readSaveFile(nameFile, &lenghtArrays[4]);
                    if(lenghtArrays[4] != 0){
                            printf("\nLos valores del archivo fueron guardados correctamente en el arreglo E.");
                        }
                }
                break;
            case 4:
                printf("\n\tSeleccionaste comparar dos arreglos:\n\n");
                printf("Ingrese los arreglos con los que desea operar (separados por un espacio):\n1.-A\n2.-B\n3.-C\n4.-D\n5.-E\n");
                scanf("%d %d", &seleccion1, &seleccion2);
                if((seleccion1 > 5) || (seleccion2 > 5)){
                    printf("\nLa opcion ingresada no es valida.\n");
                }
                else if((lenghtArrays[seleccion1 - 1] == 0) || (lenghtArrays[seleccion2 - 1] == 0)){
                    printf("Los arreglos no han sido creado.");
                }
                if(lenghtArrays[seleccion1 - 1] == lenghtArrays[seleccion2 - 1]){
                    printf("\n");
                    letra1 = letraArray(seleccion1);
                    letra2 = letraArray(seleccion2);
                    comparacionArrays(arrayP[seleccion1 - 1], arrayP[seleccion2 - 1], lenghtArrays[seleccion1 - 1], letra1, letra2);
                }
                else{
                    printf("\nEl largo de los arreglos tiene que ser el mismo, porfavor verifique sus tamaños.\n");
                }
                break;
            case 5:
                printf("\n\tSeleccionaste producto punto de arreglos:\n\n");
                printf("Ingrese los arreglos con los que desea operar (separados por un espacio):\n1.-A\n2.-B\n3.-C\n4.-D\n5.-E\n");
                scanf("%d %d", &seleccion1, &seleccion2);
                if((seleccion1 > 5) || (seleccion2 > 5)){
                    printf("\nLa opcion ingresada no es valida.\n");
                }
                else if((lenghtArrays[seleccion1 - 1] == 0) || (lenghtArrays[seleccion2 - 1] == 0)){
                    printf("Los arreglos no han sido creados.");
                }
                else if(lenghtArrays[seleccion1 - 1] == lenghtArrays[seleccion2 - 1]){
                    r3 = productoPunto(arrayP[seleccion1 - 1], arrayP[seleccion2 - 1], lenghtArrays[seleccion1 - 1]);
                    letra1 = letraArray(seleccion1);
                    letra2 = letraArray(seleccion2);
                    printf("\nEl producto punto entre los arreglos %c y %c es: %d", letra1, letra2, r3);
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
