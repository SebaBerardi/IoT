#include <stdio.h>
#include <math.h>
#include <string.h>

// Escribir un programa en C que resuelva la ecuación de segundo grado.

// Definición de tipos
typedef float coeff_t;

typedef struct {
    float root1;
    float root2;
    int type_root;  //2: tiene dos raices reales, 1: tiene raiz doble, 0: no existe, -1: no real, 8: infinitas, 3: 1er grado
} root_t;

// Función para resolver ecuación cuadrática
root_t eq_solver(coeff_t *coeficientes) {
    root_t result;

    float a = coeficientes[0];
    float b = coeficientes[1];
    float c = coeficientes[2];

   // Caso especial: a = 0 (ecuación lineal)
    if (a == 0) {
        if (b == 0) {
            result.type_root = (c == 0) ? 8 : 0; // (v o f) ? (si v) x : (sino) y
        } else {
            result.type_root = 3;
            result.root1 = result.root2 = -c / b;
        }
    }

    printf("%d ", result.type_root);

    float discriminante = b * b - 4 * a * c;

       if (discriminante < 0 && result.type_root != 0 && result.type_root != 8 && result.type_root != 3) {
        result.type_root = -1;
    } else if (discriminante == 0 && result.type_root != 0 && result.type_root != 8 && result.type_root != 3) {
        result.type_root = 1;
        result.root1 = result.root2 = -b / (2 * a);
    } else if (result.type_root != 0 && result.type_root != 8 && result.type_root != 3) {
        result.type_root = 2;
        result.root1 = (-b + sqrt(discriminante)) / (2 * a);
        result.root2 = (-b - sqrt(discriminante)) / (2 * a);
    }
    
    printf("%d", result.type_root);

    switch (result.type_root) {
        case 8:
            printf("\n\nLa ecuación tiene infinitas raices.\n\n\n");
            break;
        case -1:
            printf("\n\nLa ecuación no tiene raices reales.\n\n\n");
            break;
        case 1:
            printf("\n\nLa ecuación tiene raiz doble: %f\n\n\n", result.root1);
            break;
        case 2:
            printf("\n\nLa ecuación tiene dos raices: %f y %f\n\n\n", result.root1, result.root2);
            break;
        case 3:
            printf("\n\nEs una ecuacion lineal con raiz en: %f\n\n\n", result.root1, result.root2);
            break;
        case 0:
            printf("\n\nNo exisite ninguna raiz para esta ecuación.\n\n\n");
            break;
    }
    return result;
}

void main() {
    // Ejemplo de uso
    coeff_t coeficientes[] = {0, 0, 8};
    eq_solver(coeficientes);
}