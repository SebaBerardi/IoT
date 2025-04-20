#ifndef DAYS_LEFT_H
#define DAYS_LEFT_H

typedef struct {
    int day;
    int month;
    int year;
} date_t;

/**
 * Verifica si un año es bisiesto.
 * @param year Año a evaluar.
 * @return 1 si es bisiesto, 0 en caso contrario.
 */
int is_bisiesto(int year);

/**
 * Obtiene el número de días en un mes específico, considerando años bisiestos.
 * @param month Mes (1-12).
 * @param year Año (para validar febrero en bisiestos).
 * @return Número de días en el mes.
 */
int dias_en_mes(int month, int year);

/**
 * Compara dos fechas.
 * @param a Primera fecha.
 * @param b Segunda fecha.
 * @return -1 si a < b, 0 si son iguales, 1 si a > b.
 */
int compare_dates(date_t a, date_t b);

/**
 * Calcula la diferencia en días entre dos fechas (start y finish).
 * @param start Fecha inicial.
 * @param finish Fecha final.
 * @return Número de días entre las fechas (si start > finish, retorna días negativos).
 */
int days_left(date_t start, date_t finish);

#endif // DAYS_LEFT_H