// Devuelva la resta de dos matrices

#include "global.h"

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

matriz_t matrix_sub(matriz_t A, matriz_t B) {
    matriz_t C;
    C.filas = A.filas;
    C.columnas = A.columnas;

    for (int i = 0; i < A.filas; i++) { // recorro filas
        for (int j = 0; j < A.columnas; j++) {   // recorro columnas
            C.datos[i][j] = A.datos[i][j] - B.datos[i][j]; // resto los elementos y guardo en c
        }
    }

    return C;
}