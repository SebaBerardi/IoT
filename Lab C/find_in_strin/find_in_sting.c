// Extraiga una subcadena de una cadena dada, debe retornar -1 en caso de no encontrarse. (sin usar librerías standard).

int find_in_string(char *haystack, char *needle)
{
    // Calcular largo de haystack
    int largo_haystack = 0;
    while (haystack[largo_haystack] != '\0') {
        largo_haystack++;
    }

    // Calcular largo de needle
    int largo_needle = 0;
    while (needle[largo_needle] != '\0') {
        largo_needle++;
    }

    // Si needle está vacío, retornar 0 (como strstr)
    if (largo_needle == 0) {
        return 0;
    }

    // Búsqueda principal
    for (int i = 0; i <= largo_haystack - largo_needle; i++)
    {
        int encontrado = 1;
        for (int j = 0; j < largo_needle; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                encontrado = 0;
                break;
            }
        }
        if (encontrado) {
            return i;
        }
    }

    return -1;
}