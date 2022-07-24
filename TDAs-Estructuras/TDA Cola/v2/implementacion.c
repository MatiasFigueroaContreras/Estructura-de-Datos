#include <stdio.h>
#include <stdlib.h>
#include "cola.c"

int main(){
    Cola newCola = crearCola();
    int i;
    for(i = 0; i <= 3; i++){
        encolar(newCola, i);
        printf("Valor encolado: %d\n", elemBot(newCola));
    }
    printf("\n\n");
    for(i = 0; i <= 3; i++){
        printf("Valor desencolado: %d\n", elemTop(newCola));
        desencolar(newCola);
    }

    return 0;
}
