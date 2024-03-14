#include <stdio.h>

#define CANT_MAX 5

typedef struct{
    char name[999];
    int age;
    float salary;
}empleado_t;


void mostrar_datos(empleado_t empleados[], int cantidad, float avg, float max_salary, int max_name){
    printf("\n\n--- Información de empleados ---");
    for (int i=0; i<=cantidad; i++){
        printf("\nNombre: %s, Edad: %i, Salario: $%f", empleados[i].name, empleados[i].age, empleados[i].salary);
    }
    printf("\n\nEl promedio de salarios es: $%f.\n%s tiene el salario más alto cobrando $%f.\n\n", avg, empleados[max_name].name, max_salary);
}


float procesar_datos(empleado_t empleados[CANT_MAX], int cantidad){
    float avg = 0;
    int max_name = 0;
    float max_salary = 0;
    
    for (int i=0; i<=cantidad; i++){
        avg += empleados[i].salary;
        if (max_salary < empleados[i].salary){
            max_name = i;
            max_salary = empleados[i].salary;
        }
    }
    avg /= (cantidad+1);
    mostrar_datos(empleados, cantidad, avg, max_salary, max_name);
}


void ingresar_datos(empleado_t empleados[CANT_MAX], int cantidad){
    printf("\n\nIntroducir el nombre del empleado: ");
    scanf("%s", empleados[cantidad].name);

    printf("\nIntroducir la edad del empleado: ");
    scanf("%i", &empleados[cantidad].age);

    printf("\nIntroducir el salario del empleado: ");
    scanf("%f", &empleados[cantidad].salary);
}


void main(){
    empleado_t empleados[CANT_MAX];
    int decision = 0;
    int cantidad = 0;

    while (decision != 3 && cantidad <= CANT_MAX){
        printf("--- Menú --- \n1. Ingresar datos de un empleado.\n2. Procesar y mostrar información importante.\n3. Salir.\n\nIngrese su opción: ");
        scanf("%d", &decision);

        switch (decision){
            case 1: 
                ingresar_datos(empleados, cantidad);
                cantidad++;
                break;

            case 2:
                procesar_datos(empleados, cantidad-1);
                break;

            case 3:
                printf("Gracias por usar el programa.");
                break;

            default:
                printf("Introduzca una opción válida\n");
                break;
        }
    }
    if (cantidad > CANT_MAX){
        printf("\n\nCantidad máxima de empleados superada\n");
        procesar_datos(empleados, cantidad-1);
    }
}
