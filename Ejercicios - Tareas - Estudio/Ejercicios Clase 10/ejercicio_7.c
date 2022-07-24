// Ordenamiento por selección
// Archivos de cabecera
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
// Se declara un puntero para asignarle memoria
int *numeros;

// Función que lee un archivo, define un numeglo dinámico y retorna el número de líneas
int leer_archivo(char nom[]){
	int i, numero_lineas;
	// Se abre el archivo en modo lectura
	FILE *pt_archivo; int c = 0;
    pt_archivo = fopen(nom,"r");
    if (pt_archivo == NULL)
    {
        puts("Error: No se encontró el archivo.");
    }
	// Se lee el número de líneas 
	fscanf(pt_archivo, "%d", &numero_lineas);
	// Se asigna memoria al numeglo
	numeros = (int*)malloc(sizeof(int) * numero_lineas);
	
	// Se lee el archivo
    i = 0;
	while(i < numero_lineas){
		fscanf(pt_archivo, "%d", &numeros[i]);
		i++;
	}
	// Se cierra el archivo
	fclose(pt_archivo);
	// Retorna el número de líneas
	return numero_lineas;
}

void copyArray(int *array, int num_elements){
    int i;
    array = (int*)malloc(sizeof(int) * num_elements);
    for (i = 0; i < num_elements; i++){
        array[i] = numeros[i];
    }
}

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Función que ordena un arreglo mediante el método de inserción
void InsertionSort(int array[], int lenght,int *comparaciones){
    int i, j; 
	*comparaciones = 0;
    for(i = 1; i < lenght; i++){
        j = i;
        while ((array[j] < array[j-1]) && (j > 0)){
			(*comparaciones)++;
            swap(&array[j], &array[j-1]);
            j--;
        }
    }
}

int partitioning(int *array, int startpoint, int lenght, int *comparaciones){
    int i, j;
    int *pivot;
    j = startpoint;
    pivot = &array[lenght];
    for(i = startpoint;i < lenght;i++){
        if(array[i] <= *pivot){
			++(*comparaciones);
            swap(&array[i], &array[j]);
            j++;
        }
    }
    swap(pivot, &array[j]);
    return j;
}

void Quicksort(int *array, int startpoint, int lenght, int *comparaciones){
    int pos_pivot = 0;
    if(startpoint < lenght){
        pos_pivot = partitioning(array, pos_pivot, lenght, comparaciones);
        Quicksort(array, startpoint, pos_pivot - 1, comparaciones);
        Quicksort(array, pos_pivot + 1, lenght, comparaciones);
    }
}

void merge(int *array, int startA, int midA, int endA){
    int i = startA;
    int j = midA + 1;
    int x;
    int pos = 0;
    int lenght = endA - startA;
    int tempArray[lenght + 1];

    while ((i <= midA) && (j <= endA)){
        if (*(array + i) <= *(array + j)){
            tempArray[pos] = *(array + i);
            i++;
        }
        else{
            tempArray[pos] = *(array + j);
            j++;
        }
        pos++;
    }

    if(i == midA + 1){
        for(j; j <= endA;j++){
            tempArray[pos] = *(array + j);
            pos++;
        }
    }
    else if(j == endA + 1){
        for(i; i <= midA;i++){
            tempArray[pos] = *(array + i);
            pos++;
        }
    }

    for(x = 0; x <= lenght; x++){
        *(array + startA + x) = tempArray[x];
    }
}

void MergeSort(int *array, int startA, int endA, int *comparaciones){
    // obtenemos la mitad generando asi sub arreglos
    int midA = (endA + startA)/2;
    if (startA < endA){  // este if es el caso base
		(*comparaciones)++;
        // lado izquierdo
        MergeSort(array, startA, midA, comparaciones);
        // lado derecho
        MergeSort(array, midA + 1, endA, comparaciones);

        // se ordenan
        merge(array, startA, midA, endA);
    }
}

// Función principal 
int main(int argc, char *argv[])
{
	int i, numero_elementos;
	int comparaciones;
	time_t inicio, fin, tiempo;
	comparaciones = 0;
	numero_elementos = leer_archivo(argv[1]);

	time(&inicio);
	MergeSort(numeros, 0, numero_elementos, &comparaciones);
	time(&fin);
    tiempo = fin - inicio;

	printf("Tiempo de ordenamiento: %ld \n", tiempo);
	printf("El numero de compararaciones es: %d \n", comparaciones);

	return 0;
}
