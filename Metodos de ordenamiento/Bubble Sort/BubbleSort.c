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

void BubbleSort(int array[], int lenght){
    int i, j, verification;
    for(i = 0; i < lenght; i++){
        verification = 1;
        for(j = (lenght - 1); j > i; j--){
            if(array[j] < array[j-1]){
                swap(&array[j], &array[j-1]);
                verification = 0;
            }
        }
        if(verification == 1){
            i = lenght;
        }
    }
}


int main(){
    int lenght;
    int array[10] = {5, 4, 3, 8, 9, 10, 2, 1, 20, 12};
    int *pArray;
    int verification;
    lenght = 10;
    BubbleSort(array, lenght);
    pArray = &array[0];
    readArray(pArray, lenght);
}