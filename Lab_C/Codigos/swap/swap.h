#ifndef SWAP_H
#define SWAP_H

#include <stddef.h>  // Para size_t

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

#endif // SWAP_H