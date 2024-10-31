#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUMNOS 100 




int main() {
    // ... (resto del código)

    int opcion;
    char nombreArchivo[50];

    do {
        // Mostrar menú
        printf("1. Crear alumno\n");
        printf("2. Mostrar alumnos\n");
        printf("3. Guardar alumnos\n");
        printf("4. Cargar alumnos\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearAlumno();
                break;
            case 2:
                printf("Ordenar por:\n");
                printf("1. Matrícula\n");
                printf("2. Calificación\n");
                scanf("%d", &orden);
                mostrarAlumnos(orden);
                break;
            case 3:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombreArchivo);
                guardarAlumnos(nombreArchivo);
                break;
            case 4:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombreArchivo);
                cargarAlumnos(nombreArchivo);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}


struct Alumno {
    int matricula;
    char nombre[50];
    float calificacion;
};
void crearAlumno() {
    struct Alumno nuevoAlumno;

    printf("Ingrese la matrícula: ");
    scanf("%d", &nuevoAlumno.matricula);

    printf("Ingrese el nombre: ");
    scanf("%s", nuevoAlumno.nombre);

    printf("Ingrese la calificación: ");
    scanf("%f", &nuevoAlumno.calificacion);

    alumnos[numAlumnos] = nuevoAlumno;
    numAlumnos++;
}
void mostrarAlumnos(int orden) {
    ordenarAlumnos(orden)

    for (int i = 0; i < numAlumnos; i++) {
        printf("Matrícula: %d\n", alumnos[i].matricula);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Calificación: %.2f\n\n", alumnos[i].calificación);
    }
}
void ordenarAlumnos(int orden) {
    struct Alumno temp;
    for (int i = 0; i < numAlumnos - 1; i++) {
        for (int j = 0; j < numAlumnos - i - 1; j++) {
            if ((orden == 1 && alumnos[j].matricula > alumnos[j + 1].matricula) ||
                (orden == 2 && alumnos[j].calificacion > alumnos[j + 1].calificacion)) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}
void eliminarAlumno(int matricula) {
    int i, pos = -1;

    // Buscar la posición del alumno a eliminar
    for (i = 0; i < numAlumnos; i++) {
        if (alumnos[i].matricula == matricula) {
            pos = i;
            break;
        }
    }

    // Si el alumno fue encontrado, desplazar los elementos y reducir el contador
    if (pos != -1) {
        for (i = pos; i < numAlumnos - 1; i++) {
            alumnos[i] = alumnos[i + 1];
        }
        numAlumnos--;
        printf("Alumno eliminado exitosamente.\n");
    } else {
        printf("Alumno no encontrado.\n");
    }
}
void guardarAlumnos(const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb"); // Abrir archivo en modo escritura binaria

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fwrite(alumnos, sizeof(struct Alumno), numAlumnos, archivo);

    fclose(archivo);
    printf("Datos guardados exitosamente.\n");
}
void cargarAlumnos(const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb"); // Abrir archivo en modo lectura binaria

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    numAlumnos = 0; // Reiniciar el contador de alumnos

    while (fread(&alumnos[numAlumnos], sizeof(struct Alumno), 1, archivo) == 1) {
        numAlumnos++;
    }

    fclose(archivo);
    printf("Datos cargados exitosamente.\n");
}