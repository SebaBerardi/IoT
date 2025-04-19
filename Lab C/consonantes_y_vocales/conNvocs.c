// Cuente el número de vocales y consonantes en un string:

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int consonantes(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
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

    return num;
}

int vocales(char *string)
{
    int letras = strlen(string);
    int num = 0;
    char c;
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

    return num;
}