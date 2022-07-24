#include <stdio.h>

int read_write_File(fRead, fWrite){
    char c;
    while ((c = getc(fRead)) != EOF){
        putc(c, fWrite);
    }
    return 0;
}

int main(){
    char name_ar1[100], name_ar2[100];
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

    read_write_File(ar1, finalAr);
    putc(' ', finalAr);
    read_write_File(ar2, finalAr);

    printf("Archivos concatenados correctamente.");

    fclose(ar1);
    fclose(ar2);
    fclose(finalAr);

    return 0;
}
