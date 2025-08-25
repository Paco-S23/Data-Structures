#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // Máximo de ventas a leer

// Comparador para orden ascendente
int cmpAsc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x - y);
}

// Comparador para orden descendente
int cmpDesc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (y - x);
}

int main(void) {
    FILE *fp;
    int sales[MAX];
    int n = 0;

    // Abrir archivo
    fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        perror("Error al abrir sales.txt");
        return EXIT_FAILURE;
    }

    // Leer números
    while (n < MAX && fscanf(fp, "%d", &sales[n]) == 1) {
        n++;
    }
    fclose(fp);

    if (n == 0) {
        printf("El archivo está vacío o no contiene números válidos.\n");
        return EXIT_FAILURE;
    }

    // Copias para ordenar
    int *asc = malloc(n * sizeof(int));
    int *desc = malloc(n * sizeof(int));
    if (!asc || !desc) {
        perror("Error al reservar memoria");
        free(asc);
        free(desc);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        asc[i] = sales[i];
        desc[i] = sales[i];
    }

    qsort(asc, n, sizeof(int), cmpAsc);
    qsort(desc, n, sizeof(int), cmpDesc);

    // Imprimir tabla
    printf("\n%-15s %-15s %-15s\n", "Original", "Ascendente", "Descendente");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-15d %-15d %-15d\n",
               sales[i],
               asc[i],
               desc[i]);
    }

    // Liberar memoria
    free(asc);
    free(desc);

    return EXIT_SUCCESS;
}
