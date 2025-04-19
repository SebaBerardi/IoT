// Encuentre la longitud de un string (sin usar funciones de biblioteca) retorna -1 en caso de error

typedef int int32_t; // se declara que int32_t es un tipo igual a int

int32_t string_length(char *string) {
    if (!string) {
        return -1;  // Error: puntero nulo
    }

    int32_t len = 0;
    while (string[len] != '\0') {
        len++;
    }

    return len;
}