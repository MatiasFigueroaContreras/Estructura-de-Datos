// Ordena alfabéticamente una lista de nombres
 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Función que oredena alfabéticamente cadenas
void ordenar(int n, char nombres[] [30]){
	char temporal[30];
	int i, j;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; j < n; ++j)
			if(strcmp(nombres[i], nombres[j]) > 0) {
				strcpy(temporal, nombres[j]);
				strcpy(nombres[j], nombres[i]);
				strcpy(nombres[i], temporal);
			}
}

int main ()
{
	int i, n = 0;
	char nombres[11][30];

	printf("Ingrese a lo mas diez nombres. Cada uno en una linea\n\n");
	printf ( "Escriba \'FIN\' para terminar\n \n");
	do {
		printf("Nombre %d: ", n + 1);
		scanf("%s", nombres[n]);
	}	while (strcmp(nombres[n++], "FIN"));
	n--;
	// Invoca la función para ordenar con un entero y un arreglo de char
	ordenar(n, nombres);
	printf("\n\nLista de nombres ordenados: \n");
	for (i = 0; i < n; ++i)
		printf("\n Nombre %d: %s", i + 1, nombres[i]);
}

