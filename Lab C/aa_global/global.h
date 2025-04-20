
#ifndef GLOBAL_H
#define GLOBAL_H



//===================================================================================================================================================================




// Librerías estándar:

#include <stdbool.h>  // Para 'bool' en bin2dec
#include <stddef.h>   // Para 'size_t'



//===================================================================================================================================================================



// Definiciones:

#define MAX_FILAS 10
#define MAX_COLUMNAS 10



//===================================================================================================================================================================



// Tipos personalizados:

typedef int int32_t;  			// Tipo entero de 32 bits, para evitar el uso de librerías estándar en algunas funciones.

typedef char* root_t;			// Tipo puntero a char, para la solución de la ecuación de segundo grado.

typedef struct {			// Estructura para función de segundo grado (ax² + bx + c = 0).
    float a;
    float b;
    float c;
} coeff_t;

typedef struct complex_s {		//Estructura para números complejos.
    float r;  // Parte real
    float i;  // Parte imaginaria
} complex_t;

typedef struct {			// Estructura para fecha.
    int day;
    int month;
    int year;
} date_t;

typedef struct {			// Estructura para matrices.
    int filas;
    int columnas;
    int datos[MAX_FILAS][MAX_COLUMNAS];
} matriz_t;



//===================================================================================================================================================================



// bin_2_dec

/**
 * Convierte un número binario en su representación decimal.
 * 
 * @param binary Número binario en formato de complemento a 2 (se espera 0b...).
 * @param sign Indica si el número debe interpretarse como con signo (true) o sin signo (false).
 * @return Valor decimal correspondiente al número binario.
 * 
 * @note 
 * - El código espera un formato binario válido (ej. `0b1010`).
 * - Si el número es sin signo y tiene un 1 en el bit 31, su valor decimal puede exceder el máximo de un `int32_t` (2147483647), causando comportamiento inesperado.
 */
int32_t bin2dec(int32_t binary, bool sign);



//===================================================================================================================================================================



// complex_prod y complex_sum

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



//===================================================================================================================================================================



// consonantes y vocales

/**
 * Cuenta el número de consonantes en un string
 * @param string Cadena de caracteres a analizar
 * @return Número de consonantes encontradas
 * @note Considera tanto mayúsculas como minúsculas, incluye Ñ y ñ
 */
int consonantes(char *string);

/**
 * Cuenta el número de vocales en un string
 * @param string Cadena de caracteres a analizar
 * @return Número de vocales encontradas
 * @note Considera tanto mayúsculas como minúsculas
 */
int vocales(char *string);



//===================================================================================================================================================================



// days_left

/**
 * Verifica si un año es bisiesto.
 * @param year Año a evaluar.
 * @return 1 si es bisiesto, 0 en caso contrario.
 */
int is_bisiesto(int year);

/**
 * Obtiene el número de días en un mes específico, considerando años bisiestos.
 * @param month Mes (1-12).
 * @param year Año (para validar febrero en bisiestos).
 * @return Número de días en el mes.
 */
int dias_en_mes(int month, int year);

/**
 * Compara dos fechas.
 * @param a Primera fecha.
 * @param b Segunda fecha.
 * @return -1 si a < b, 0 si son iguales, 1 si a > b.
 */
int compare_dates(date_t a, date_t b);

/**
 * Calcula la diferencia en días entre dos fechas (start y finish).
 * @param start Fecha inicial.
 * @param finish Fecha final.
 * @return Número de días entre las fechas (si start > finish, retorna días negativos).
 */
int days_left(date_t start, date_t finish);



//===================================================================================================================================================================



// eq_solver

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



//===================================================================================================================================================================



// find_in_string

/**
 * Busca una subcadena dentro de una cadena (sin usar librerías standard).
 * @param haystack Cadena principal donde buscar
 * @param needle Subcadena a encontrar
 * @return Posición de inicio de la subcadena si se encuentra, -1 si no se encuentra
 * @note Si needle es una cadena vacía, retorna 0
 * @warning No se deben pasar punteros nulos
 */
int find_in_string(char *haystack, char *needle);



//===================================================================================================================================================================



// init_lab

/**
 * Muestra en pantalla el mensaje de identificación del laboratorio
 * @note Despliega el mensaje "Laboratorio lenguaje C de <nombres completos>"
 */
void init_lab(void);



//===================================================================================================================================================================



// print_reverse_array

/**
 * Imprime un array en orden inverso detectando automáticamente el tipo de dato
 * 
 * @param array Puntero al array a imprimir
 * @param data_type Tamaño en bytes del tipo de dato (usa sizeof())
 * @param array_size Cantidad de elementos en el array
 * 
 * @note Tipos soportados:
 *       - char (1 byte)
 *       - short (2 bytes)
 *       - int (4 bytes)
 *       - long (4/8 bytes)
 *       - long long (8 bytes)
 *       - float (4 bytes)
 *       - double (8 bytes)
 *       - long double (8/16 bytes)
 * 
 * @warning Para long double en Windows se usa __mingw_printf()
 */
