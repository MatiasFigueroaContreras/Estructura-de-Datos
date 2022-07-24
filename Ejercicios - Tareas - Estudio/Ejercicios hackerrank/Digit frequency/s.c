#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%s", s);
    s = realloc(s, strlen(s) + 1);

    int *digits;
    digits = malloc(sizeof(int) * 10);
    int i, res;

    for(i = 0; i < 10; i++){
        digits[i] = 0;
    }

    
    for(i = 0; i < strlen(s); i++){
        res = s[i] - '0';
        if(res <= 9){
            digits[res]++;
        }
    }

    for(i = 0; i < 10; i++){
        printf("%d ", digits[i]);
    }
    free(s);
    free(digits);
    
    return 0;
}