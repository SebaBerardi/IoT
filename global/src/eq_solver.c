// Resuelva la ecuación de segundo grado:

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "global.h"

// Definición de tipos
typedef char* root_t;

// Función para resolver ecuación cuadrática
root_t eq_solver(coeff_t *coeficientes) {
    root_t result;
    
    float a = coeficientes->a;
    float b = coeficientes->b;
    float c = coeficientes->c;

   // Caso especial: a = 0 (ecuación lineal)
    if (a == 0) {
        if (b == 0) {
            strcpy(result, c == 0 ? "Infinitas soluciones" : "No existen soluciones"); // (v o f) ? (si v) x : (sino) y
        } else {
            sprintf(result, "Ecuacion lineal con raiz en: %f", -c / b);
        }
    } else {
        float disc = b * b - 4 * a * c;
        if (disc < 0 ) {
            float real = -b / (2 * a);
            float imag = sqrt(-disc) / (2*a);
            sprintf(result, "Raices complejas: %f + j%f", real, imag);
        } else if (disc == 0) {
            sprintf(result, "Raiz doble: %f", -b / (2 * a));
        } else {
            float root1 = (-b + sqrt(disc)) / (2 * a);
            float root2 = (-b - sqrt(disc)) / (2 * a);
            sprintf(result, "Raices reales: %f y %f", root1, root2);
        }
    }
    return result;
}