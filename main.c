#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para la lista
#define MAXCHAR 30
#define TAMANIO_LISTA 50

// Tipo enumerado para el contacto
enum tipoContacto {
    FAVORITO,
    CONOCIDO,
    TRABAJO
};

// Tipo para las personas
typedef struct {
    char nombre[MAXCHAR];
    char apellidos[MAXCHAR];
    int edad;
    enum tipoContacto tipo;
} tipoPersona;

// Tipo para la agenda
typedef struct {
    tipoPersona *personas;
    int numPersonas;
} tipoAgenda;

// Función para creación de la agenda
tipoAgenda creaAgenda();

// Función para imprimir el tipo de contacto
char *imprimeTipoContacto(enum tipoContacto);

// Listado de contactos
void listadoContactos(tipoAgenda);

int main() {

    tipoAgenda agenda = creaAgenda();

    // Menu principal
    int opcion;


    do {
        printf("\n --- MENU --- \n");
        printf("1. Listado de personas\n");
        printf("2. Nueva persona\n");
        printf("3. Borrar persona\n");
        printf("4. Guardar agenda en fichero de texto\n");
        printf("5. Leer agenda de fichero de texto\n");
        printf("0. SALIR\n");

        printf("\nElija una opción: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                listadoContactos(agenda);
                break;
            case 2:
                // Por completar
                //addPersona(&agenda);
                break;
            case 3:
                // Por completar
                // removePersona(&agenda);
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                printf("\nAdios\n");
                break;
            default:
                printf("\nOpcion incorrecta\n");
        }
    } while (opcion != 0);

    // Liberación de memoria antes de terminar
    free(agenda.personas);
}


tipoAgenda creaAgenda() {
    // Creación de agenda
    tipoAgenda agenda;

    // Cero personas
    agenda.numPersonas = 0;
    // Lista inicial de TAMANIO_LISTA
    agenda.personas = malloc(sizeof(tipoPersona) * TAMANIO_LISTA);
    if (agenda.personas == NULL) {
        printf("No hay memoria.");
        agenda.numPersonas = -1;
        return agenda;
    }

    // Adición de una persona (hay que implementar la opción 2 del menu principal(
    strcpy(agenda.personas[0].nombre,"Antoine");
    strcpy(agenda.personas[0].apellidos,"Griezmann");
    agenda.personas[0].edad = 30;
    agenda.personas[0].tipo = CONOCIDO;
    agenda.numPersonas++;

    return agenda;
}

char *imprimeTipoContacto(enum tipoContacto tipo) {
    switch (tipo) {
        case FAVORITO: return "FAVORITO";
        case CONOCIDO: return "CONOCIDO";
        case TRABAJO: return "TRABAJO";
        default: return "Tipo desconocido";
    }
}

void listadoContactos(tipoAgenda agenda) {
    printf("\n");
    for (int i = 0; i < agenda.numPersonas; ++i) {
        printf("%i;%s;%s;%s",i+1, agenda.personas[i].nombre, agenda.personas[i].apellidos,
               imprimeTipoContacto(agenda.personas[i].tipo));
    }
    printf("\n");
}