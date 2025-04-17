#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct complex_s
{
    float r;
    float i;
} complex_t;



// Multiplique dos números complejos:
complex_t prod(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;
    return result;
}

int main()
{
    complex_t a, b, s, p;
    a.r = 1;
    a.i = 2;

    b.r = 5;
    b.i = 8;

    p = prod(a, b);

    printf("PROD: %f %f\n", p.r, p.i);


    return 0;
}