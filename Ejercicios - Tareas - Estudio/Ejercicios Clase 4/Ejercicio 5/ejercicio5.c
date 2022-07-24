#include <stdio.h>

int main(){
    char name_ar1[100], name_ar2[100], c, x;
    int i;
    FILE * ar1;
    FILE * ar2;

    printf("Ingrese el nombre de su archivo n1: ");
    scanf("%s", name_ar1);
    printf("Ingrese el nombre de su archivo n2: ");
    scanf("%s", name_ar2);

    ar1 = fopen(name_ar1, "r");
    ar2 = fopen(name_ar2, "r");

    if (ar1 == NULL){
        printf("Error al abrir el archivo numero 1, porfavor verifique el nombre.");
        return 0;
    }
    if (ar2 == NULL){
        printf("Error al abrir el archivo numero 2, porfavor verifique el nombre.");
        return 0;
    }

    i = 1;
    while (((c = getc(ar1)), (x = getc(ar2))) != EOF){
        if (c != x){
            printf("Los caracteres difieren en la posicion %d, en donde: \nCaracter archivo n1: %c\nCaracter archivo n2: %c \n\n", i, c, x);
        }
        i++;
    }

    fclose(ar1);
    fclose(ar2);

    return 0;
}
