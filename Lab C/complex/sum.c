#include <stdio.h>
#include <math.h>
#include <string.h>

// Sume dos números complejos:
typedef struct complex_s
{
    float r;
    float i;
} complex_t;

complex_t sum(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}

int main()
{
    complex_t a, b, s, p;
    a.r = 1;
    a.i = 2;

    b.r = 5;
    b.i = 8;

    s = sum(a, b);

    printf("SUM: %f %f\n", s.r, s.i);

    return 0;
}
