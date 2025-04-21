#include "global.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void init_lab(void) {
    printf("Laboratorio lenguaje C de Sebastián Berardi, Gervasio Hernández y Joaquín Cuitiño\n");
}

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

int32_t bin2dec(int32_t binary, bool sign) {
    
    printf("\n\nIMPORTANTE: \n\n  - Tener en cuenta que el codigo funciona unicamente cuando se le ingresa un número binario, es decir en el formato 0b.\n\n  - Si el valor es incorrecto, esto puede deverse a que si el valor ingresado tiene un 1 en el bit 31 y no tiene signo, por lo que su valor decimal es mayor a 2147483647, el cual es el valor mas grande que se puede guardar en un int32.\n\n");
    
    int32_t decimal = 0;
    int base = 1;
    int bits = 32;
    
    if (sign == true & 1<<31) {
        binary -= 1;
        binary = ~binary;
     
        for (int i = 0; i < 31; i++) {
            if (binary & (1 << i)) {
                decimal -= base;
            }
        }
    }        
    else if (sign == true & 1<<31) {
        bits = 31;
    }

    for (int i = 0; i < bits; i++) {
        if (binary & (1 << i)) {
                decimal += base;
        }
        base *= 2;
        }
    return decimal;
}

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
       
    int dato = 0;
    for (size_t i = 0; i < array_size; i++) {
        
        if (data_type == sizeof(int)) {      
            float val = ((float*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                dato = 1; }
        }
        else if (data_type == sizeof(char)) {    
            dato = 2; 
        }
        else if (data_type == sizeof(long)) {    
            dato = 3; 
        }
        else if (data_type == sizeof(short)) {    
            dato = 4; 
        }
        else if (data_type == sizeof(long long)) {    
            double val = ((double*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                dato = 5; }
        }
        else if (data_type == sizeof(long double)) {    
            dato = 6; 
        }   
        else { dato = 7; }
    }
    switch (dato) {   
    
        case 0:
        printf("\nArray inverso: ");
        if (data_type == sizeof(int)) {
            for (size_t i = array_size ; i > 0; i--) {
                printf("%d ", ((int*)array)[i-1]);
            }   printf("\n");
        } 
        else {         
            for (size_t i = array_size ; i > 0; i--) {
                printf("%lld ", ((long long*)array)[i-1]);
            }   printf("\n");} 
        break;
    case 1: 
        printf("\nArray inverso: ");    
        for (size_t i = array_size ; i > 0; i--) {
            printf("%f ", ((float*)array)[i-1]);
        }   printf("\n");
        break;
    case 2: 
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%c", ((char*)array)[i-1]);
        }   printf("\n");
        break;
    case 3:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%ld ", ((long*)array)[i-1]);
        }   printf("\n");
        break;
    case 4:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%hd ", ((short*)array)[i-1]);
        }   printf("\n");
        break;
    case 5:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%lf ", ((double*)array)[i-1]);
        }   printf("\n");
        break;
    case 6:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            long double valor = ((long double*)array)[i-1];
            __mingw_printf("%Lf", valor);
        }   printf("\n");
        break;
    default: printf("\ndata_type no soportado\n");
    }   
    printf("\n");
}

void max_index(void *array, size_t data_type, size_t array_size) {
    if (array == NULL || array_size == 0) {
        printf("Array inválido.\n");
        return;
    }

    char *ptr = (char *)array; //configuro punteros
    int max_val = *(int *)ptr;
    size_t max_pos = 0;

    for (size_t i = 1; i < array_size; i++) {//recorro el array guardando cada vez el valor mas grande hasta el momento
        int current = *(int *)(ptr + i * data_type);
        if (current > max_val) {
            max_val = current;
            max_pos = i;
        }
    }

    printf("Máximo: %d en la posición %zu\n", max_val, max_pos);
}

void min_index(void *array, size_t data_type, size_t array_size) { 
    if (array == NULL || array_size == 0) {
        printf("Array inválido.\n");
        return;
    }

    char *ptr = (char *)array; //configuro punteros
    int min_val = *(int *)ptr;
    size_t min_pos = 0;

    for (size_t i = 1; i < array_size; i++) { //recorro el array guardando cada vez el valor mas chico hasta el momento
        int current = *(int *)(ptr + i * data_type);
        if (current < min_val) {
            min_val = current;
            min_pos = i;
        }
    }

    printf("Mínimo: %d en la posición %zu\n", min_val, min_pos);
}

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


