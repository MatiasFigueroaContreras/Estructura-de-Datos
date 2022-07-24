//3. Crear un programa que lea dos archivos y entregue otro intercalando los caracteres de cada archivo 
#include <stdio.h>

int main(){
    char name_ar1[100], name_ar2[100], c, x;
    int ver1, ver2;
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
        //Verificamos que el archivo n1 se encuentre.
        printf("Error al abrir el archivo numero 1, porfavor verifique el nombre.");
        return 0;
    }
    if (ar2 == NULL){
        //Verificamos que el archivo n2 se encuentre.
        printf("Error al abrir el archivo numero 2, porfavor verifique el nombre.");
        return 0;
    }

    finalAr = fopen("Archivos intercalados.txt", "w");
    ver1 = 1;
    ver2 = 1;
    while ((ver1 == 1) || (ver2 == 1)){
        //Ingresamos un caracter de cada archivo por cada iteracion, hasta que se haya llegado 
        // al final del archivo, en este caso se esperara a llegar al final del archivo faltante
        // para asi terminar de iterar, y tener los archivos intercalados.
        if (ver1 == 1){
            c = getc(ar1);
            if (c != EOF){
                putc(c, finalAr);
            }
            else{
                ver1 = 0;
            }
        }
        if (ver2 == 1){
            x = getc(ar2);
            if (x != EOF){
                putc(x, finalAr);
            }
            else{
                ver2 = 0;
            }
        }
    }

    printf("Archivos intercalados correctamente.");

    fclose(ar1);
    fclose(ar2);
    fclose(finalAr);

    return 0;
}
