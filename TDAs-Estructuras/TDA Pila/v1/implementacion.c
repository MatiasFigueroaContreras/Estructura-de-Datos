#include <stdio.h>
#include <stdlib.h>
#include "pila.c"

int main(){
    Pila newPila = crearPila();
    Pila newNodo;
    int i;
    // for(i = 0; i <= 3; i++){
    //     newNodo = crearNodo(i);
    //     push(newPila, newNodo);
    //     printf("Valor pusheado: %d\n", newPila->siguiente->numero);
    // }
    for(i = 0; i <= 3; i++){
        push(newPila, i);
        printf("Valor pusheado: %d\n", newPila->siguiente->numero);
    }
    printf("\n\n");
    int popedValue;
    for(i = 0; i <= 5; i++){
        printf("1.Valor n%i popeado: %d\n", i + 1, newPila->siguiente->numero);
        popedValue = pop(newPila);
        printf("2.Valor n%i popeado: %d\n", i + 1, popedValue);
        
    }
}