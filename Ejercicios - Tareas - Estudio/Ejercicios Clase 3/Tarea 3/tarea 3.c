#include <stdio.h>

int main(){
    int cantidad;
    printf("Ingrese el tamaño de el rut sin contar el digito verificador: ");
    scanf("%d", &cantidad);
    
    int arrayR[cantidad], multipicador, acum, x, resto, digitoV;
    for(int i = 0; i < cantidad; i++){
        //Con este for se busca almacenar los valores que tendra el arreglo.
        printf("Ingrese el caracter del rut (considerelo de izquierda a derecha): ");
        scanf("%d", &arrayR[i]);
    }
    multipicador = 2;
    acum = 0;
    for(x = cantidad - 1; x >= 0;x--){
        acum += arrayR[x] * multipicador;
        multipicador++;
        if (multipicador > 7){
            multipicador = 2;
        }
    }
    resto = acum % 11;
    digitoV = 11 - resto;
    if(digitoV == 11){
        digitoV = 0;
        printf("El digito verificador es: %d", digitoV);
    }
    else if(digitoV == 10){
        printf("El digito verificador es: %c", 'k');
    }
    else{
        printf("El digito verificador es: %d", digitoV);
    }

    return 0;
}
