#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    printf("-----------------------------------------------------\n\n");
    
    int arr[] = {12, 5, 8, 21, -4, 9, 0, 17}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Máximo: %d\n", max);
    printf("Mínimo: %d", min);

    printf("\n\n-----------------------------------------------------");

    return 0;
    }