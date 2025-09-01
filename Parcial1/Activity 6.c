#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    int i, j;

    // Leer tamaño de la matriz
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    // Reservar memoria dinámicamente para matrices A, B y C
    int *A = (int*)malloc(rows * cols * sizeof(int));
    int *B = (int*)malloc(rows * cols * sizeof(int));
    int *C = (int*)malloc(rows * cols * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Llenar matriz A y B con números aleatorios entre 0 y 9
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(A + i*cols + j) = rand() % 10;
            *(B + i*cols + j) = rand() % 10;
        }
    }

    // Sumar matrices usando aritmética de punteros
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(C + i*cols + j) = *(A + i*cols + j) + *(B + i*cols + j);
        }
    }

    // Imprimir matriz A
    printf("\nMatrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(A + i*cols + j));
        }
        printf("\n");
    }

    // Imprimir matriz B
    printf("\nMatrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(B + i*cols + j));
        }
        printf("\n");
    }

    // Imprimir resultado C = A + B
    printf("\nMatrix C = A + B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i*cols + j));
        }
        printf("\n");
    }

    // Liberar memoria
    free(A);
    free(B);
    free(C);

    return 0;
}
