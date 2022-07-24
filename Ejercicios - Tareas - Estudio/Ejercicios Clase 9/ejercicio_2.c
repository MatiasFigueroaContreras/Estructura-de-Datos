// Ordena alfabéticamente una lista de nombres
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Se declara un doble puntero
char **nombres;

// Función que oredena alfabéticamente cadenas
void ordenar(char **nombres, int numero_nombres, int largo_nombres){
	char temporal[largo_nombres];
	int i, j;
	for (i = 0; i < numero_nombres - 1; ++i)
		for (j = i + 1; j < numero_nombres; ++j)
			if(strcmp(nombres[i], nombres[j]) > 0) {
				strcpy(temporal, nombres[j]);
				strcpy(nombres[j], nombres[i]);
				strcpy(nombres[i], temporal);
			}
}

int main ()
{
	int i, numero_nombres, largo_nombres;
	
	printf("¿Cuantos nombres ingresara? \n");
	scanf("%i", &numero_nombres);
	printf("¿Cual sera el largo maximo de los nombres? \n");
	scanf("%i", &largo_nombres);

	// Se asigna memoria en forma dinámica
	nombres = (char **)malloc(sizeof(char *) * numero_nombres); 
	// Se asigna memoria para cada fila
	for (i = 0;i < numero_nombres; i++) 
		nombres[i] = (char *)malloc(sizeof(char) * largo_nombres); 
	
	printf("Ingrese los nombres. Cada uno en una linea\n\n");
	i = 0;
	do {
		printf("Nombre %d: ", i + 1);
		scanf("%s", nombres[i]);
	}	while (++i < numero_nombres);
	// Invoca la función con un entero y un arreglo de char
	ordenar(nombres, numero_nombres, largo_nombres);
	printf("\n\nLista de nombres ordenados: \n");
	for (i = 0; i < numero_nombres; ++i)
		printf("\n Nombre %d: %s", i + 1, nombres[i]);


	// Se libera la memoria
	for (i = 0;i < numero_nombres; i++) {
		free(nombres[i]);
	}
	free(nombres);
}