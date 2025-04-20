#ifndef MAX_MIN_H
#define MAX_MIN_H

#include <stddef.h>  // Para size_t

/**
 * @brief Encuentra el valor máximo en un array genérico
 * @param array Puntero al array
 * @param data_type Tamaño en bytes de cada elemento
 * @param array_size Cantidad de elementos en el array
 * @note Esta versión funciona solo con arrays de tipo int
 * @warning No verifica que data_type coincida con el tipo real del array
 */
void max_index(void *array, size_t data_type, size_t array_size);

/**
 * @brief Encuentra el valor mínimo en un array genérico
 * @param array Puntero al array
 * @param data_type Tamaño en bytes de cada elemento
 * @param array_size Cantidad de elementos en el array
 * @note Esta versión funciona solo con arrays de tipo int
 * @warning No verifica que data_type coincida con el tipo real del array
 */
void min_index(void *array, size_t data_type, size_t array_size);

#endif // MAX_MIN_H