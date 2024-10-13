#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros;
    int cantidad, i;

    do {
        printf("Ingrese la cantidad de números a almacenar: ");
        scanf("%d", &cantidad);

        
        numeros = (int*)malloc(cantidad * sizeof(int));

        if (numeros == NULL) {
            printf("Error: No se pudo asignar memoria.\n");
            return 1;
        }

       
        printf("Ingrese los números:\n");
        for (i = 0; i < cantidad; i++) {
            scanf("%d", &numeros[i]);
        }

        
        printf("Los números ingresados son:\n");
        for (i = 0; i < cantidad; i++) {
            printf("%d ", numeros[i]);
        }
        printf("\n");

        
        free(numeros);

    } while (cantidad > 0);

    return 0;
}