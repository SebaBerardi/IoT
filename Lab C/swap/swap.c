//int swap(void *elem_1, void *elem_2, size_t data_type)
#include <stdio.h>

int main() {
    int a = 496;
    int b = 0;
    int temp = 0;
    int *p0, *p1;

    printf("Antes del intercambio: x = %d, y = %d\n", a, b);
    p0=&a;
    p1=&b;
    temp = *p0;
    *p0 = *p1;
    *p1 = temp;
    printf("Despues del intercambio: x = %d, y = %d\n", a, b);
    return 0;
}

