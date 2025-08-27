#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int *arr = (int*) malloc(N * sizeof(int));
    if(arr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    printf("Ingrese %d enteros:\n", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }

    // Calcular suma acumulativa en el mismo arreglo
    for(int i = 1; i < N; i++) {
        *(arr + i) = *(arr + i) + *(arr + i - 1);
    }

    printf("Arreglo transformado (suma acumulativa):\n");
    for(int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}
