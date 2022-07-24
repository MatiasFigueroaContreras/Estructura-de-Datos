#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variable-Puntero global
int *elements;

int readFile(char name_file[]){
    //Esta funcion lee los datos de un archivo (entrada) y los guarda en un arreglo, y retorna la cantidad
    // de elementos que fueron guardados
    int i, num_elements;
    FILE *rFile;

    rFile = fopen(name_file, "r");
    if (rFile == NULL){
        //Nos aseguramos que el archivo se encuentre
        printf("Error al abrir el archivo, porfavor verifique el nombre.");
        return 0;
    }

    fscanf(rFile, "%d", &num_elements);

    elements = (int *)malloc(sizeof(int) * num_elements); //Asignamos la memoria para nuestro arreglo

    for(i = 0; i < num_elements; i++){
        //Leemos el archivo y guardamos los datos en el arreglo
        fscanf(rFile, "%d", &elements[i]);
    }
    
    fclose(rFile);

    return num_elements;
}

void writeArray(char name_file[], int *array, int num_elments){
    //Esta funcion escribe los datos de un arreglo en un archivo (en este caso sirve para verificar que los datos del arreglo son los deseados)
    int i;
    FILE *wFile;
    wFile = fopen(name_file, "w");
    fprintf(wFile, "A continuacion se encuentran los %d datos ordenados:\n", num_elments);
    for(i = 0; i < num_elments; i++){
        fprintf(wFile, "%d\n", array[i]);
    }

}

void copyArray(int *array, int num_elements){
    //Esta funcion copia los datos del arreglo "elements" en un arreglo entregado junto a su longitud. 
    int i;
    for (i = 0; i < num_elements; i++){
        array[i] = elements[i];
    }
}

void swap(int *A, int *B){
    //Esta funcion hace un swap de elementos (sirve para los metodos de ordenamiento a continuacion)
    int temp = *A;
    *A = *B;
    *B = temp;
}

//////////////////////////////
///Metodos de ordenamiento///
////////////////////////////

//InsertionSort
void InsertionSort(int array[], int lenght, int *comparaciones, int *swaps){
    int i, j; 
    for(i = 1; i < lenght; i++){
        j = i;
        (*comparaciones)++; //Una comparacion segura cada vez que pregunta la condicion del while
        while ((array[j] < array[j-1]) && (j > 0)){
            if(j != i){
                //Este if verifica que si entra por primera vez al while este no sume una comparacion de mas,
                // ya que este fue contado anteriormente, en otro caso empieza a contar todas las iteraciones(comparaciones)
                // que se estan haciendo
                (*comparaciones)++;
            }
            swap(&array[j], &array[j-1]);
            (*swaps)++;
            j--;
        }
    }
}
//End InsertionSort

//QuickSort
int partitioning(int *array, int startpoint, int lenght, int *comparaciones, int *swaps){
    int i, j;
    int *pivot;
    j = startpoint;
    pivot = &array[lenght];
    for(i = startpoint;i < lenght;i++){
        (*comparaciones)++; //+1 Comparacion por cada ves que pasa por el if
        if(array[i] <= *pivot){
            swap(&array[i], &array[j]);
            (*swaps)++;
            j++;
        }
    }
    swap(pivot, &array[j]);
    (*swaps)++;
    return j;
}

void QuickSort(int *array, int startpoint, int lenght, int *comparaciones, int *swaps){
    int pos_pivot = 0;
    if(startpoint < lenght){
        pos_pivot = partitioning(array, pos_pivot, lenght, comparaciones, swaps);
        QuickSort(array, startpoint, pos_pivot - 1, comparaciones, swaps);
        QuickSort(array, pos_pivot + 1, lenght, comparaciones, swaps);
    }
}
//End QuickSort

//MergeSort
void merge(int *array, int startA, int midA, int endA, int *comparaciones){
    int i = startA;
    int j = midA + 1;
    int x;
    int pos = 0;
    int lenght = endA - startA;
    int tempArray[lenght + 1];

    while ((i <= midA) && (j <= endA)){
        (*comparaciones)++; //+1 Comparacion por cada vez que pasa por el if/else
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
        // lado izquierdo
        MergeSort(array, startA, midA, comparaciones);
        // lado derecho
        MergeSort(array, midA + 1, endA, comparaciones);
        // se ordenan
        merge(array, startA, midA, endA, comparaciones);
    }
}
// End MergeSort

