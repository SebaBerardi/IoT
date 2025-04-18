#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int main() //int32_t binary, bool sign
{
    printf("\n\n-----------------------------------------------------\n\n");
    
    
    char bin[] = "111100101101101110001";
    //strcpy(bin,binary)
    int valor_final = 0;
    int valor_parcial = 0;
    int signo = 1; //bool sign

    int len = strlen(bin);    

    for ( int bit = 0; bit+1 <= len; bit++ ){

        if (bin[bit] == '1'){
            printf("%d; " ,len-1-bit);
            printf("%c\n",bin[bit]);
            valor_parcial = 1 * pow(2, (len-1-bit));
            valor_final = valor_final + valor_parcial;
        }
        else {
            valor_final = valor_final + 0;
        }
    }
    if (signo == '1'){
        printf ("\nTu número es -%d?",valor_final);
    }
    else{
        printf ("\nTu número es %d?",valor_final);
    }
    
    
    printf("\n\n-----------------------------------------------------\n\n");
    
}
