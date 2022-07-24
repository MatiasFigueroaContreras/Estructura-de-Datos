#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.c"

void ingresarDatosDiccionario(link head, char nombre_archivo[]){
    //Funcion para capturar las palabras, definicion, y sinonimos, para asi agregarlos al diccionario.
    FILE *rFile;

    rFile = fopen(nombre_archivo, "r");
    if (rFile == NULL){
        // En caso de que no se encuentre el archivo, retroalimentamos al usuario.
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return;
    }
    int largo;
    fscanf(rFile, "%d ", &largo);
    char **palabra = (char**)malloc(sizeof(char*) * largo);
    char **definicion = (char**)malloc(sizeof(char*) * largo);
    char **sinonimos = (char**)malloc(sizeof(char*) * largo);

    int j;
    for(j = 0; j < largo; j++){
        palabra[j] = (char*)malloc(sizeof(char) * 20);
        definicion[j] = (char*)malloc(sizeof(char) * 10000);
        sinonimos[j] = (char*)malloc(sizeof(char) * 10000);
    }
    int i = 0;
    while ((fscanf(rFile, "%[^\n] ", palabra[i]) != EOF) && (i < largo)){
        //Con %[^\n] se obtienen todos los caracteres excepto si se encuentra frente a un salto de linea
        // en donde se deja de capturar caracteres.
        fscanf(rFile, "%[^\n] ", definicion[i]);
        fscanf(rFile, "%[^\n] ", sinonimos[i]);
        insertarPalabraDi(head, palabra[i], definicion[i], sinonimos[i]);
        i++;
    }
    fclose(rFile);
}

int main(){
    link DiccionarioEDA = crearDiccionario();
    ingresarDatosDiccionario(DiccionarioEDA, "diccionarioEDA.txt");
    char clean;
    int opcion = 0;
    do{
        //Iteracion que verifica si el usuario quiere salir o no del programa.
        char *palabra = (char *)malloc(sizeof(char) * 20);
        char *definicion = (char *)malloc(sizeof(char) * 10000000);
        char *sinonimos = (char *)malloc(sizeof(char) * 10000000);
        char *definicionP;
        char *sinonimosP;
        if(opcion == 0){
            printf("\n\tDiccionario en el contexto de las estructuras de datos:");
        }
        printf("\n\t\tMenu de Opciones:\n");
        printf("1.- Ver diccionario completo\n");
        printf("2.- Buscar definicion\n");
        printf("3.- Buscar sinonimos\n");
        printf("4.- Agregar palabra\n");
        printf("5.- Actualizar definicion\n");
        printf("6.- Actualizar sinonimos\n");
        printf("7.- Eliminar palabra\n");
        printf("8.- Salir\n");
        scanf("%d", &opcion);
        while (((clean = getchar()) != '\n') && (clean != EOF)); //Eliminamos el salto de linea que produce la funcion scanf luego de recibir su entrada.
        switch (opcion){
            //Se asigna el codigo correspondiente para la opcion seleccionada.
            case 1:
                imprimirDiccionario(DiccionarioEDA);
                break;
            case 2:
                printf("\nIngrese la palabra que desea saber la definicion: ");
                gets(palabra);
                definicionP = buscarDef(DiccionarioEDA, palabra);
                if (definicionP != NULL){
                    printf("\nDefinicion: %s\n", definicionP);
                }
                else{
                    printf("\nLa palabra ingresada no se encuentra en el diccionario.\n");
                }
                break;
            case 3:
                printf("\nIngrese la palabra que desea saber los sinonimos: ");
                gets(palabra);
                sinonimosP = buscarSin(DiccionarioEDA, palabra);
                if (sinonimosP != NULL){
                    printf("\nSinonimo: %s\n", sinonimosP);
                }
                else{
                    printf("\nLa palabra ingresada no se encuentra en el diccionario.\n");
                }
                break;
            case 4:
                printf("\nIngrese la palabra que desea agregar: ");
                gets(palabra);
                printf("\nIngrese su definicion: ");
                gets(definicion);
                printf("\nIngrese sus sinonimos: ");
                gets(sinonimos);
                insertarPalabraDi(DiccionarioEDA, palabra, definicion, sinonimos);
                break;
            case 5:
                printf("Ingrese la palabra: ");
                gets(palabra);
                printf("Ingrese la nueva definicion: ");
                gets(definicion);
                actualizarDef(DiccionarioEDA, palabra, definicion);
                break;
            case 6:
                printf("Ingrese la palabra: ");
                gets(palabra);
                printf("Ingrese los nuevos sinonimos: ");
                gets(sinonimos);
                actualizarSin(DiccionarioEDA, palabra, sinonimos);
                break;
            case 7:
                printf("Ingrese la palabra que desea eliminar del diccionario: ");
                gets(palabra);
                eliminarPalabraDi(DiccionarioEDA, palabra);
                break;
            case 8:
                break;
            default:
                printf("\nIngrese una opcion valida: \n");
                break;
        }
    }while(opcion != 8);
    return 0;
}
