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

void InsertionSort(int array[], int lenght){
    int i, j; 
    for(i = 1; i < lenght; i++){
        j = i;
        while ((array[j] < array[j-1]) && (j > 0)){
            swap(&array[j], &array[j-1]);
            j--;
        }
    }
}


int main(){
    int i, j, lenght;
    int array[10] = {5, 4, 3, 8, 9, 10, 2, 1, 20, 12};
    int *pArray;
    lenght = 10;

    InsertionSort(array, lenght);
    pArray = &array[0];
    readArray(pArray, lenght);

    return 0;
}