#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
       
    printf("\n\nArray original: ");
    
    // Primero imprimimos el array en orden normal para referencia
    for (size_t i = 0; i < array_size; i++) {
        
        if (data_type == sizeof(char)) {
            printf("%c", ((char*)array)[i]);
        } 
        else if (data_type == sizeof(int)) {
            printf("%d ", ((int*)array)[i]);
        } 
        else if (data_type == sizeof(float)) {
            printf("%.2f ", ((float*)array)[i]);
        }
    }
    
    printf("\n\nArray inverso: ");
    
    // Imprimimos en orden inverso
    for (size_t i = array_size ; i > 0; i--) {
        
        if (data_type == sizeof(char)) {
            printf("%c", ((char*)array)[i-1]);
        } 
        else if (data_type == sizeof(int)) {
            printf("%d ", ((int*)array)[i-1]);
        } 
        else if (data_type == sizeof(float)) {
            printf("%.2f ", ((float*)array)[i-1]);
        }
    }
    printf("\n");   
}

int main() {
    // Ejemplo con array de caracteres
    char char_array[] = "Hola mundo";
    print_reverse_array(char_array, sizeof(char), strlen(char_array));
    
    // Ejemplo con array de enteros
    int int_array[] = {325, 21, 54, 446, 32};
    print_reverse_array(int_array, sizeof(int), 5);
    
    // Ejemplo con array de floats
    float float_array[] = {1.23, 2.4, 3.16, 4.6};
    print_reverse_array(float_array, sizeof(float), 4);

    printf("\n\n");

    return 0;
}