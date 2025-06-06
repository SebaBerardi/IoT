#include "lista.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


Estudiante *crearNodo(const char *nombre, const char *apellido, int ci, int grado, float promedio)
{
    Estudiante *nuevo = (Estudiante *)malloc(sizeof(Estudiante));

    strncpy(nuevo->nombre, nombre, sizeof(nuevo->nombre) - 1);
    nuevo->nombre[sizeof(nuevo->nombre) - 1] = '\0';

    strncpy(nuevo->apellido, apellido, sizeof(nuevo->apellido) - 1);
    nuevo->apellido[sizeof(nuevo->apellido) - 1] = '\0';

    nuevo->ci = ci;
    nuevo->grado = grado;
    nuevo->promedio = promedio;
    nuevo->siguiente = NULL;

    return nuevo;
}

const char *calificacion(float promedio)
{
    if (promedio >= 0 && promedio <= 30)
        return "D";
    if (promedio > 30 && promedio <= 60)
        return "R";
    if (promedio > 60 && promedio <= 75)
        return "B";
    if (promedio > 75 && promedio <= 81)
        return "BMB";
    if (promedio > 81 && promedio <= 94)
        return "MB";
    if (promedio > 94 && promedio <= 100)
        return "S";
    return "Inválido";
}

int eliminar(Estudiante **primero, int ci_a_eliminar)
{
    Estudiante *actual = *primero;
    Estudiante *anterior = NULL;

    while (actual != NULL && actual->ci != ci_a_eliminar)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        return 0;
    }

    if (anterior == NULL)
    {
        *primero = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    return 1;
}

void imprimir(const Estudiante *est)
{
    if (est == NULL)
    {
        printf("-----------------------------\n");
        printf("Error: Intentando mostrar un estudiante nulo.\n");
        printf("-----------------------------\n\n");

        return;
    }
    printf("-----------------------------\n");
    printf("Nombre: %s\n", est->nombre);
    printf("Apellido: %s\n", est->apellido);
    printf("CI: %d\n", est->ci);
    printf("Grado: %d\n", est->grado);
    printf("Promedio: %.2f\n", est->promedio);
    printf("Calificación: %s\n", calificacion(est->promedio));
    printf("-----------------------------\n");
}

void imprimirLista(const Estudiante *primero)
{
    printf("\n--- LISTA COMPLETA DE ESTUDIANTES ---\n");
    const Estudiante *actual = primero;
    if (actual == NULL)
    {
        printf("\nLa lista está vacía, no hay nada que imprimir.\n");
    }
    else
    {
        while (actual != NULL)
        {
            imprimir(actual);
            actual = actual->siguiente;
        }
    }
    printf("--------------------------------------\n\n");
}

Estudiante *buscarPorCI(const Estudiante *primero, int ci_a_buscar)
{
    const Estudiante *actual = primero;
    while (actual != NULL)
    {
        if (actual->ci == ci_a_buscar)
        {
            return (Estudiante *)actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

int largoLista(const Estudiante *primero)
{
    int contador = 0;
    const Estudiante *actual = primero;
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

int compararApellido(const void *a, const void *b)
{
    Estudiante *estA = *(Estudiante **)a;
    Estudiante *estB = *(Estudiante **)b;
    return strcmp(estA->apellido, estB->apellido);
}

int compararCI(const void *a, const void *b)
{
    Estudiante *estA = *(Estudiante **)a;
    Estudiante *estB = *(Estudiante **)b;
    if (estA->ci < estB->ci)
        return -1;
    if (estA->ci > estB->ci)
        return 1;
    return 0;
}

void imprimirListaOrdenada(Estudiante *primero, int ordenar_por_ci)
{
    int n = largoLista(primero);
    if (n == 0)
    {
        printf("-----------------------------\n");
        printf("La lista está vacía, no hay nada que ordenar.\n");
        printf("-----------------------------\n\n");
        return;
    }

    Estudiante **array_punteros = (Estudiante **)malloc(n * sizeof(Estudiante *));
    Estudiante *actual = primero;
    int i = 0;
    while (actual != NULL)
    {
        array_punteros[i++] = actual;
        actual = actual->siguiente;
    }

    if (ordenar_por_ci)
    {
        qsort(array_punteros, n, sizeof(Estudiante *), compararCI);
        printf("-----------------------------\n");
        printf("\n--- LISTA ORDENADA POR CI ---\n");
    }
    else
    {
        qsort(array_punteros, n, sizeof(Estudiante *), compararApellido);
        printf("-----------------------------\n");
        printf("\n--- LISTA ORDENADA POR APELLIDO ---\n");
    }

    for (i = 0; i < n; i++)
    {
        imprimir(array_punteros[i]);
    }
    printf("--------------------------------------\n\n");

    free(array_punteros);
}
