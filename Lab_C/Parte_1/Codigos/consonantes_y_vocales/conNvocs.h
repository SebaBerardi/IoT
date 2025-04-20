#ifndef CONNVOCS_H
#define CONNVOCS_H

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

#endif // CONNVOCS_H