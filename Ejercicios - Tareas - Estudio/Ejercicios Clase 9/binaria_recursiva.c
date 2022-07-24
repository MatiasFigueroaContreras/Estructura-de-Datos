// Búsqueda binaria implementación recursiva
#include <stdio.h>


int busqueda_binaria(int arreglo[], int inferior, int superior, int buscado)
{
	int indice_central;
	if (superior >= inferior) {
		indice_central = inferior + (superior - inferior) / 2;

		if (arreglo[indice_central] == buscado)
			return indice_central;

		if (arreglo[indice_central] > buscado)
			return busqueda_binaria(arreglo, inferior, indice_central - 1, buscado);

		return busqueda_binaria(arreglo, indice_central + 1, superior, buscado);
	}
	return -1;
}

int main(void)
{
	int arreglo[] = {10, 8, 6, 4, 2, 0};
	int numero_elementos = 6;
	int numero_buscado = 10;
	if (busqueda_binaria(arreglo, 0, numero_elementos - 1, numero_buscado));
		printf("El numero esta en la lista")
	else:
		printf("El numero no esta en la lista")
	return 0;
}