#include <stdio.h> 
// programa que transfiere las estructuras completas entre las funciones
struct persona
{
	char nombre[30];
    int edad;
    float altura;
 };


struct persona lee_entrada(int i){
	
	struct persona per;
	printf("\nDatos persona %d \n", i + 1);
	printf("Ingrese el nombre: \n");
	scanf("%s", per.nombre);
	printf("Ingrese la edad: \n");
	scanf("%i", &per.edad);
	printf("Ingrese la altura: \n");
	scanf("%f", &per.altura);
	return per;
	}


void escribe_salida(struct persona pr){
	printf("\n Nombre: %s ", pr.nombre);
	printf("\n Edad: %i ", pr.edad);	
	printf("\n Altura: %.2f ", pr.altura);
}


int main(void)
{
	int n;
	printf ("Ingrese el núnero de personas: ");
	scanf ( "%d", &n);
	struct persona personas[n];
	
	for (int i = 0; i < n; ++i){
		personas[i] = lee_entrada(i);
	}
	
	// Muestar datos de las personas
	for(int i = 0; i < n; ++i){
		escribe_salida(personas[i]);
	}
	return 0;
}




