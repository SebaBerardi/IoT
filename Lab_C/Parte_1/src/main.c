/*Provar todas las funciones en este archivo, para ejecutar, Ctrl+Shift+P y buscar Tasks: Run Task */

#include "global.h" 
#include <stdio.h>

int main()
{
    int a = bin2dec(0b110,true);
    printf("El valor decimal es: %d\n\n",a);

    char holanda[8] = "holanda";
    printf("Pos: %i\n", find_in_string(holanda, "ola"));

    string_to_caps(holanda);
    printf("TO CAPS: %s\n", holanda);
    string_to_min(holanda);
    printf("TO MIN: %s\n", holanda);

    complex_t ca, cb, cs, cp;
    ca.r = 1;
    ca.i = 2;

    cb.r = 5;
    cb.i = 8;

    cs = sum(ca, ca);
    cp = prod(ca, cb);

    printf("SUM: %f %f\n", cs.r, cs.i);
    printf("PROD: %f %f\n", cp.r, cp.i);

    date_t da, db;
    da.year = 2024;
    da.month = 1;
    da.day = 1;

    db.year = 2025;
    db.month = 6;
    db.day = 23;

    int diff = days_left(da, db);
    printf("DAYS: %d\n", diff);
}