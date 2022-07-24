#include <stdio.h>
#include <stdlib.h>

#define lenghtArray(A) (sizeof(A) / sizeof(int)); //Forma de sacar el largo de un arreglo

//Se define nuestro TDA conjunto con su respectivo dominio (largo y numeros/elementos).
typedef struct{
    int largo;
    int *numeros;
}conjunto;

void copyArray(int *arrayA, int *arrayB, int num_elements){
    //Esta funcion copia los datos del arreglo "elements" en un arreglo entregado junto a su longitud. 
    int i;
    for (i = 0; i < num_elements; i++){
        arrayA[i] = arrayB[i];
    }
}

void readArray(int *array, int lenght){
    //Esta funcion lee un arreglo y imprime sus elementos en un formato especifico.
    int i;
    printf("{");
    for(i = 0; i < lenght; i++){
        if (i == lenght - 1){
            printf("%i", *(array + i));
        }
        else{
            printf("%i, ", *(array + i));
        }
    }
    printf("}");
}

conjunto U(conjunto A, conjunto B){
    //Esta funcion calcula la union entre dos conjuntos, entregando asi el conjunto resultante.
    int i, j, z;
    i = 0;
    j = 0;
    z = 0;
    conjunto final;
    int *C = (int *)malloc(sizeof(int) * (A.largo + B.largo));

    while ((i < A.largo) && (j < B.largo)){
        if(A.numeros[i] == B.numeros[j]){
            C[z] = A.numeros[i];
            i++;
            j++;
        }
        else if(A.numeros[i] > B.numeros[j]){
            C[z] = B.numeros[j];
            j++;
        }
        else{
            C[z] = A.numeros[i];
            i++;
        }
        z++;
    }
    
    if(i == A.largo){
        for(j; j < B.largo; j++){
            C[z] = B.numeros[j];
            z++;
        }
    }
    else if(j == B.largo){
        for(i; i < A.largo; i++){
            C[z] = A.numeros[i];
            z++;
        }
    }

    if(z == A.largo + B.largo){
        final.largo = A.largo + B.largo;
        final.numeros = C;
        return final;
    }
    else{
        int *R = (int *)malloc(sizeof(int) * z);;
        copyArray(R, C, z);
        free(C);
        final.largo = z;
        final.numeros = R;
        return final;
    }
}

conjunto I(conjunto A, conjunto B){
    //Esta funcion calcula la interseccion entre dos conjuntos, entregando asi el conjunto resultante.
    int i, j, z;
    i = 0;
    j = 0;
    z = 0;
    conjunto final;
    int *C = (int *)malloc(sizeof(int) * (A.largo + B.largo));

    while ((i < A.largo) && (j < B.largo)){
        if(A.numeros[i] == B.numeros[j]){
            C[z] = A.numeros[i];
            i++;
            j++;
            z++;
        }
        else if(A.numeros[i] > B.numeros[j]){
            j++;
        }
        else{
            i++;
        }
    }

    if(z == A.largo + B.largo){
        final.largo = A.largo + B.largo;
        final.numeros = C;
        return final;
    }
    else{
        int *R = (int *)malloc(sizeof(int) * z);;
        copyArray(R, C, z);
        free(C);
        final.largo = z;
        final.numeros = R;
        return final;
    }
}

conjunto D(conjunto A, conjunto B){
    //Esta funcion calcula la diferencia entre dos conjuntos, entregando asi el conjunto resultante.
    int i, j, z;
    i = 0;
    j = 0;
    z = 0;
    conjunto final;
    int *C = (int *)malloc(sizeof(int) * (A.largo + B.largo));
    
    while ((i < A.largo) && (j < B.largo)){
        if(A.numeros[i] == B.numeros[j]){
            i++;
            j++;
        }
        else if(A.numeros[i] > B.numeros[j]){
            C[z] = B.numeros[j];
            j++;
            z++;
        }
        else{
            C[z] = A.numeros[i];
            i++;
            z++;
        }
    }

    if(i == A.largo){
        for(j; j < B.largo;j++){
            C[z] = B.numeros[j];
            z++;
        }
    }
    else if(j == B.largo){
        for(i; i < A.largo;i++){
            C[z] = A.numeros[i];
            z++;
        }
    }

    if(z == A.largo + B.largo){
        final.largo = A.largo + B.largo;
        final.numeros = C;        
        return final;
    }
    else{
        int *R = (int *)malloc(sizeof(int) * z);;
        copyArray(R, C, z);
        free(C);
        final.largo = z;
        final.numeros = R;
        return final;
    }

}

int main(){
    int T[3] = {1, 3, 6};
    int H[3] = {0, 1, 3};
    conjunto C;
    conjunto Z;
    conjunto X;

    conjunto A;
    conjunto B;
    int lenghtA = lenghtArray(T);
    int lenghtB = lenghtArray(H);
    A.largo = lenghtA;
    A.numeros = T;
    B.largo = lenghtB;
    B.numeros = H;
    C = U(A, B);
    Z = I(A, B);
    X = D(A, B);

    readArray(C.numeros, 4);
    printf("\n");
    readArray(Z.numeros, 2);
    printf("\n");
    readArray(X.numeros, 2);

    return 0;
}