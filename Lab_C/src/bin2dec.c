// Convierta un número binario en uno decimal

#include <stdbool.h>
#include <stdio.h>
#include "global.h"

typedef int int32_t;

int32_t bin2dec(int32_t binary, bool sign) {
    
    printf("\n\nIMPORTANTE: \n\n  - Tener en cuenta que el codigo funciona unicamente cuando se le ingresa un número binario, es decir en el formato 0b.\n\n  - Si el valor es incorrecto, esto puede deverse a que si el valor ingresado tiene un 1 en el bit 31 y no tiene signo, por lo que su valor decimal es mayor a 2147483647, el cual es el valor mas grande que se puede guardar en un int32.\n\n");
    
    int32_t decimal = 0;
    int base = 1;
    int bits = 32;
    
    if (sign == true & 1<<31) {
        binary -= 1;
        binary = ~binary;
     
        for (int i = 0; i < 31; i++) {
            if (binary & (1 << i)) {
                decimal -= base;
            }
        }
    }        
    else if (sign == true & 1<<31) {
        bits = 31;
    }

    for (int i = 0; i < bits; i++) {
        if (binary & (1 << i)) {
                decimal += base;
        }
        base *= 2;
        }
    return decimal;
}