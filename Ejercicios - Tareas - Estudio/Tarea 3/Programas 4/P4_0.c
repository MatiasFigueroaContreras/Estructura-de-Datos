//4.0 Escribir un programa que lea un archivo y lo muestre por pantalla
#include <stdio.h>

int main(){
    char name_ar[100], c;
    FILE * arc;

    printf("Ingrese el nombre de su archivo: ");
    scanf("%s", name_ar);

    arc = fopen(name_ar, "r");
    if (arc == NULL){
        //Verificamos que el archivo se encuentre.
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return 0;
    }
    while ((c = getc(arc)) != EOF){
        //Imprimimos los caracteres hasta que se llege al final del archivo.
        printf("%c", c);
    }

    return 0;
}
