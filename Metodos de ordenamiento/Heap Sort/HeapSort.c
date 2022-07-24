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

int pair(int num){
    int rest;
    rest = num % 2;
    if(rest == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// int buildHeap(int *array, int lenght){
//     int verification, i;
//     do{
//         verification = 1;
//         for (i = 0; i < lenght; i++){
//             if (array[i] < array[(2*i + 1)]){
//                 swap(&array[i], &array[(2*i + 1)]);
//                 verification = 0;
//             }
//             if (array[i] < array[(2*i + 2)]){
//                 swap(&array[i], &array[(2*i + 2)]);
//                 verification = 0;
//             }
//         }
//     }while(verification == 0);
// }


void buildHeap(int *array, int lenght){
    int verification, i;
    int numi;
    numi = (lenght - 1) / 2;
    do{
        verification = 1;
        for (i = 0; i <= numi; i++){
            if (*(array + i) < *(array + (2*i + 1))){
               swap((array + i), array + (2*i + 1));
               verification = 0;
            }
            if ((pair(lenght) != 0) || (i != numi)){
                if (*(array + i) < *(array + (2*i + 2))){
                    swap((array + i), array + (2*i + 2));
                    verification = 0;
                }
            }
        }
    }while(verification == 0);
}

void HeapSort(int *array, int lenght){
    int i, top;
    for(i = 0; i < lenght; i++){
        top = lenght - i;
        buildHeap(array, top);
        swap((array + top), array);
    }
}

int main(){
    int lenght;
    int array[14] = {5, 4, 3, 8, 12, 10, 2, 1, 20, 9, 100, 8, 7, 6};
    int *pArray;
    lenght = 14;
    
    pArray = &array[0];
    HeapSort(pArray, lenght - 1);
    readArray(pArray, lenght);

    return 0;
}
