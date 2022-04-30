#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarea{

    int tareaId;        // Numerado en el ciclo iterativo.
    char *descripcion;  // Descripcion de tarea.
    int duracion;       // Entre 10 - 100.

}typedef tarea;

void imprimirTarea(tarea tarea);

int main(){

    short numTareas = 0, check = 0, realizado = 0;
    tarea** listaTarea;
    tarea** tareasRealizadas;
    char* buffer;

    buffer = (char*) malloc(50*sizeof(char));

    printf("\n====================== [TAREAS] ======================\n");

    printf("\n CARGA DE TAREAS: \n");

    do
    {
        printf("\n Cargue la cantidad de tareas: ");
        scanf("%hd", &numTareas);
        fflush(stdin);

    } while (numTareas <= 0);
    
    listaTarea = (tarea**) malloc(sizeof(tarea*)*numTareas);

    for (short i = 0; i < numTareas; i++)
    {
        listaTarea[i] = (tarea*) malloc(sizeof(tarea));
        listaTarea[i]->tareaId = i+1;

        printf("\n - Inserte la descripcion de la tarea[%hd]: ", i+1);
        gets(buffer);
        fflush(stdin);

        listaTarea[i]->descripcion = (char*) malloc(strlen(buffer)+1);

        strcpy(listaTarea[i]->descripcion, buffer);

        do
        {
            printf("\n   Inserte la duracion de la tarea: ");
            scanf("%d", &(listaTarea[i]->duracion) );
            fflush(stdin);

        } while (listaTarea[i]->duracion <= 10 || listaTarea[i]->duracion > 90);
        
    }

    printf("\n---------------------------------------------------------\n");

    printf("\n CONTROL DE TAREAS: \n");

    tareasRealizadas = (tarea**) malloc(sizeof(tarea*)*numTareas);

    for (short j = 0; j < numTareas; j++)
    {

        imprimirTarea(*listaTarea[j]);

        do
        {
            printf("\n\n Es la tarea [%d] terminada?: ", j + 1);
            scanf("%hd", &check);

        } while (check != 0 && check != 1);

        if (check == 1)
        {

            tareasRealizadas[realizado] = listaTarea[j];
            listaTarea[j] = NULL;

            realizado++;
        }
        
    }

    printf("\n---------------------------------------------------------\n");

    printf("\n MOSTRAR TAREAS REALIZADAS Y PENDIENTES: \n");

    printf("\n Tareas pendinetes: \n");

    for (short i = 0; i < numTareas; i++)
    {
        if (listaTarea[i] != NULL)
        {
            imprimirTarea(*listaTarea[i]);
        }
    }

    printf("\n\n Tareas realizadas: \n");
    
    for (short j = 0; j < realizado; j++)
    {
        imprimirTarea(*tareasRealizadas[j]);
    }
    

    free(buffer);

    return 0;
}

void imprimirTarea(tarea tarea){

    printf("\n - Tarea numero [%d]: ", tarea.tareaId);
    printf("\n   Descripcion: ");
    puts(tarea.descripcion);
    printf("   Duracion: %d", tarea.duracion);

}