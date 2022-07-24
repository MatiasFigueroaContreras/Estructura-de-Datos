#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i, sum;
    
    scanf("%d", &n);
    int *arr = (int *)(malloc(sizeof(int) * n));
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    sum = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
    }
    free(arr);
    printf("%d", sum);
    
    
    return 0;
}