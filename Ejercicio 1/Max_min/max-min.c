#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    printf("\n-----------------------------------------------------");

    char str[21];
    printf("\n\nIngrese los digitos continuamente ");
    scanf("%20s", &str);
    
    int len = strlen(str);
    int max=-10;
    int min=10;
    int valor;

    for ( int digito = len - 1; digito >= 0; digito-- ){
        
        valor = str[digito];
        if (max<valor){
            max= valor;
        }
        if (min>valor){
            min=valor;
        }   
    }

    printf("El valor maximo es %d \n",max);
    printf("El valor maximo es %d \n",min);
    
    printf("\n\n-----------------------------------------------------");
}
