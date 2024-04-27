

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
