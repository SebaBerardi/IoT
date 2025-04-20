typedef struct complex_s
{
    float r;
    float i;
} complex_t;

// Sume dos números complejos
complex_t prod(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;
    return result;
}

// Multiplique dos números complejos
complex_t sum(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}