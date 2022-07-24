#include <stdio.h>
#include <stdlib.h>
#include "cola.c"

int main(){
    Cola newCola = crearCola();
    int i;
    for(i = 0; i <= 3; i++){
        encolar(newCola, i);
        printf("Valor pusheado: %d\n", newCola->bot->numero);
    }

    return 0;
}
