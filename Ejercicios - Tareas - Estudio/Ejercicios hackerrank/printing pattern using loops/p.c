#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int i, j, num, s, verS, z, verZ;
    verS = 0;
    s = 0;
    for(i = 0; i < 2*n - 1; i++){
        num = n;
        verZ = 0;
        z = 0;
        for(j = 0; j < 2*n - 1; j++){
            num = n - z;
            if(j == 2*n - 2 - s){
                verZ = 1;
            }
            if(verZ == 0 && z < s){
                z++;
            }
            else if(verZ == 1 && z > 0){
                z--;
            }
            printf("%d ", num);
        }
        if(s == n - 1){
            verS = 1;
        }

        if (verS == 0){
            s++;
        }
        else{
            s--;
        }
        printf("\n");
    }

    return 0;
}