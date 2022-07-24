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

void merge(int *array, int startA, int midA, int endA){
    int i = startA;
    int j = midA + 1;
    int x;
    int pos = 0;
    int length = endA - startA;
    int tempArray[length + 1];

    while ((i <= midA) && (j <= endA)){
        if (*(array + i) <= *(array + j)){
            tempArray[pos] = *(array + i);
            i++;
        }
        else{
            tempArray[pos] = *(array + j);
            j++;
        }
        pos++;
    }

    if(i == midA + 1){
        for(j; j <= endA;j++){
            tempArray[pos] = *(array + j);
            pos++;
        }
    }
    else if(j == endA + 1){
        for(i; i <= midA;i++){
            tempArray[pos] = *(array + i);
            pos++;
        }
    }

    for(x = 0; x <= length; x++){
        *(array + startA + x) = tempArray[x];
    }
}

void MergeSort(int *array, int startA, int endA){
    // obtenemos la mitad generando asi sub arreglos
    int midA = (endA + startA)/2;
    if (startA < endA){  // este if es el caso base
        // lado izquierdo
        MergeSort(array, startA, midA);
        // lado derecho
        MergeSort(array, midA + 1, endA);

        // se ordenan
        merge(array, startA, midA, endA);
    }
}

int main(){
    int length;
    int array[10] = {5, 4, 3, 8, 12, 10, 2, 1, 20, 9};
    int *pArray;
    length = 10;
    
    pArray = &array[0];
    MergeSort(pArray, 0, length - 1);
    readArray(pArray, length);

    return 0;
}
