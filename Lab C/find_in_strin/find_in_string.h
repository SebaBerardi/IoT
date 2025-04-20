#ifndef FIND_IN_STRING_H
#define FIND_IN_STRING_H

/**
 * Busca una subcadena dentro de una cadena (sin usar librerías standard).
 * @param haystack Cadena principal donde buscar
 * @param needle Subcadena a encontrar
 * @return Posición de inicio de la subcadena si se encuentra, -1 si no se encuentra
 * @note Si needle es una cadena vacía, retorna 0
 * @warning No se deben pasar punteros nulos
 */
int find_in_string(char *haystack, char *needle);

#endif // FIND_IN_STRING_H