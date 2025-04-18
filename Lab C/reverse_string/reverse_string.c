#include <stdio.h>
#include <stdint.h>
#include <string.h>

char *reverse_string(char *string) {
    
    int array_size = strlen (string);    
    
    printf("\n\nSu string inverso es: "); 

    for ( int digito = array_size - 1; digito >= 0; digito-- ){
        printf("%c",string[digito]);
    }

    printf("\n\n\n");
}

int main()
{
    char *string = "Hola mundo";
    *reverse_string(string);
}