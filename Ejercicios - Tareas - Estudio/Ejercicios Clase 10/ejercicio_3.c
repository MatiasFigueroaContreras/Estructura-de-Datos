// Ordena alfabéticamente una lista de nombres de un archivo
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>

// Se declara un doble puntero
char **nombres;

// Función que oredena alfabéticamente cadenas
void leer_archivo(char nom[], int *n_lineas, int *max_nombre){
	// Inicializan variables
    *n_lineas = 0;
	*max_nombre = 0;
	int i, l_nombre = 0;
	// Se abre el archivo en modo lectura
	FILE *pt_archivo; int c = 0;
    pt_archivo = fopen(nom,"r");
    if (pt_archivo == NULL)
    {
        puts("Error: No se encontró el archivo.");
    }
	// Se cuenta el número de líneas y el número de caracteres del nombre de mayor largo
    while((c = fgetc(pt_archivo)) != EOF){
		++l_nombre;
        if( c == '\n'){
            ++(*n_lineas);
			if(l_nombre > *max_nombre){
				*max_nombre = l_nombre;
			}
			l_nombre = 0;
		}
    }
	++(*n_lineas);
	// Se asigna memoria en forma dinámica
	nombres = (char **)malloc(sizeof(char *) * (*n_lineas)); 
	// Se asigna memoria para cada fila
	for (i = 0;i < *n_lineas; i++) 
		nombres[i] = (char *)malloc(sizeof(char) * (*max_nombre)); 
	// Se vuelve a al inicio del archivo
    rewind(pt_archivo);
	// Se leen los nombres desde el archivo y se almacenan en el arreglo nombres
	i = 0;
	while(i < *n_lineas){
		fscanf(pt_archivo, "%s", nombres[i]);
		++i;			
	}
	// Se cierra el archivo
	fclose(pt_archivo);
}

// Función que oredena alfabéticamente los nombres
void ordenar(int numero_nombres, int largo_nombres){
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


int main(int argc, char *argv[])
{
	int i, numero_nombres, largo_nombres;
	char archivo[30];
	strcpy(archivo, argv[1]);
	// Lee nombres desde un archivo y los almacena en un arreglo dinámico 
	leer_archivo(archivo, &numero_nombres, &largo_nombres);
	
	// Invoca la función con dos enteros y un nombres de char
	ordenar(numero_nombres, largo_nombres);

	printf("\n\nLista de nombres ordenados: \n");
	for (i = 0; i < numero_nombres; ++i)
		printf("\n Nombre %d: %s", i + 1, nombres[i]);

	// Se libera la memoria
	for (i = 0;i < numero_nombres; i++) {
		free(nombres[i]);
	}
	free(nombres);

	return 0;
}

