#ifndef STRING_COPY_H
#define STRING_COPY_H

/**
 * Copia un string de origen a destino (sin usar librerías estándar).
 * @param source String de origen (a copiar).
 * @param destination Buffer de destino (donde se copiará).
 * @return 0 en éxito, -1 si source o destination son NULL.
 * 
 * @note:
 * - El buffer de destino debe tener suficiente espacio para almacenar el string de origen + '\0'.
 * - Esta versión no verifica desbordamiento del buffer de destino.
 * - La copia incluye el carácter nulo terminador.
 */
int string_copy(char *source, char *destination);

#endif // STRING_COPY_H