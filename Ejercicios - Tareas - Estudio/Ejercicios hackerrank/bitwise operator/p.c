#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    //Write your code here.
    int i, j;
    int rAnd, rOr, rXor;
    int maxAnd, maxOr, maxXor;
    maxAnd = 0;
    maxOr = 0;
    maxXor = 0;
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            rAnd = i & j;
            rOr = i | j;
            rXor = i ^ j;
            if(rAnd < k && rAnd > maxAnd){
                maxAnd = rAnd;
            }
            if(rOr < k && rOr > maxOr){
                maxOr = rOr;
            }
            if(rXor < k && rXor > maxXor){
                maxXor = rXor;
            }
        }
    }
    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
