#ifndef STRING_TO_H
#define STRING_TO_H

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

#endif // STRING_TO_H