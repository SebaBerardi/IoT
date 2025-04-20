// Imprima y devuelve un string al revés

#include <stdio.h>
#include <string.h>

char *reverse_string(char *string) {
    if (!string) return NULL;
    
    int length = strlen(string);
    
    // Invertir el string
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    
    printf("\nSu string inverso es: %s\n\n", string);
    return string;
}