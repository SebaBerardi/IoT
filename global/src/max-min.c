// Encuentre los elementos máximo y mínimo en un array.

#include <stdio.h>
#include "global.h"

void max_index(void *array, size_t data_type, size_t array_size) {
    if (array == NULL || array_size == 0) {
        printf("Array inválido.\n");
        return;
    }

    char *ptr = (char *)array; //configuro punteros
    int max_val = *(int *)ptr;
    size_t max_pos = 0;

    for (size_t i = 1; i < array_size; i++) {//recorro el array guardando cada vez el valor mas grande hasta el momento
        int current = *(int *)(ptr + i * data_type);
        if (current > max_val) {
            max_val = current;
            max_pos = i;
        }
    }

    printf("Máximo: %d en la posición %zu\n", max_val, max_pos);
}

void min_index(void *array, size_t data_type, size_t array_size) { 
    if (array == NULL || array_size == 0) {
        printf("Array inválido.\n");
        return;
    }

    char *ptr = (char *)array; //configuro punteros
    int min_val = *(int *)ptr;
    size_t min_pos = 0;

    for (size_t i = 1; i < array_size; i++) { //recorro el array guardando cada vez el valor mas chico hasta el momento
        int current = *(int *)(ptr + i * data_type);
        if (current < min_val) {
            min_val = current;
            min_pos = i;
        }
    }

    printf("Mínimo: %d en la posición %zu\n", min_val, min_pos);
}