/**
 * @file AlumnosMayorEdad.c
 * @author your name ( Nikooll)
 * @brief Saber la cantidad de alumnos que son mayores de edad 
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{

    system("@cls||clear");
    
    int contador_mayores = 0;
    int contador_estudiantes = 0;
    int total_estudiantes;
    int edad;
    

    printf("Ingrese el total de estudiantes que existan en el aula: ");
    scanf("%d", &total_estudiantes);

    while (contador_estudiantes < total_estudiantes) {
        
        printf("Ingrese la edad del estudiante: ");
        scanf("%d", &edad);

        if (edad >= 18) {
            contador_mayores++;
        }

        contador_estudiantes++;
    }

    printf("La cantidad de estudiantes mayores de edad es: %d\n", contador_mayores);
    printf("Gracias por usar nuestro programa, vuelva pronto!!\n");

    return 0;
}
