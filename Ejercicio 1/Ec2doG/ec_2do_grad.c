#include <stdio.h>
#include <math.h>
#include <string.h>

// Escribir un programa en C que resuelva la ecuación de segundo grado.
void ecuacion()
{
    float a, b, c, resultadoA, resultadoB;

    a = 4;
    b = 4;
    c = 1;

    int j = 7;

    resultadoA = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    resultadoB = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    printf("Resultado A: %f\n", resultadoA);
    printf("Resultado B: %f\n", resultadoB);
}

void palindromo()
{
    int num = 12321;
    int espejado = 0;
    int original = num;

    while (num > 0)
    {
        espejado = espejado * 10 + num % 10;
        num /= 10;
    }

    if (espejado == original)
    {
        printf("palindromo\n");
    }
    else
    {
        printf("NO palindromo\n");
    }
}

// Extraiga una subcadena de una cadena dada, debe retornar -1 en caso de no encontrarse. (sin usar librerías standard).
int find_in_string(char *haystack, char *needle)
{
    int largo_haystack = strlen(haystack);
    int largo_needle = strlen(needle);

    for (int i = 0; i <= largo_haystack - largo_needle; i++)
    {
        for (int j = 0, i2 = i; j < largo_needle && haystack[i2] == needle[j]; j++, i2++)
        {
            if (j == largo_needle - 1)
            {
                return i;
            }
        }
    }

    return -1;
}

// Lea una oración y reemplace los caracteres en minúsculas con mayúsculas o viceversa según
// decida el usuario. (sin usar librerías standard):
void string_to_caps(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}

void string_to_min(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

typedef struct complex_s
{
    float r;
    float i;
} complex_t;

// Sume dos números complejos:
complex_t sum(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}

// Multiplique dos números complejos:
complex_t prod(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;
    return result;
}

typedef struct date_s
{
    int year;
    int month;
    int day;
} date_t;

// Al ingresar dos fechas encuentre la diferencia, en días, entre ellas.
// AXIOMAS:
//     - start < finish
//     - Los años bisiestos NO existen.
//     - Se considera que el año tiene 365 días y los meses tienen 30 días. Matemáticamente no funciona, pero es así.
int days_left(date_t start, date_t finish)
{
    int days = abs(start.year - finish.year) * 365;
    days += abs(start.month - finish.month) * 30;
    days += abs(start.day - finish.day);
    return days;
}

int main()
{
    ecuacion();
    palindromo();
    char holanda[8] = "holanda";
    printf("Pos: %i\n", find_in_string(holanda, "ola"));

    string_to_caps(holanda);
    printf("TO CAPS: %s\n", holanda);
    string_to_min(holanda);
    printf("TO MIN: %s\n", holanda);

    complex_t a, b, s, p;
    a.r = 1;
    a.i = 2;

    b.r = 5;
    b.i = 8;

    s = sum(a, b);
    p = prod(a, b);

    printf("SUM: %f %f\n", s.r, s.i);
    printf("PROD: %f %f\n", p.r, p.i);

    return 0;
}
