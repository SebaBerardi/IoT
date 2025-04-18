#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

int32_t bin2dec(int32_t binary, bool sign) {
    
    printf("\n\nTener en cuenta que el codigo funciona unicamente cuando se le ingresa un número binario, es decir en el formato 0xb.\n");
    
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
    printf("\nSi el siguiente valor es incorrecto, esto puede deverse a que si el valor ingresado tiene un 1 en el bit 31 y no tiene signo, su valor decimal es mayor a 2147483647 el cual es el valor mas grande que se puede guardar en un int32.");

    return decimal;
}

// Función principal para probar el conversor
int main() {
    int32_t positivo = 0b01111111111111111111111111111111;
    bool signo = false;
    printf("\n\nDecimal: %d\n\n\n", bin2dec(positivo, signo));
}
