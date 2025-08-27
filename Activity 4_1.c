#include <stdio.h>
#include <stdlib.h>

int main() {
    int staticArr[10];                 // Arreglo estático
    int *dynamicArr = (int*) malloc(10 * sizeof(int)); // Arreglo dinámico

    if(dynamicArr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    printf("Direcciones de memoria (Static Array):\n");
    for(int i = 0; i < 10; i++) {
        printf("&staticArr[%d] = %p\n", i, (void*)&staticArr[i]);
    }

    printf("\nDirecciones de memoria (Dynamic Array):\n");
    for(int i = 0; i < 10; i++) {
        printf("&dynamicArr[%d] = %p\n", i, (void*)&dynamicArr[i]);
    }

    free(dynamicArr); // Liberar memoria
    return 0;
}
