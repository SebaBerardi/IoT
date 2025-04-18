#include <stdio.h>

// Función que copia un string source en destination
int string_copy(char *source, char *destination) {
    if (source == NULL || destination == NULL) {
        return -1; // Error por puntero nulo
    }

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // Terminar string con carácter nulo

    return 0; // Éxito
}