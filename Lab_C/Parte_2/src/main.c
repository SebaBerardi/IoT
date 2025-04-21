#include "lista.h" 
#include <stdio.h>


void agregar(Estudiante **primero)
{
    char nombre[50];
    char apellido[50];
    int ci;
    int grado;
    float promedio;
    printf("\n--- INGRESO NUEVO ESTUDIANTE ---\n");

    printf("Nombre: ");
    scanf("%s", nombre);

    printf("Apellido: ");
    scanf("%s", apellido);

    printf("CI (solo números): ");
    scanf("%d", &ci);

    printf("Grado: ");
    scanf("%d", &grado);

    printf("Promedio (0-100): ");
    scanf("%f", &promedio);

    Estudiante *nuevo = crearNodo(nombre, apellido, ci, grado, promedio);

    nuevo->siguiente = *primero;
    *primero = nuevo;
    printf("Estudiante agregado correctamente.\n");
    printf("-----------------------------\n\n");
}

int main()
{
    Estudiante *listaEstudiantes = NULL;
    int opcion;
    int ci_busqueda;
    do
    {
        printf("1 - Agregar Estudiante\n");
        printf("2 - Eliminar Estudiante\n");
        printf("3 - Mostrar Estudiante\n");
        printf("4 - Mostrar Lista\n");
        printf("5 - Mostrar Lista Ordenada (Apellido)\n");
        printf("6 - Mostrar Lista Ordenada (CI)\n");
        printf("0 - Salir\n");
        printf("Seleccione una opción: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregar(&listaEstudiantes);
            break;
        case 2:
            if (listaEstudiantes == NULL)
            {
                printf("-----------------------------\n");
                printf("La lista está vacía, no hay estudiante que eliminar.\n");
                printf("-----------------------------\n\n");
            }
            else
            {
                printf("Ingrese la CI del estudiante a eliminar: ");
                scanf("%d", &ci_busqueda);
                if (eliminar(&listaEstudiantes, ci_busqueda))
                {
                    printf("Estudiante con CI %d eliminado correctamente.\n", ci_busqueda);
                }
                else
                {
                    printf("Estudiante con CI %d no encontrado.\n", ci_busqueda);
                }
            }
            break;
        case 3:
            if (listaEstudiantes == NULL)
            {
                printf("-----------------------------\n");
                printf("La lista está vacía, no hay estudiante para buscar.\n");
                printf("-----------------------------\n\n");
            }
            else
            {
                printf("Ingrese la CI del estudiante a buscar: ");
                scanf("%d", &ci_busqueda);
                Estudiante *encontrado = buscarPorCI(listaEstudiantes, ci_busqueda);
                if (encontrado != NULL)
                {
                    printf("\n--- Estudiante Encontrado ---\n");
                    imprimir(encontrado);
                }
                else
                {
                    printf("Estudiante con CI %d no encontrado.\n", ci_busqueda);
                }
            }
            break;
        case 4:
            imprimirLista(listaEstudiantes);
            break;
        case 5:
            imprimirListaOrdenada(listaEstudiantes, 0);
            break;
        case 6:
            imprimirListaOrdenada(listaEstudiantes, 1);
            break;
        case 0:
            break;
        default:
            printf("-----------------------------\n");
            printf("Entrada inválida. Intente de nuevo: \n");
            printf("-----------------------------\n\n");
        }
    } while (opcion != 0);

    return 0;
}
