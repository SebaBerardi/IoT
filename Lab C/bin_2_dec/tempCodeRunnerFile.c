#include <stdio.h>
#include <stdint.h>  // Para usar int32_t
#include <stdbool.h> // Para usar el tipo bool

int32_t bin2dec(int32_t binary, bool sign) {   // Función que convierte un número binario a decimal
    int32_t decimal = 0;                       // Variable donde se acumulará el resultado decimal
    int32_t base = 1;                          // Representa la potencia de 2 actual (2^0, 2^1, 2^2, ...)
    int32_t bin = binary;                      // Copia del binario para manipular

    
    if (sign && (binary & 0x80000000)) {   // Chequea si el bit más significativo es 1, si lo es, se interpreta como complemento a dos.
        bin = ~binary + 1;                 // Invierte los bits y suma 1 (complemento a dos)
        bin &= 0x7FFFFFFF;                 // Se asegurara de que se borre el bit de signo
    }

    while (bin > 0) {                 // Itera mientras queden bits por procesar
        int32_t last_bit = bin % 10;  // Extrae el último dígito binario (0 o 1) (Resto de la divicion por 10)
        decimal += last_bit * base;   // Suma su valor en base 10
        base *= 2;                    // Avanza a la siguiente potencia de 2
        bin /= 10;                    // Elimina el último dígito del binario (mueve todo una pocición a la izquierda haciendo que el ultimo digito quede despues de la coma)
    }

    // Si era con signo y negativo, devolver el valor negativo
    if (sign && (binary & 0x80000000)) {
        return -decimal;
    }

    return decimal;  // Retorna el valor decimal positivo
}

int main() {
    int32_t bin = 0b111111111111111111111111111101110; // -18 en binario en complemento a dos
    bool signo = true; // Indica que es un número con signo

    printf("\n--------------------------------------------------------------------------------------------------\n\n");
    printf("Decimal: %d\n", bin2dec(bin, signo)); // Output: -18
    printf("\n--------------------------------------------------------------------------------------------------\n");

    return 0;
}