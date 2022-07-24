#include <stdio.h>
#include <time.h>

unsigned int fibonacciR(num){
    if(num == 1){
        //Caso base 1
        return 1;
    }
    else if(num == 0){
        //Caso base 0
        return 0;
    }
    else{
        //Recursion hasta llegar al caso base
        return fibonacciR(num - 1) + fibonacciR(num - 2);
    }
}

unsigned int fibonacciI(num){
    int i;
    int fibi = 0;
    int fibi_1 = 1; //Caso base 1
    int fibi_2 = 0; //Caso base 0
    for(i = 2; i <= num; i++){
        fibi = fibi_1 + fibi_2; //Valor que toma el fibonacci de i
        //Cambio de valores, para pasar a calcular el fibonacci de i++
        fibi_2 = fibi_1;
        fibi_1 = fibi;
    }
    return fibi;
}

int main(){
    int i, resR, resI;
    time_t inicio, fin, tiempoR, tiempoI;
    for(i = 10; i <= 50; i += 10){
        time(&inicio);
        resR = fibonacciR(i);
        time(&fin);
        tiempoR = fin - inicio;
        time(&inicio);
        resI = fibonacciI(i);
        time(&fin);
        tiempoI = fin - inicio;
        printf("Fibonacci del numero: %i\nRespuesta: %u\nTiempo de la funcion Recursiva: %ld\nTiempo de la funcion Iterativa: %ld\n\n", i, resI, tiempoR, tiempoI);
    }
    return 0;
}
