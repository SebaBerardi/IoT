// Copie un string en otro string. (sin usar librerías standard)

#include "global.h"

int string_copy(char *source, char *destination) {
    if (!source || !destination) {
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