#include <stdio.h>

int main(){
    char name_ar1[100], name_ar2[100], c;
    FILE * ar1;
    FILE * ar2;
    FILE * finalAr;

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

    finalAr = fopen("Archivos concatenados.txt", "w");

    while ((c = getc(ar1)) != EOF){
        putc(c, finalAr);
    }
    putc(' ', finalAr);
    while ((c = getc(ar2)) != EOF){
        putc(c, finalAr);
    }

    printf("Archivos concatenados correctamente.");

    fclose(ar1);
    fclose(ar2);
    fclose(finalAr);

    return 0;
}
