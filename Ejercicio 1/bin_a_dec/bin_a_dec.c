#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
    
    int bit = 0;
    int valor_final = 0;
    int valor_parcial = 0;

    for ( int digito = 0; digito < 8; digito ++){

        printf("Ingrese el numero en binario digito por digito\n");
        scanf("%d", &bit);

        valor_parcial = bit * pow(2, (digito));
        valor_final = valor_final + valor_parcial;

    }

    printf ("Tu número es %d?",valor_final);
}
