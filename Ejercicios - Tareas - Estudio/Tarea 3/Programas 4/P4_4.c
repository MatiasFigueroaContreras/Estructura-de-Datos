//4. Crear un programa que compare dos archivos e indique el carácter donde ellos difieran (si es que difieren)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char name_ar1[100], name_ar2[100];
    char *c = (char *)malloc(sizeof(char) * 1);
    char *x = (char *)malloc(sizeof(char) * 1);
    int i, ver1, ver2, v;
    FILE * ar1;
    FILE * ar2;

    printf("Ingrese el nombre de su archivo n1: ");
    scanf("%s", name_ar1);
    printf("Ingrese el nombre de su archivo n2: ");
    scanf("%s", name_ar2);

    ar1 = fopen(name_ar1, "r");
    ar2 = fopen(name_ar2, "r");

    if (ar1 == NULL){
        //Verificamos que el archivo n1 se encuentre.
        printf("Error al abrir el archivo numero 1, porfavor verifique el nombre.");
        return 0;
    }
    if (ar2 == NULL){
        //Verificamos que el archivo n2 se encuentre.
        printf("Error al abrir el archivo numero 2, porfavor verifique el nombre.");
        return 0;
    }
    i = 1;
    ver1 = 1;
    ver2 = 1;
    while ((ver1 == 1) || (ver2 == 1)){
        //Recorre dos archivos hasta llegar al final de estos para poder comparar los caracteres y mostrar
        // al usuario en cual de estos difiere
        if (c != EOF){
            c = getc(ar1);
        }
        else{
            c = ' ';
            ver1 = 0;
        }

        if (x != EOF){
            x = getc(ar2);
        }
        else{
            x = ' ';
            ver2 = 0;
        }
        v = strcmp(&c, &x);
        if (v != 0){
            printf("Los caracteres difieren en la posicion %d, en donde: \nCaracter archivo n1: %c\nCaracter archivo n2: %c \n\n", i, c, x);
        }
        i++;
    }

    fclose(ar1);
    fclose(ar2);

    free(c);
    free(x);

    return 0;
}
