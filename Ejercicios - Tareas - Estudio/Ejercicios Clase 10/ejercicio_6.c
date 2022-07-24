// Ordenamiento por selección
// Archivos de cabecera
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
// Se declara un puntero para asignarle memoria
int *numeros;

// Función que lee un archivo, define un arreglo dinámico y retorna el número de líneas
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
	// Se asigna memoria al arreglo
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


// Función que ordena un arreglo mediante el método de selección
void ordenamiento_seleccion(int *num, int n, int *comparaciones)
{
	int i, j, minimo, aux;
	*comparaciones = 0;
	for (i = 0; i < n - 1; i++)
	{
		minimo = i;
		for (j = i + 1; j < n; j++){
			++(*comparaciones);
			if (num[j] < num[minimo])
				minimo = j;
		}
		if (i != minimo){
			aux = num[i];
			num[i] = num[minimo];
			num[minimo] = aux;
			
		}
	}
}



// Función principal 
int main(int argc, char *argv[])
{
	int i, numero_elementos;
	int comparaciones;
	time_t inicio, fin, tiempo;

	numero_elementos = leer_archivo(argv[1]);

	time(&inicio);
	ordenamiento_seleccion(numeros, numero_elementos, &comparaciones);
	time(&fin);
    tiempo = fin - inicio;

	printf("Tiempo de ordenamiento: %ld \n", tiempo);
	printf("El numero de compararaciones es: %d \n", comparaciones);

	return 0;
}
