#include <stdio.h>
#include <math.h>
#include <string.h>

// Lea una oración y reemplace los caracteres en minúsculas con mayúsculas o viceversa según
// decida el usuario. (sin usar librerías standard):
void string_to_caps(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}

void string_to_min(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

int main()
{
    char holanda[8] = "holanda";
    
    string_to_caps(holanda);
    printf("TO CAPS: %s\n", holanda);
    string_to_min(holanda);
    printf("TO MIN: %s\n", holanda);

}