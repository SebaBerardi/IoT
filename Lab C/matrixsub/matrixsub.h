#ifndef MATRIXSUB_H
#define MATRIXSUB_H

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

typedef struct {
    int filas;
    int columnas;
    int datos[MAX_FILAS][MAX_COLUMNAS];
} matriz_t;

/**
 * @brief Resta dos matrices elemento por elemento
 * 
 * @param A Primera matriz (minuendo)
 * @param B Segunda matriz (sustraendo)
 * @return matriz_t Matriz resultante de A - B
 * 
 * @note Ambas matrices deben tener las mismas dimensiones
 * @warning No se verifica que las dimensiones sean válidas (< MAX_FILAS/MAX_COLUMNAS)
 */
matriz_t matrix_sub(matriz_t A, matriz_t B);

#endif // MATRIXSUB_H