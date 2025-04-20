#ifndef EQ_SOLVER_H
#define EQ_SOLVER_H

typedef struct {
    float a;
    float b;
    float c;
} coeff_t;

typedef char* root_t;

/**
 * Resuelve una ecuación cuadrática de la forma ax² + bx + c = 0
 * @param coeficientes Puntero a la estructura con los coeficientes a, b y c
 * @return String con las raíces calculadas (formato dinámico)
 * @note El string retornado contiene:
 *       - "Infinitas soluciones" si a=0, b=0, c=0
 *       - "No existen soluciones" si a=0, b=0, c≠0
 *       - Solución lineal si a=0, b≠0
 *       - Raíces reales o complejas según el discriminante
 * @warning El llamante debe asegurar que el puntero a coeficientes es válido
 */
root_t eq_solver(coeff_t *coeficientes);

#endif // EQ_SOLVER_H