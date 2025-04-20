//Intercambie el contenido de dos elementos, deberá retornar si la operacion se realizo con exito (0) o no (-1)

#include <string.h>  // Para memcpy
#include <stdlib.h>  // Para malloc
#include "global.h"

int swap(void *elem_1, void *elem_2, size_t data_type) {
    if (elem_1 == NULL || elem_2 == NULL || data_type == 0) {
        return -1; // Error: punteros nulos o tipo de dato inválido
    }

    
    void *temp = malloc(data_type);
    if (temp == NULL) {
        return -1; 
    }

    // Intercambiar los contenidos
    memcpy(temp, elem_1, data_type);      // temp = *elem_1
    memcpy(elem_1, elem_2, data_type);    // *elem_1 = *elem_2
    memcpy(elem_2, temp, data_type);      // *elem_2 = temp

    free(temp);

    return 0;
}