#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arraylist.c"
typedef struct
{
  int id;
  char description[100];
  int priority;
  char arrival_time[20];
} ticket;
void limpiarPantalla()
{
  system("clear || cls");
}
void mostrarMenuPrincipal()
{
  puts("========================================");
  puts("     Sistema de Gestión ticket");
  puts("========================================");

  puts("1) Registrar ticket");
  puts("2) Asignar prioridad a ticket");
  puts("3) Mostrar lista de ticket pendientes");
  puts("4) Procesar siguiente ticket");
  puts("5) Buscar ticket por ID y mostrar detalles");
  puts("6) Salir");
}

void asignarHora(ticket *p)
{
  time_t aux;
  time(&aux);
  strftime(p->arrival_time, sizeof(p->arrival_time), "%H:%M:%S", localtime(&aux));
}

void registrar_ticket(List *ticket_Baja)
{
  ticket *new_ticket = (ticket *)malloc(sizeof(ticket));
  printf("\nIngrese el ID del ticket: ");
  scanf("%d", &new_ticket->id);

  printf("Ingrese los Descripción del ticket: ");
  scanf(" %[^\n]", new_ticket->description);

  asignarHora(new_ticket);
  new_ticket->priority = 3; // Inicialmente se asigna baja prioridad
  pushBack(ticket_Baja, new_ticket);

  printf("ticket registrado con éxito.\n\n");
  return;
}
void asignar_Prioridad(List *ticket_Alta, List *ticket_Media, List *ticket_Baja)
{
  if (first(ticket_Baja) == NULL)
  {
    printf("No hay tickets\n");
    return;
  }
  int ID_Aux;
  printf("\nIngrese el ID del ticket: ");
  scanf("%d", &ID_Aux);

  ticket *ticket_aux = (ticket *)malloc(sizeof(ticket));
  ticket_aux = first(ticket_Baja);
  while (ticket_aux != NULL)
  {
    if (ticket_aux->id == ID_Aux)
    {
      break;
    }
    ticket_aux = next(ticket_Baja);
  }
  if (ticket_aux == NULL)
  {
    printf("No se encontró el ticket con ID %d.\n", ID_Aux);
    return;
  }
  else
  {
    int nueva_prioridad;
    printf("Ingrese la prioridad del ticket \n1) Alta\n2) Media\n3) Baja\nSeleccione una opción: ");
    scanf("%d", &nueva_prioridad);
    ticket_aux->priority = nueva_prioridad;

    if (nueva_prioridad == 1)
    {
      pushBack(ticket_Alta, ticket_aux);
      popCurrent(ticket_Baja);
      printf("ticket asignado a la lista de alta prioridad.\n\n");
    }
    else if (nueva_prioridad == 2)
    {
      pushBack(ticket_Media, ticket_aux);
      popCurrent(ticket_Baja);
      printf("ticket asignado a la lista de media prioridad.\n\n");
    }
    else
    {
      printf("ticket asignado a la lista de baja prioridad.\n\n");
    }
  }
}
void mostrarPendientes(List *ticket_Alta, List *ticket_Media, List *ticket_Baja)
{
  printf("\nLista de ticket pendientes:\n\n");
  printf("Prioridad Alta:\n");
  ticket *ticket_aux = (ticket *)malloc(sizeof(ticket));

  ticket_aux = first(ticket_Alta);
  while (ticket_aux != NULL)
  {
    printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
    ticket_aux = next(ticket_Alta);
  }

  printf("\nPrioridad Media:\n");
  ticket_aux = first(ticket_Media);
  while (ticket_aux != NULL)
  {
    printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
    ticket_aux = next(ticket_Media);
  }

  printf("\nPrioridad Baja:\n");
  ticket_aux = first(ticket_Baja);
  while (ticket_aux != NULL)
  {
    printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
    ticket_aux = next(ticket_Baja);
  }
  free(ticket_aux);
  printf("\n");
}
void procesar_Siguiente(List *ticket_Alta, List *ticket_Media, List *ticket_Baja)
{
  ticket *ticket_aux = (ticket *)malloc(sizeof(ticket));
  ticket_aux = first(ticket_Alta);
  if (ticket_aux != NULL)
  {
    printf("ticket de alta prioridad:\n");
    printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
    popFront(ticket_Alta);
  }
  else
  {
    ticket_aux = first(ticket_Media);
    if (ticket_aux != NULL)
    {
      printf("ticket de media prioridad:\n");
      printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
      popFront(ticket_Media);
    }
    else
    {
      ticket_aux = first(ticket_Baja);
      if (ticket_aux != NULL)
      {
        printf("ticket de baja prioridad:\n");
        printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
        popFront(ticket_Baja);
      }
      else
      {
        printf("No hay ticket pendientes.\n\n");
      }
    }
  }
  free(ticket_aux);
}
void buscar_ticket(List *ticket_Alta, List *ticket_Media, List *ticket_Baja)
{
  int ID_Aux;
  printf("\nIngrese el ID del ticket:");
  scanf("%d", &ID_Aux);

  ticket *ticket_aux = (ticket *)malloc(sizeof(ticket));
  ticket_aux = first(ticket_Alta);
  while (ticket_aux != NULL)
  {
    if (ticket_aux->id == ID_Aux)
    {
      printf("\nticket encontrado\n");
      printf("Prioridad: Alta\n");
      printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
      return;
    }
    ticket_aux = next(ticket_Alta);
  }
  ticket_aux = first(ticket_Media);
  while (ticket_aux != NULL)
  {
    if (ticket_aux->id == ID_Aux)
    {
      printf("\nticket encontrado\n");
      printf("Prioridad: Media\n");
      printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
      return;
    }
    ticket_aux = next(ticket_Media);
  }
  ticket_aux = first(ticket_Baja);
  while (ticket_aux != NULL)
  {
    if (ticket_aux->id == ID_Aux)
    {
      printf("\nticket encontrado\n");
      printf("Prioridad: Baja\n");
      printf("ID: %d\nDescripción: %s\nHora de llegada: %s\n\n", ticket_aux->id, ticket_aux->description, ticket_aux->arrival_time);
      return;
    }
    ticket_aux = next(ticket_Baja);
  }
  printf("\nNo se encontró el ticket con ID %d.\n", ID_Aux);
  free(ticket_aux);
  printf("\n");
  return;
}
int main()
{
  limpiarPantalla();
  List *ticket_Alta = create_list();
  List *ticket_Media = create_list();
  List *ticket_Baja = create_list();
  int opcion;
  do
  {
    mostrarMenuPrincipal();
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
      registrar_ticket(ticket_Baja);
      break;
    case 2:
      asignar_Prioridad(ticket_Alta, ticket_Media, ticket_Baja);
      break;
    case 3:
      mostrarPendientes(ticket_Alta, ticket_Media, ticket_Baja);
      break;

    case 4:
      procesar_Siguiente(ticket_Alta, ticket_Media, ticket_Baja);
      break;
    case 5:
      buscar_ticket(ticket_Alta, ticket_Media, ticket_Baja);
      break;
    case 6:
      printf("Saliendo del programa...\n");
      break;

    default:
      printf("Opción no válida. Intente nuevamente.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}
