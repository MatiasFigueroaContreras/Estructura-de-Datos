#include <stdio.h>
#include <stdlib.h> 
// Se define un puntero a un arreglo de estructuras
struct persona *personas;
// Se define una strcutura
struct persona
{
	char nombre[30];
    int edad;
    float altura;
 };

// Función que solicita los datos para las estructuras
void lee_entrada(int n, struct persona *per){
	for (int i = 0; i < n; ++i){
		printf("\nDatos persona %d \n", i + 1);
		printf("Ingrese el nombre: \n");
		scanf("%s", per[i].nombre);
		printf("Ingrese la edad: \n");
		scanf("%i", &per[i].edad);
		printf("Ingrese la altura: \n");
		scanf("%f", &per[i].altura);
		}
	}

// Función que muestra los datos de las estructuras
void escribe_salida(int n, struct persona *per){
	for(int i = 0; i < n; ++i){
		printf("\nDatos persona: %d \n", i + 1);
		printf("\n Nombre: %s ", per[i].nombre);
		printf("\n Edad: %i ", per[i].edad);	
		printf("\n Altura: %.2f \n", per[i].altura);
	}
}


int main(void)
{
	int n;
	printf ("Ingrese el núnero de personas: ");
	scanf ( "%d", &n);
	// Se asigna memoria al arreglo de struct
	personas = (struct persona*)malloc(sizeof(struct persona) * n); 
	// invoca función 
	lee_entrada(n, personas);
	// invoca función 
	escribe_salida(n, personas);
	
	return 0;
}




