#include <stdio.h>
#include <stdint.h>
#include <string.h>

void main() //void *array, size_t data_type, size_t array_size
{
    printf("-----------------------------------------------------\n\n");
    

    int array_size=10;
    char arr[array_size];
    char array[]= "Hola mundo";
    strcpy (arr, array);    

    printf("Su array inverso es: ");
    for ( int digito = array_size - 1; digito >= 0; digito-- ){
        printf("%c",arr[digito]);
    }
    
    printf("\n\n-----------------------------------------------------");
}