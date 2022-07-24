#include <stdio.h>

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

void readArray(int *array, int lenght){
    int i;
    printf("{");
    for(i = 0; i < lenght; i++){
        if (i == lenght - 1){
            printf("%i", *(array + i));
        }
        else{
            printf("%i, ", *(array + i));
        }
    }
    printf("}");
}

void SelectionSort(int array[], int lenght){
    int i, j;
    int *less;
    for(i = 0; i < lenght; i++){
        less = &array[i];
        j = i + 1;
        for(j; j < lenght; j++){
            if(*less > array[j]){
                less = &array[j];
            }
        }
        if (*less != array[i]){
            swap(less, &array[i]);
        }
    }

}


int main(){
    int lenght;
    // int array[8] = {49, 70, 23, 73, 5, 8, 38, 13};
    // int array[8] = {11, 13, 24, 35, 47, 58, 59, 80};
    int array[8] = {10, 9, 8, 7, 6, 5, 4, 2};
    int *pArray;
    lenght = 8;

    SelectionSort(array, lenght);
    pArray = &array[0];
    readArray(pArray, lenght);
}
