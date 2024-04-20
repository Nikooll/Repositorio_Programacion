/**
 * @file SumaDosBinarios.c
 * @author your name (Nathaly Camacho)
 * @brief Sumar dos numeros binarios utilizando las reglas correspondientes para que se efectue la operación: 0+0=0, 0+1=1, 1+0=1, 1+1=0 y acarreo 1.
 * @version 0.1
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>  //

#define MAX_DIGITOS 100

bool esDigitoBinario(char caracter) {
    return (caracter == '0' || caracter == '1');
}

bool esNumeroBinario(char numero[]) {
    int longitud = strlen(numero);  // Calcula la longitud de una cadena de caracteres.
    for (int i = 0; i < longitud; i++) {
        if (!esDigitoBinario(numero[i])) {
            return false;
        }
    }
    return true;
}

void ajustarLongitud(char numero[], int longitudMaxima) {
    int longitud = strlen(numero);
    int diferencia = longitudMaxima - longitud;
    if (diferencia > 0) {
        memmove(numero + diferencia, numero, longitud + 1);
        memset(numero, '0', diferencia);
    }
}

void sumarBinarios(char binario1[], char binario2[], char resultado[]) {
    int longitud1 = strlen(binario1);
    int longitud2 = strlen(binario2);
    int maxLongitud = (longitud1 > longitud2) ? longitud1 : longitud2;

    ajustarLongitud(binario1, maxLongitud);
    ajustarLongitud(binario2, maxLongitud);

    int acarreo = 0;

    for (int i = maxLongitud - 1; i >= 0; i--) {
        int digito1 = binario1[i] - '0';
        int digito2 = binario2[i] - '0';
        int suma = digito1 + digito2 + acarreo;

        resultado[i] = (suma % 2) + '0';
        acarreo = suma / 2;
    }

    if (acarreo == 1) {
        memmove(resultado + 1, resultado, maxLongitud + 1);
        resultado[0] = '1';
    }
}

int main() {
    char binario1[MAX_DIGITOS + 1]; 
    char binario2[MAX_DIGITOS + 1];
    char resultado[MAX_DIGITOS + 2]; 

    do {
        printf("Ingrese el primer numero binario: ");
        fgets(binario1, sizeof(binario1), stdin);
        binario1[strcspn(binario1, "\n")] = '\0'; 
        if (!esNumeroBinario(binario1)) {
            printf("El numero que ingreso no es binario ingrese un nuevo numero\n");
        }
    } while (!esNumeroBinario(binario1));

    do {
        printf("Ingrese el segundo numero binario: ");
        fgets(binario2, sizeof(binario2), stdin);
        binario2[strcspn(binario2, "\n")] = '\0'; 
        if (!esNumeroBinario(binario2)) {
            printf("El numero que ingreso no es binario ingrese un nuevo numero\n");
        }
    } while (!esNumeroBinario(binario2));

    sumarBinarios(binario1, binario2, resultado);

    printf("La suma del primer binario %s con el segundo binario %s es: %s\n", binario1, binario2, resultado);
    printf("Gracias por usar el programa. Lindo dia");

    return 0;
}


