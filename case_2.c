#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//tipo
typedef struct {
  char DNI[10];
  char Nombre[20];
  char Apellido1[20];
  char Apellido2[20];
  int telefono;
} alumno;

typedef struct {
  char Denominacion[40];
  alumno alumnos[30];
  int numero_alumnos_guardados;
} curso;

typedef struct {
  curso cursos[40];
  int numero_cursos_guardados;
 } escuela;
//ftipo

// algoritmo tratamientoEscuela
int main() {

    escuela e;
    int o;
    
    inicializar_escuela(&e);

    o = menu();
    
    while ((o >=1) && (o <= 4)){
         if (o == 1){
          introducir_curso(&e);
        }

        if (o == 2){
          listar_cursos(e);
          }

        if (o == 3){
          listar_alumnos_curso(e);
        }

        if (o == 4){
          borrar_curso(&e);
        }

        o = menu();
    }

    system("pause");
    return 0;
}
//falgoritmo

// accion
void inicializar_escuela(escuela* e) {
  e->numero_cursos_guardados = 0;
}
//faccion

//funcion menu
int menu() {
  int op;

  printf("****************************************************************\n");
  printf("Teclea el numero de la opcion escogida o cualquier otro numero para salir:\n");
  printf("1. Introducir curso y alumnos del curso.\n");
  printf("2. Listar cursos introducidos.\n");
  printf("3. Listar alumnos de un curso determinado.\n");
  printf("4. Borrar curso y alumnos.\n");
  printf("******************************************************************\n");
  scanf("%d", &op);
  return op;
  }
//ffuncion menu

//accion1
void introducir_curso(escuela* e) {
    if (e->numero_cursos_guardados < 40) {

        curso c;
        int p;
        c.numero_alumnos_guardados = 0;

        printf("Teclea el nombre del curso \n");
        scanf("%s", &c.Denominacion);
        printf("Vas a introducir un nuevo alumno? Teclea 1 si es que si, o 0 si es que no. \n");
        scanf("%d", &p);
        while (p == 1) {
            alumno a;
            printf("Teclea el DNI del alumno \n");
            scanf("%s", a.DNI);
            printf("Teclea el nombre del alumno \n");
            scanf("%s", a.Nombre);
            printf("Teclea el primer apellido del alumno \n");
            scanf("%s", a.Apellido1);
            printf("Teclea el segundo apellido del alumno \n");
            scanf("%s", a.Apellido2);
            printf("Teclea el primer telefono del alumno \n");
            scanf("%d", &a.telefono);
            c.alumnos[c.numero_alumnos_guardados+1] = a;
            c.numero_alumnos_guardados=c.numero_alumnos_guardados+1;
            printf("Vas a introducir un nuevo alumno? Teclea 1 si es que si, o 0 si es que no. \n");
            scanf("%d", &p);
        }
        e->cursos[e->numero_cursos_guardados+1] = c;
        e->numero_cursos_guardados = e->numero_cursos_guardados+1;
    }
}

//accion2
void listar_cursos(escuela e) {
    int i;
    for (i = 1; i <= e.numero_cursos_guardados; i++) {
        printf("\n %s", e.cursos[i].Denominacion);
        printf(" \n Se han guardado ");
        printf(" %d \n", e.cursos[i].numero_alumnos_guardados);
    }
}

//accion3
void listar_alumnos_curso(escuela e) {
    int i, c;

    if (e.numero_cursos_guardados == 0) {
      printf("No hay cursos guardados \n");
    }
    else {
        printf("Indica por su numero que los siguientes cursos de cual quieres listar sus alumnos \n");
        for (i = 1; i <= e.numero_cursos_guardados; i++) {
                printf("%d",i);
                printf(".");
                printf("%s \n", e.cursos[i].Denominacion);
        }
        scanf("%d", &c);

        while ((c < 1) || (c > e.numero_cursos_guardados)) {
            printf("Numero incorrecto.Indica un numero de entre los siguientes. \n");

            for (i = 1; i <= e.numero_cursos_guardados; i++) {
                printf("%d",i);
                printf(".");
                printf("%s \n", e.cursos[i].Denominacion);
            }
            scanf("%d", &c);
        }
        
        printf("Sus alumnos son %d\n", e.cursos[c].numero_alumnos_guardados);
        for (i = 1; i <= e.cursos[c].numero_alumnos_guardados; i++) {
            printf("DNI %s\n", e.cursos[c].alumnos[i].DNI);
            printf("Nombre: %s\n", e.cursos[c].alumnos[i].Nombre);
            printf("Apellido1: %s\n", e.cursos[c].alumnos[i].Apellido1);
            printf("Apellido2: %s\n", e.cursos[c].alumnos[i].Apellido2);
            printf("Telefono: %d\n", e.cursos[c].alumnos[i].telefono);
        }
    }
}

//accion4
void borrar_curso(escuela* e) {
    int i, numero;

    printf("Indica por su número de los siguientes cursos de cual quieres borrar junto con sus alumnos\n");
    
    for (i = 1; i <= e->numero_cursos_guardados; i++) {
          printf("%d",i);
          printf(".");
          printf("%s \n", e->cursos[i].Denominacion);
    }

    scanf("%d", &numero);

    if ((numero > 0) && (numero <= e->numero_cursos_guardados)) {
        while (numero <= e->numero_cursos_guardados) {
            e->cursos[numero] = e->cursos[numero + 1];
            numero = numero +1;
        }
        e->numero_cursos_guardados = e->numero_cursos_guardados-1;
    }
}

