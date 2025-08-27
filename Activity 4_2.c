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
        scanf("%d", arr + i);   // usando aritmética de punteros
    }

    printf("Elementos en orden inverso:\n");
    for(int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i)); // usando aritmética de punteros
    }
    printf("\n");

    free(arr);
    return 0;
}
