// Al ingresar dos fechas encuentre la diferencia, en días, entre ellas.

#include "global.h"

int is_bisiesto(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dias_en_mes(int month, int year) {
    switch (month) {
        case 2: return is_bisiesto(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

// Compara dos fechas: retorna -1 si a < b, 0 si iguales, 1 si a > b, para validar si la fecha final es despues de la inicial
int compare_dates(date_t a, date_t b) {
    if (a.year != b.year) return (a.year < b.year) ? -1 : 1;
    if (a.month != b.month) return (a.month < b.month) ? -1 : 1;
    if (a.day != b.day) return (a.day < b.day) ? -1 : 1;
    return 0;
}

// Avanza un día en una fecha
void next_day(date_t *date) {
    date->day++;
    if (date->day > dias_en_mes(date->month, date->year)) {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

int days_left(date_t start, date_t finish) {
    int count = 0;

    // Si start > finish, los intercambiamos
    if (compare_dates(start, finish) > 0) {
        date_t temp = start;
        start = finish;
        finish = temp;
    }

    while (compare_dates(start, finish) != 0) {
        next_day(&start);
        count++;
    }

    return count;
}