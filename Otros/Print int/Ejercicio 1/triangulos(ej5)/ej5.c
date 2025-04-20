#include <stdio.h>
#include <stdint.h>
int main(){
    int a = 30;
    int b = 30;
    int c = 30;
    char tipo;

    if (a == b || a==c || b==c)
    {
        tipo = 'B';
    }
    if (a == b && a == c && b == c)
    {
        tipo = 'A';
    }
    switch (tipo)
    {
    case 'A':
        printf("Equilatero\n");
        break;
    case 'B':
        printf("Isosceles\n");
        break;
    default:
        printf("Escaleno\n");
    }
    return 0;
}
