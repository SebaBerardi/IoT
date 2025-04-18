// Extraiga una subcadena de una cadena dada, debe retornar -1 en caso de no encontrarse. (sin usar librerías standard).
#include <stdio.h>
#include <math.h>
#include <string.h>

int find_in_string(char *haystack, char *needle)
{

    int largo_haystack = strlen(haystack);
    int largo_needle = strlen(needle);

    for (int i = 0; i <= largo_haystack - largo_needle; i++)
    {
        for (int j = 0, i2 = i; j < largo_needle && haystack[i2] == needle[j]; j++, i2++)
        {
            if (j == largo_needle - 1)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    char holanda[8] = "holanda";
    printf("Pos: %i\n", find_in_string(holanda, "ola"));
    return 0;
}

