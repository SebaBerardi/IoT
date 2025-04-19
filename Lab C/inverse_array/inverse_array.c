// Lea los valores en un array y los muestre en pantalla en orden inverso

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
       
    int dato = 1;
    
    for (size_t i = 0; i < array_size; i++) {
        
        if (data_type == sizeof(char)) {    
            dato = 2;
        }    
        else if (data_type == sizeof(int)) {      
            float val = ((float*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                dato = 0;
            }
        }
    }    
    switch (dato)
    {
    case 1:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%d ", ((int*)array)[i-1]);
        }   printf("\n"); 
        break;
    case 0: 
        printf("\nArray inverso: ");    
        for (size_t i = array_size ; i > 0; i--) {
            printf("%f ", ((float*)array)[i-1]);
        }   printf("\n");
        break;
    case 2: 
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%c", ((char*)array)[i-1]);
        }   printf("\n");
        break;
}   
    printf("\n");   
}