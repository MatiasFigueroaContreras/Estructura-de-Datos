//4.0v2 Escribir un programa que lea un archivo y lo muestre por pantalla luego modificar el 
//  código anterior para que el programa cree una copia del archivo de entrada, llamado “copia.txt”. 
#include <stdio.h>

int main(){
    char name_ar[100], c;
    FILE * arc;
    FILE * copia_arc;

    printf("Ingrese el nombre de su archivo: ");
    scanf("%s", name_ar);

    arc = fopen(name_ar, "r");
    if (arc == NULL){
        //Verificamos que el archivo se encuentre.
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return 0;
    }

    copia_arc = fopen("copia.txt", "w");
    while ((c = getc(arc)) != EOF){
        //Imprimimos los caracteres hasta que se llege al final del archivo, y ademas
        // ponemos ese caracter en el archivo copia.txt.
        printf("%c", c);
        putc(c, copia_arc);
    }

    return 0;
}
