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

int partitioning(int *array, int startpoint, int lenght){
    int i, j;
    int *pivot;
    j = startpoint;
    pivot = &array[lenght];
    for(i = startpoint; i < lenght;i++){
        if(array[i] <= *pivot){
            swap(&array[i], &array[j]);
            j++;
        }
    }
    swap(pivot, &array[j]);
    return j;
}

void Quicksort(int *array, int startpoint, int lenght){
    int pos_pivot = 0;
    if(startpoint < lenght){
        pos_pivot = partitioning(array, pos_pivot, lenght);
        Quicksort(array, startpoint, pos_pivot - 1);
        Quicksort(array, pos_pivot + 1, lenght);
    }
}


int main(){
    int lenght, pos_pivot;
    int array[10] = {5, 4, 3, 8, 12, 10, 2, 1, 20, 9};
    int *pArray;
    pos_pivot = 0;
    lenght = 10;
    
    
    pArray = &array[0];
    Quicksort(pArray, 0, lenght - 1);
    readArray(pArray, lenght);

    return 0;
}