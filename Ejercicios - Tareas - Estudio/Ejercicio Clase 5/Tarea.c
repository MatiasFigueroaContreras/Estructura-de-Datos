#include <stdio.h>

void swap(int *v1, int *v2){
    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}


int main(){
    int a[10] = {12, 4, 65, 3, 23, 45, 87, 6, 9, 10};
    int *p1, i;
    p1 = &a[0];
    for(i = 0; i < 10; i++){
        printf("%d\n", *(p1 + i));
    }
    printf("\n\n");
    for(i = 0; i < 9; i++){
        if (*p1 > *(p1 + 1)){
            swap(p1, (p1+1));
        }
        p1 = p1 + 1;
    }

    for(i = 0; i < 10; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}