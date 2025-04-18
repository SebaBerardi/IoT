#include <stdint.h>

int32_t string_words(char *string) {
    if (string == 0) return -1; // Error: puntero nulo

    int32_t count = 0;
    int in_word = 0;

    while (*string != '\0') {
        if (*string != ' ' && *string != '\t' && *string != '\n') {
            if (!in_word) {
                count++;       // Entramos a una nueva palabra
                in_word = 1;   // Marcamos que estamos dentro de una palabra
            }
        } else {
            in_word = 0;       // Salimos de la palabra
        }
        string++; // Avanzamos al siguiente carácter
    }

    return count;
}
