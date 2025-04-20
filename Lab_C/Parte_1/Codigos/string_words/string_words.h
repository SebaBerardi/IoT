#ifndef STRING_WORDS_H
#define STRING_WORDS_H

typedef int int32_t;  // Tipo entero de 32 bits

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

#endif // STRING_WORDS_H