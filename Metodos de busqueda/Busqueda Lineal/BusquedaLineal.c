#include <stdio.h>

int BusquedaLineal(int *array, int lenght, int value){
    int i;
    for(i = 0; i < lenght; i++){
        if (*(array + i) == value){
            return i;
        }
    }
    return -1;
}

int BusquedaLinealOrdenanda(int *array, int lenght, int value){
    int i;
    for(i = 0; i < lenght; i++){
        if (*(array + i) == value){
            return i;
        }
        else if (*(array + i) > value){
            return -1;
        }
    }
    return -1;
}



int main(){
    int array[10] = {1, 3, 4, 6, 7, 9, 10, 14, 15, 23};
    int pos;
    pos = BusquedaLineal(&array[0], 10, 1);
    printf("Numero encontrado: %d, en la posicion: %d", array[pos], pos + 1);
    return 0;
}