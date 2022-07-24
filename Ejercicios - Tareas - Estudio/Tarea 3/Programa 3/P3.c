#include <stdio.h>

float potencia(float a, float b){
    //Funcion que calcula la potencia entre dos numeros.
    float c, i;
    c = 1;
    if(b >= 1){
        for(i = 1; i <= b; i++){
        c *= a;
        }
    }
    else if(b < 0){
        for(i = -1; i >= b; i--){
        c *= 1/a;
        }
    }
    else{
    }
    return c;
}

float division(float a, float b){
    //Funcion que calcula la division entre dos numeros.
    float c;
    c = a/b;
    return c;
}

unsigned int fibonacciI(num){
    //Funcion para calcular el Fibonacci de un numero retornando este como valor.
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

void fillArray(int array[], int lenght){
    //Funcion que le pregunta al usuario que valores quiere asignarle a su arreglo, para almacenarlos en este. 
    int i;
    for (i = 0; i < lenght; i++){
        printf("Ingrese el valor del arreglo con pos n%i: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int elementosMayores(int array[], int lenght, int valor){
    //Funcion que revisa en un arreglo cuantos elementos mayores a un valor hay.
    int i, res;
    res = 0;
    for(i = 0; i < lenght; i++){
        if (valor < array[i]){
            res++;
        }
    }
    return res;
}

float promedioArray(int *array, int lenght){
    //Funcion que suma los elementos de un arreglo y luego lo divide en la cantidad, para asi retornar el promedio.
    int i, res;
    res = 0;
    for(i = 0; i < lenght; i++){
        res += *(array + i);
    }
    res = res / lenght;

    return res;
}

void par_impar(int array[], int lenght){
    //Funcion que verifica si los elementos de un arreglo son par o impar y muestra por pantalla para cada posicion/valor.
    int i, res;
    for(i = 0; i < lenght; i++){
        switch (array[i] % 2){
        case 0:
            printf("El elemento: %d, en la posicion %i es PAR\n", array[i], i + 1);
            break;
        case 1:
            printf("El elemento: %d, en la posicion %i es IMPAR\n", array[i], i + 1);
            break;
        }
    }
}

int main(){
    float a, b, res1, res2;
    int res3, ver;
    printf("Ingrese el valor de a: ");
    scanf("%f", &a);
    printf("Ingrese el valor de b: ");
    scanf("%f", &b);
    //Parte 1.
    res1 = potencia(a, b);
    res2 = division(a, b);

    printf("\nEl resultado de a^b es: %.4f\n", res1);
    printf("El resultado de a/b es: %.4f\n", res2);

    //Parte 2.
    if (a > b){
        ver = b;
    }
    else{
        ver = a;
    }
    res3 = fibonacciI(ver);
    printf("\nEl valor menor de la serie de fibonacci es para el valor %d y es: %u\n", ver, res3);

    //Parte 3.
    int array[20];
    int valor, res4;
    float res5;
    printf("\nIngrese los valores de su arreglo a continuacion:\n");
    fillArray(array, 20);

    printf("\nIngrese el valor para el cual desa saber cuantos valores mayores existen: ");
    scanf("%d", &valor);
    res4 = elementosMayores(array, 20, valor);
    printf("\nLa cantidad de elementos mayores a %d es: %d\n", valor, res4);

    res5 = promedioArray(&array[0], 20);
    printf("\nEl promedio de los elementos del arreglos es: %.2f\n", res5);

    printf("\nElementos par o impar del arreglo:\n\n");
    par_impar(array, 20);

    return 0;
}
