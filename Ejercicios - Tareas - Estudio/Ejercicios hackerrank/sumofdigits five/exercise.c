#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum = 0;
    int digit;
    int i;
    for(i = n; i > 0; i = i / 10){
        digit = i % 10;
        sum += digit;
    }
    printf("%d\n", sum);
    return 0;
}