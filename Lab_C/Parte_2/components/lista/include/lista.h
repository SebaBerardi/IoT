
#ifndef GLOBAL_H
#define GLOBAL_H


//===================================================================================================================================================================



// Tipos personalizados:

typedef struct Estudiante
{
    char nombre[50];
    char apellido[50];
    int ci;
    int grado;
    float promedio;
    struct Estudiante *siguiente;
} Estudiante;


Estudiante *crearNodo(const char *nombre, const char *apellido, int ci, int grado, float promedio);
int eliminar(Estudiante **primero, int ci_a_eliminar);
void imprimir(const Estudiante *est);
void imprimirLista(const Estudiante *primero);
Estudiante *buscarPorCI(const Estudiante *primero, int ci_a_buscar);
const char *calificacion(float promedio);
void imprimirListaOrdenada(Estudiante *primero, int ordenar_por_ci);
int compararApellido(const void *a, const void *b);
int compararCI(const void *a, const void *b);
int largoLista(const Estudiante *primero);


#endif // GLOBAL_H