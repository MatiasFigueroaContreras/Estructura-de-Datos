#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *A = malloc(sizeof(char) * 1024);
    char *B = malloc(sizeof(char) * 1024);
    char *Res = malloc(sizeof(char) * 1024);
    scanf("%s", A);
    scanf("%s", B);
    int i = -1;
    do{
        i++;
        if(A[i] > B[i]){
            Res = A;
        }
        else if(A[i] < B[i]){
            Res = B;
        }

    }while(A[i] != B[i]);
    printf("%s", Res);


    return 0;
}