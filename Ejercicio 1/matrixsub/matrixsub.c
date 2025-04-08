#include <stdio.h>

void restar_matrices(int filas, int columnas, int a[filas][columnas], int b[filas][columnas], int c[filas][columnas])
{
    for (size_t i = 0; i < filas; i++)
    { // recorro filas
        for (size_t j = 0; j < columnas; j++)
        {                                // recorro columnas
            c[i][j] = a[i][j] - b[i][j]; // resto los elementos y guardo en c
        }
    }
}

int main()
{
    int filas = 2;
    int columnas = 3;

    int a[2][3] = {
        {5, 6, 7},
        {1, 2, 3}};

    int b[2][3] = {
        {1, 2, 3},
        {1, 1, 1}};

    int c[2][3];

    restar_matrices(filas, columnas, a, b, c);

    // Mostrar matriz resultante
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