// HeapSort
int pair(int num){
    int rest;
    rest = num % 2;
    if(rest == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void buildHeap(int *array, int lenght, int *comparaciones, int *swaps){
    int verification, i;
    int numi;
    numi = (lenght - 1) / 2;
    do{
        verification = 1;
        for (i = 0; i <= numi; i++){
            (*comparaciones)++; //+1 Comparacion de arreglos por el if 
            if (*(array + i) < *(array + (2*i + 1))){
                swap((array + i), array + (2*i + 1));
                (*swaps)++;
                verification = 0;
            }
            if ((pair(lenght) != 0) || (i != numi)){
                (*comparaciones)++; //+1 Comparacion de arreglos por el if
                if (*(array + i) < *(array + (2*i + 2))){
                    swap((array + i), array + (2*i + 2));
                    (*swaps)++;
                    verification = 0;
                }
            }
        }
    }while(verification == 0);
}

void HeapSort(int *array, int lenght, int *comparaciones, int *swaps){
    int i, top;
    for(i = 0; i < lenght; i++){
        top = lenght - i;
        buildHeap(array, top, comparaciones, swaps);
        swap((array + top), array);
        (*swaps)++;
    }
}
//End HeapSort

//BubbleSort
void BubbleSort(int array[], int lenght, int *comparaciones, int *swaps){
    int i, j, verification;
    for(i = 0; i < lenght; i++){
        verification = 1;
        for(j = (lenght - 1); j > i; j--){
            (*comparaciones)++; //+1 Comparacion de arreglos por el if
            if(array[j] < array[j-1]){
                swap(&array[j], &array[j-1]);
                (*swaps)++;
                verification = 0;
            }
        }
        if(verification == 1){
            i = lenght;
        }
    }
}
//End BubbleSort

//SelectionSort
void SelectionSort(int array[], int lenght, int *comparaciones, int *swaps){
    int i, j;
    int *less;
    for(i = 0; i < lenght; i++){
        less = &array[i];
        j = i + 1;
        for(j; j < lenght; j++){
            (*comparaciones)++;
            if(*less > array[j]){
                less = &array[j];
            }
        }
        if (*less != array[i]){
            swap(less, &array[i]);
            (*swaps)++;
        }
    }

}
//End SelectionSort
//Final metodos de ordenamiento

//////////////////////////
///Metodos de busqueda///
////////////////////////

//Todos los metodos retornan la posicion contando desde el valor 0, y por el contrario si 
// no se encuentra retorna el valor de -1, ademas trabajan buscando en arreglos.

//Busqueda con datos ordenados
//Busqueda Binaria
int BusquedaBinaria(int *array, int start, int end, int value){
    int mid = (end + start)/2;
    if (value == *(array + mid)){
        return mid;
    }
    else if(start == end){
        return -1;
    }
    else if(value > *(array + mid)){
        BusquedaBinaria(array, mid + 1, end, value);
    }
    else if(value < *(array + mid)){
        BusquedaBinaria(array, start, mid - 1, value);
    }
}

//Busqueda lineal
int BusquedaLinealOrdenanda(int *array, int lenght, int value){
    int i;
    for(i = 0; i < lenght; i++){
        if (*(array + i) == value){
            return i;
        }
        else if (*(array + i) > value){
            return -1;
        }
    }
    return -1;
}


//Busqueda con datos no ordenados
//Busqueda lineal
int BusquedaLineal(int *array, int lenght, int value){
    int i;
    for(i = 0; i < lenght; i++){
        if (*(array + i) == value){
            return i;
        }
    }
    return -1;
}
//Final metodos de busqueda

void print_out(char metodo[],int comparaciones, int swaps, int tiempo){
    //Funcion que retroalimenta con los valores de comparaciones, intercambios y tiempo asociados a un metodo de ordenamiento.
    printf("\nPara el metodo de ordenamiento %s:\n", metodo);
    printf("El numero de comparaciones son: %lu\n", comparaciones);
    printf("El numero de intercambios son: %lu\n", swaps);
    printf("El tiempo de ejecucion es: %ld\n", tiempo);
}

int main(int argc, char *name_file[]){
    if(argc != 2){
        //Ya que argc contiene el numero de elementos que ingreso el usuario al momento de partir el
        // programa, con este if verificamos que este efectivamente haya ingresado el nombre del archivo
        printf("Asegurese de ingresar el nombre del archivo con el que se va a trabajar.");
        return 0;
    }

    int num_elements, pos, valor;
    time_t inicio, fin, tiempo;
    //Ya que los valores de las comparaciones e intercambios van a ser positivos(unsigned) y pueden llegar a ser muy grandes(long),
    // se usara unsigned long int para tener asi disponible una mayor cantidad de bits en memoria para guardar los valores.
    unsigned long int comparaciones; 
    unsigned long int swaps;
    int *array;
    
    num_elements = readFile(name_file[1]);

    //Calculos para los distintos tipos de ordenamiento:

    //InsertionSort
    array = (int*)malloc(sizeof(int) * num_elements); //Asignamos la memoria para nuestro arreglo
    copyArray(array, num_elements);
    //Se reinicia el conteo de comparaciones e intercambios
    comparaciones = 0;
    swaps = 0;
    //Con time calculamos el tiempo que se demora el algoritmo en ordenar
    time(&inicio);
    InsertionSort(array, num_elements, &comparaciones , &swaps);
    time(&fin);
    tiempo = fin - inicio;
    print_out("InsertionSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_InsertionSort.txt", array, num_elements); //No es necesario!, pero sirve para verificar que el metodo de ordenamiento funciona
    free(array);  //Liberamos la memoria del arreglo para poder usarla mas adelante


    //QuickSort
    array = (int*)malloc(sizeof(int) * num_elements);
    copyArray(array, num_elements);
    comparaciones = 0;
    swaps = 0;
    time(&inicio);
    QuickSort(array, 0, num_elements - 1, &comparaciones, &swaps);
    time(&fin);
    tiempo = fin - inicio;
    print_out("QuickSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_QuickSort.txt", array, num_elements);
    free(array);


    //MergeSort
    array = (int*)malloc(sizeof(int) * num_elements);
    copyArray(array, num_elements);
    comparaciones = 0;
    swaps = 0;
    time(&inicio);
    MergeSort(array, 0, num_elements - 1, &comparaciones);
    time(&fin);
    tiempo = fin - inicio;
    print_out("MergeSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_MergeSort.txt", array, num_elements);
    free(array);


    //HeapSort
    array = (int*)malloc(sizeof(int) * num_elements);
    copyArray(array, num_elements);
    comparaciones = 0;
    swaps = 0;
    time(&inicio);
    HeapSort(array, num_elements - 1, &comparaciones, &swaps);
    time(&fin);
    tiempo = fin - inicio;
    print_out("HeapSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_HeapSort.txt", array, num_elements);
    free(array);


    //BubbleSort
    array = (int*)malloc(sizeof(int) * num_elements);
    copyArray(array, num_elements);
    comparaciones = 0;
    swaps = 0;
    time(&inicio);
    BubbleSort(array, num_elements, &comparaciones, &swaps);
    time(&fin);
    tiempo = fin - inicio;
    print_out("BubbleSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_BubbleSort.txt", array, num_elements);
    free(array);


    //SelectionSort
    array = (int*)malloc(sizeof(int) * num_elements);
    copyArray(array, num_elements);
    comparaciones = 0;
    swaps = 0;
    time(&inicio);
    SelectionSort(array, num_elements, &comparaciones, &swaps);
    time(&fin);
    tiempo = fin - inicio;
    print_out("SelectionSort", comparaciones, swaps, tiempo);
    writeArray("DatosO_SelectionSort.txt", array, num_elements);
    

    // Busqueda de un valor con datos ordenados:
    printf("\n\nIngrese el valor que desea buscar: ");
    scanf("%d", &valor);

    //Busqueda Binaria
    time(&inicio);
    pos = BusquedaBinaria(array, 0, num_elements, valor);
    time(&fin);
    tiempo = fin - inicio;
    printf("\n\nPara la busqueda Binaria: ");
    printf("\nLa posicion del elemento buscado es: %d\n", pos + 1);
    printf("El tiempo de ejecucion es: %ld\n", tiempo);
    

    //Busqueda Lineal Ordenada
    time(&inicio);
    pos = BusquedaLinealOrdenanda(array, num_elements, valor);
    time(&fin);
    tiempo = fin - inicio;
    printf("\nPara la busqueda Lineal: ");
    printf("\nLa posicion del elemento buscado es: %d\n", pos + 1);
    printf("El tiempo de ejecucion es: %ld\n", tiempo);
    
    free(array); //Se libera la memoria del arreglo que fue usado para ocupar los metodos de busqueda

    free(elements); //Liberamos la memoria del arreglo

    return 0;
}
