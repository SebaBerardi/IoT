#ifndef BIN2DEC_H
#define BIN2DEC_H

#include <stdbool.h>

typedef int int32_t;

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

#endif // BIN2DEC_H