int swap(void *elem_1, void *elem_2, size_t data_type) {
    if (elem_1 == NULL || elem_2 == NULL || data_type == 0) {
        return -1; // Error: punteros nulos o tipo de dato inválido
    }

    
    void *temp = malloc(data_type);
    if (temp == NULL) {
        return -1; 
    }

    // Intercambiar los contenidos
    memcpy(temp, elem_1, data_type);      // temp = *elem_1
    memcpy(elem_1, elem_2, data_type);    // *elem_1 = *elem_2
    memcpy(elem_2, temp, data_type);      // *elem_2 = temp

    free(temp);

    return 0;
}


int consonantes(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
    char *cons = "BbCcDdFfGgHhJjKkLlMmNnÑñPpQqRrSsTtVvWwXxYyZz";
    
    for (int digito = 0; digito < letras; digito++)
    {
        for (int i = 0; i < 44; i++)
        {
            c = cons[i];
            if (string[digito] == c)
            {
                num++;
            }
        }
    }

    return num;
}

int vocales(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
    char *voc = "AaEeIiOoUu";
    
    for (int digito = 0; digito < letras; digito++)
    {
        for (int i = 0; i < 10; i++)
        {
            c = voc[i];
            if (string[digito] == c)
            {
                num++;
            }
        }
    }

    return num;
}

char *reverse_string(char *string) {
    if (!string) return NULL;
    
    int length = strlen(string);
    
    // Invertir el string
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    
    printf("\nSu string inverso es: %s\n\n", string);
    return string;
}

int32_t string_length(char *string) {
    if (!string) {
        return -1;  // Error: puntero nulo
    }

    int32_t len = 0;
    while (string[len] != '\0') {
        len++;
    }

    return len;
}

int32_t string_words(char *string) {
    if (string == 0) return -1; // Error: puntero nulo

    int32_t count = 0;
    int in_word = 0;

    while (*string != '\0') {
        if (*string != ' ' && *string != '\t' && *string != '\n') {
            if (!in_word) {
                count++;       // Entramos a una nueva palabra
                in_word = 1;   // Marcamos que estamos dentro de una palabra
            }
        } else {
            in_word = 0;       // Salimos de la palabra
        }
        string++; // Avanzamos al siguiente carácter
    }

    return count;
}


int string_copy(char *source, char *destination) {
    if (!source || !destination) {
        return -1; // Error por puntero nulo
    }

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // Terminar string con carácter nulo

    return 0; // Éxito
}

int find_in_string(char *haystack, char *needle)
{
    // Calcular largo de haystack
    int largo_haystack = 0;
    while (haystack[largo_haystack] != '\0') {
        largo_haystack++;
    }

    // Calcular largo de needle
    int largo_needle = 0;
    while (needle[largo_needle] != '\0') {
        largo_needle++;
    }

    // Si needle está vacío, retornar 0 (como strstr)
    if (largo_needle == 0) {
        return 0;
    }

    // Búsqueda principal
    for (int i = 0; i <= largo_haystack - largo_needle; i++)
    {
        int encontrado = 1;
        for (int j = 0; j < largo_needle; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                encontrado = 0;
                break;
            }
        }
        if (encontrado) {
            return i;
        }
    }

    return -1;
}


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

complex_t sum(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}

complex_t prod(complex_t a, complex_t b)
{
    complex_t result;
    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;
    return result;
}

int is_bisiesto(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dias_en_mes(int month, int year) {
    switch (month) {
        case 2: return is_bisiesto(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

// Compara dos fechas: retorna -1 si a < b, 0 si iguales, 1 si a > b, para validar si la fecha final es despues de la inicial
int compare_dates(date_t a, date_t b) {
    if (a.year != b.year) return (a.year < b.year) ? -1 : 1;
    if (a.month != b.month) return (a.month < b.month) ? -1 : 1;
    if (a.day != b.day) return (a.day < b.day) ? -1 : 1;
    return 0;
}

// Avanza un día en una fecha
void next_day(date_t *date) {
    date->day++;
    if (date->day > dias_en_mes(date->month, date->year)) {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

int days_left(date_t start, date_t finish) {
    int count = 0;

    // Si start > finish, los intercambiamos
    if (compare_dates(start, finish) > 0) {
        date_t temp = start;
        start = finish;
        finish = temp;
    }

    while (compare_dates(start, finish) != 0) {
        next_day(&start);
        count++;
    }

    return count;
}