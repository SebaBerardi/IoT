#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex_s {
    float r;  // Parte real
    float i;  // Parte imaginaria
} complex_t;

/**
 * Multiplica dos números complejos
 * @param a Primer número complejo
 * @param b Segundo número complejo
 * @return Resultado de la multiplicación a*b
 */
complex_t prod(complex_t a, complex_t b);

/**
 * Suma dos números complejos
 * @param a Primer número complejo
 * @param b Segundo número complejo
 * @return Resultado de la suma a+b
 */
complex_t sum(complex_t a, complex_t b);

#endif // COMPLEX_H