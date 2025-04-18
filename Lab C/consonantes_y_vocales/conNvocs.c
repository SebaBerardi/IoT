#include <stdio.h>
#include <stdint.h>
#include <string.h>

int consonantes(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
    printf("\n\nNúmero de consonantes: ");

    char *cons = "BbCcDdFfGgHhJjKkLlMmNnÑñPpQqRrSsTtVvWwXxYyZz";
    
    for (int digito = 0; digito < letras; digito++)
    {
        for (int i = 0; i < 44; i++)
        {
            c = cons[i];
            if (string[digito] == c)
            {
                num++;
            }
        }
    }

    printf("%d", num);
    return 0;
}

int vocales(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
    printf("\n\nNúmero de vocales: ");

    char *voc = "AaEeIiOoUu";
    
    for (int digito = 0; digito < letras; digito++)
    {
        for (int i = 0; i < 10; i++)
        {
            c = voc[i];
            if (string[digito] == c)
            {
                num++;
            }
        }
    }

    printf("%d\n\n\n", num);
    return 0;
}

int main()
{
    char *string = "Hola Como Andas";
    consonantes(string);
    vocales(string);
    return 0;
}
