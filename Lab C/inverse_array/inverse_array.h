#ifndef INVERSE_ARRAY_H
#define INVERSE_ARRAY_H

#include <stddef.h>  // Para size_t

/**
 * @brief Imprime un array en orden inverso detectando automáticamente el tipo de dato
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

#endif // INVERSE_ARRAY_H