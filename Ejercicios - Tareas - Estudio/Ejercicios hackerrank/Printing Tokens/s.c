#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int i, j;
    j = 0;
    char *t;
    t = malloc(1024 * sizeof(char));
    for(i = 0; i < strlen(s); i++){
        // printf("%c\n", s[i]);
        if(s[i] == ' '){
            j = 0;
            printf("%s\n", t);
            free(t);
            t = malloc(1000 * sizeof(char));
        }
        else{
            t[j] = s[i];
            j++;
        }
    }
    printf("%s", t);
    return 0;
}