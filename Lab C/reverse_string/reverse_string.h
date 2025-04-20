#ifndef REVERSE_STRING_H
#define REVERSE_STRING_H

/**
 * Invierte un string in-place y lo imprime.
 * @param string String a invertir (se modifica directamente).
 * @return El mismo string invertido, o NULL si el input es NULL.
 * 
 * @note El string original es modificado. Para mantener el original,
 *       hacer una copia antes de llamar a esta función.
 */
char *reverse_string(char *string);

#endif // REVERSE_STRING_H