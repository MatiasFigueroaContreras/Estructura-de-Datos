#include <stdio.h>

int main(){
    int cantidad;
    
    do{
        //Con este do while se busca que el usuario ingrese 2 como minimo en el tamaño
        // del arreglo para evitar errores y que el ejercicio tenga sentido.
        printf("Ingrese el tamaño de el arreglo (minimo 2): ");
        scanf("%d", &cantidad);
    } while(cantidad <= 1);

    int arrayA[cantidad], mayor, menor, promedio;
    for(int i = 0; i < cantidad; i++){
        //Con este for se busca almacenar los valores que tendra el arreglo.
        printf("Ingrese el valor a almacenar en el arreglo A: ");
        scanf("%d", &arrayA[i]); 
    }

    //El siguiente conjunto de if-else, busca dar un punto de partida al siguiente for
    // y asi tener valores definidos.
    if (arrayA[0] > arrayA[1]){
        mayor = arrayA[0];
        menor = arrayA[1];
    }
    else{
        mayor = arrayA[1];
        menor = arrayA[0];
    }

    promedio = arrayA[0] + arrayA[1];
    for(int x = 2; x < cantidad; x++){
        //Con este for se busca encontrar el mayor, y el menor numero, y ademas sumar los
        // valores que se encuentran en el arreglo, para luego sacar el promedio de estos.
        if(mayor < arrayA[x]){
            mayor = arrayA[x];
        }
        else if(menor > arrayA[x]){
            menor = arrayA[x];
        }
        promedio += arrayA[x];
    }
    promedio = promedio / cantidad;

    printf("El numero mayor del arreglo es: %d\nEl numero menor es: %d\nMientras que el promedio es: %d", mayor, menor, promedio);
    return 0;
}