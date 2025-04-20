// Lea los valores en un array y los muestre en pantalla en orden inverso

#include <stdio.h>
#include <math.h>
#include "global.h"

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
       
    int dato = 0;
    for (size_t i = 0; i < array_size; i++) {
        
        if (data_type == sizeof(int)) {      
            float val = ((float*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                dato = 1; }
        }
        else if (data_type == sizeof(char)) {    
            dato = 2; 
        }
        else if (data_type == sizeof(long)) {    
            dato = 3; 
        }
        else if (data_type == sizeof(short)) {    
            dato = 4; 
        }
        else if (data_type == sizeof(long long)) {    
            double val = ((double*)array)[i];
            if (fabsf(fmodf(val, 1.0f)) > 1.0e-42f) {
                dato = 5; }
        }
        else if (data_type == sizeof(long double)) {    
            dato = 6; 
        }   
        else { dato = 7; }
    }
    switch (dato) {   
    
        case 0:
        printf("\nArray inverso: ");
        if (data_type == sizeof(int)) {
            for (size_t i = array_size ; i > 0; i--) {
                printf("%d ", ((int*)array)[i-1]);
            }   printf("\n");
        } 
        else {         
            for (size_t i = array_size ; i > 0; i--) {
                printf("%lld ", ((long long*)array)[i-1]);
            }   printf("\n");} 
        break;
    case 1: 
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
    case 3:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%ld ", ((long*)array)[i-1]);
        }   printf("\n");
        break;
    case 4:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%hd ", ((short*)array)[i-1]);
        }   printf("\n");
        break;
    case 5:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            printf("%lf ", ((double*)array)[i-1]);
        }   printf("\n");
        break;
    case 6:
        printf("\nArray inverso: ");
        for (size_t i = array_size ; i > 0; i--) {
            long double valor = ((long double*)array)[i-1];
            __mingw_printf("%Lf", valor);
        }   printf("\n");
        break;
    default: printf("\ndata_type no soportado\n");
    }   
    printf("\n");
}