void print_reverse_array(void *array, size_t data_type, size_t array_size);



//===================================================================================================================================================================



// matrix_sub

/**
 * Resta dos matrices elemento por elemento
 * 
 * @param A Primera matriz (minuendo)
 * @param B Segunda matriz (sustraendo)
 * @return matriz_t Matriz resultante de A - B
 * 
 * @note Ambas matrices deben tener las mismas dimensiones
 * @warning No se verifica que las dimensiones sean válidas (< MAX_FILAS/MAX_COLUMNAS)
 */
matriz_t matrix_sub(matriz_t A, matriz_t B);



//===================================================================================================================================================================



// max y min

/**
 * Encuentra el valor máximo en un array genérico
 * @param array Puntero al array
 * @param data_type Tamaño en bytes de cada elemento
 * @param array_size Cantidad de elementos en el array
 * @note Esta versión funciona solo con arrays de tipo int
 * @warning No verifica que data_type coincida con el tipo real del array
 */
void max_index(void *array, size_t data_type, size_t array_size);

/**
 * Encuentra el valor mínimo en un array genérico
 * @param array Puntero al array
 * @param data_type Tamaño en bytes de cada elemento
 * @param array_size Cantidad de elementos en el array
 * @note Esta versión funciona solo con arrays de tipo int
 * @warning No verifica que data_type coincida con el tipo real del array
 */
void min_index(void *array, size_t data_type, size_t array_size);



//===================================================================================================================================================================



// reverse_string

/**
 * Invierte un string in-place y lo imprime.
 * @param string String a invertir (se modifica directamente).
 * @return El mismo string invertido, o NULL si el input es NULL.
 * 
 * @note El string original es modificado. Para mantener el original,
 *       hacer una copia antes de llamar a esta función.
 */
char *reverse_string(char *string);



//===================================================================================================================================================================



// string_copy

/**
 * Copia un string de origen a destino (sin usar librerías estándar).
 * @param source String de origen (a copiar).
 * @param destination Buffer de destino (donde se copiará).
 * @return 0 en éxito, -1 si source o destination son NULL.
 * 
 * @note:
 * - El buffer de destino debe tener suficiente espacio para almacenar el string de origen + '\0'.
 * - Esta versión no verifica desbordamiento del buffer de destino.
 * - La copia incluye el carácter nulo terminador.
 */
int string_copy(char *source, char *destination);



//===================================================================================================================================================================



// string_length

/**
 * Calcula la longitud de un string (sin usar bibliotecas estándar).
 * @param string String cuyo length se calculará.
 * @return Longitud del string, o -1 si el string es NULL.
 */
int32_t string_length(char *string);



//===================================================================================================================================================================



// string_to_caps y string_to_min

/**
 * Convierte todos los caracteres de un string a mayúsculas (modifica el original).
 * @param string String a modificar (debe terminar en '\0').
 * 
 * @note:
 * - Solo afecta letras minúsculas (a-z).
 * - Modifica el string in-place (no crea una copia).
 */
void string_to_caps(char *string);

/**
 * Convierte todos los caracteres de un string a minúsculas (modifica el original).
 * @param string String a modificar (debe terminar en '\0').
 * 
 * @note:
 * - Solo afecta letras mayúsculas (A-Z).
 * - Modifica el string in-place (no crea una copia).
 */
void string_to_min(char *string);



//===================================================================================================================================================================



// string_words

/**
 * Cuenta el número de palabras en un string (sin usar bibliotecas estándar).
 * @param string String a analizar (debe terminar en '\0').
 * @return Número de palabras (>= 0), o -1 si el string es NULL.
 * 
 * @note:
 * - Una palabra se define como una secuencia de caracteres delimitada por espacios, tabs o saltos de línea.
 * - No distingue entre mayúsculas/minúsculas ni caracteres especiales.
 */
int32_t string_words(char *string);



//===================================================================================================================================================================



// swap

/**
 * Intercambia el contenido de dos elementos genéricos.
 * @param elem_1 Puntero al primer elemento.
 * @param elem_2 Puntero al segundo elemento.
 * @param data_type Tamaño en bytes del tipo de dato a intercambiar.
 * @return 0 si éxito, -1 si hay errores (punteros NULL o data_type = 0).
 * 
 * @note:
 * - Usa memoria dinámica (malloc) para el intercambio.
 * - Los elementos deben ser del mismo tipo y tamaño.
 * - No verifica overlaps (comportamiento indefinido si elem_1 y elem_2 se solapan).
 */
int swap(void *elem_1, void *elem_2, size_t data_type);



//===================================================================================================================================================================



#endif // GLOBAL_H