#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
       
    printf("\n\nArray original: ");
    
    // Primero imprimimos el array en orden normal para referencia
    int dato = 1;
    
    for (size_t i = 0; i < array_size; i++) {
        
        if (data_type == sizeof(char)) {    
            printf("%c", ((char*)array)[i]);
            dato = 2;
        }    
        else if (data_type == sizeof(int)) {      
            float val = ((float*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                float lpm = fmodf(val, 1.0f);
                dato = 0;
            }
        }
    }    
    switch (dato)
    {
    case 1:
        for (size_t i = 0; i < array_size; i++) {
            printf("%d ", ((int*)array)[i]);
        }
        printf("\n\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%d ", ((int*)array)[i-1]);
        }   break;
    case 0:
        for (size_t i = 0; i < array_size; i++) {
            printf("%f ", ((float*)array)[i]);    
        }
        printf("\n\nArray inverso: ");    
        for (size_t i = array_size ; i > 0; i--) {
            printf("%f ", ((float*)array)[i-1]);
        }   break;
    case 2: 
        printf("\n\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%c", ((char*)array)[i-1]);
        }   break;
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
    float float_array[] = {101.1, 2.14, 3.13, 4.36};
    print_reverse_array(float_array, sizeof(float), 4);

    printf("\n\n");

    return 0;
}