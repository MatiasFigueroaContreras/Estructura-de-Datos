//1. Crear un programa que lea un archivo de entrada con números (uno por cada línea) y escriba un archivo de salida con la suma de estos números 
#include <stdio.h>

int main(){
    char name_ar[100];
    int num, suma;
    FILE * arc;
    FILE * suma_arc;

    printf("Ingrese el nombre de su archivo: ");
    scanf("%s", name_ar);

    arc = fopen(name_ar, "r");
    if (arc == NULL){
        //Verificamos que el archivo se encuentre.
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return 0;
    }
    suma = 0;
    while ((fscanf(arc, "%d", &num)) != EOF){
        //Sumamos cada numero que se encuentra en el archivo hasta llegar al final de este.
        suma += num;
    }
    suma_arc = fopen("suma_num.txt", "w");
    fprintf(suma_arc, "El resultado de la suma es: %d", suma);

    return 0;
}
