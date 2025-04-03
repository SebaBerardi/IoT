#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    printf("\n-----------------------------------------------------");

    char str[21];
    printf("\n\nIngrese una palabra (hasta 20 caracteres):  ");
    scanf("%20s", str); 

    int len = strlen(str);
    int voc = 0;
    printf("\nNúmero de vocales: ");

    for (int digito = 0; digito < len; digito++) {  
        if (str[digito] == 'A' || str[digito] == 'E' || str[digito] == 'I' || str[digito] == 'O' || str[digito] == 'U' ||
            str[digito] == 'a' || str[digito] == 'e' || str[digito] == 'i' || str[digito] == 'o' || str[digito] == 'u') {
            voc++; 
        }
    }

    printf("%d", voc);
    printf("\n\n-----------------------------------------------------\n");

    return 0; 
}
