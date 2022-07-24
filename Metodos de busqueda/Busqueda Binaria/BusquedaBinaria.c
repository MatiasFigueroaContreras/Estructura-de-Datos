#include <stdio.h>

int BusquedaBinaria(int *array, int start, int end, int value){
    int mid = (end + start)/2;
    if (value == *(array + mid)){
        return mid;
    }
    else if(start == end){
        return -1;
    }
    else if(value > *(array + mid)){
        BusquedaBinaria(array, mid + 1, end, value);
    }
    else if(value < *(array + mid)){
        BusquedaBinaria(array, start, mid - 1, value);
    }
} 



int main(){
    int array[10] = {1, 3, 4, 6, 7, 9, 10, 14, 15, 23};
    int pos;
    pos = BusquedaBinaria(&array[0], 0, 9, 1);
    if (pos != -1){
        printf("Numero encontrado: %d, en la posicion: %d", array[pos], pos + 1);
    }
    else{
        printf("Numero no encontrado, pos: %d", pos);
    }
    return 0;
}