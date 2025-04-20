#ifndef STRING_LENGTH_H
#define STRING_LENGTH_H

typedef int int32_t;  // Tipo entero de 32 bits

/**
 * Calcula la longitud de un string (sin usar bibliotecas estándar).
 * @param string String cuyo length se calculará.
 * @return Longitud del string, o -1 si el string es NULL.
 */
int32_t string_length(char *string);

#endif // STRING_LENGTH_H