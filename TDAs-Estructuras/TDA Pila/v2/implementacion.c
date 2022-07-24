#include <stdio.h>
#include <stdlib.h>
#include "pila.c"

int main(){
    Pila newPila = crearPila();
    int i;
    for(i = 0; i <= 3; i++){
        push(newPila, i);
        printf("Valor pusheado: %d\n", newPila->top->numero);
    }
    printf("\n\n");
    int popedValue;
    for(i = 0; i <= 3; i++){
        printf("Valor n%i popeado: %d\n", i + 1, elemTop(newPila));
        pop(newPila);
    }
    if(elemTop(newPila) != NULL){
        printf("NO NULO, valor: %d", elemTop(newPila)); 
        
    }
    else{
       printf("NULO");
    }

    return 0;
}