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
    int num = 0;
    char c;
    printf("\nNúmero de consonantes: ");
    char *cons = "QqWwRrTtYyPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
    for (int digito = 0; digito < len; digito++)
    {
        for (int i = 0; i < 44; i++)
        {
            c = cons[i];
            if (str[digito] == c)
            {
                num++;
            }
        }
    }

    printf("%d", num);
    printf("\n\n-----------------------------------------------------\n");
    return 0;
}