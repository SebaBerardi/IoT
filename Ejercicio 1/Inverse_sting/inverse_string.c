#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    printf("\n-----------------------------------------------------");

    char str[21];
    printf("\n\nIngrese una palabra: ");
    scanf("%20s", &str);
    
    int len = strlen(str);

    printf("\nPalabra inversa: ");

    for ( int digito = len - 1; digito >= 0; digito-- ){
        printf("%c",str[digito]);
    }
    
    printf("\n\n-----------------------------------------------------");
}

