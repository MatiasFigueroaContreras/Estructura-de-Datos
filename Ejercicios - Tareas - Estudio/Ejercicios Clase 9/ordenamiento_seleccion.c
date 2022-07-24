// Ordenamiento por selección
#include <stdio.h>

void ordenamiento_seleccion(int arreglo[], int n)
{
	int i, j, minimo, aux;
	for (i = 0; i < n - 1; i++)
	{
		minimo = i;
		for (j = i + 1; j < n; j++)
			if (arreglo[j] < arreglo[minimo])
				minimo = j;

		if (i != minimo){
			aux = arreglo[i];
			arreglo[i] = arreglo[minimo];
			arreglo[minimo] = aux;
		}
	}
}


/* Muestra el arreglo*/
void mostrar_arreglo(int arreglo[], int elementos)
{
	int i;
	for (i=0; i < elementos; i++)
		printf("%d ", arreglo[i]);
	printf("\n");
}

// 
int main()
{
	int arreglo[] = {10, 8, 6, 4, 2, 0};
	int numero_elementos = 6;
	ordenamiento_seleccion(arreglo, numero_elementos);
	mostrar_arreglo(arreglo, numero_elementos);
	return 0;
}
