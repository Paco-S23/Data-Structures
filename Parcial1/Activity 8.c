#include <stdio.h>

#define MAX 100

void printMatrix(int arr[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillNormal(int arr[MAX][MAX], int n, int m) {
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = val++;  // llena con valores consecutivos
        }
    }
}

void fillSpiral(int arr[MAX][MAX], int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int val = 1;

    while (top <= bottom && left <= right) {
        // Fila superior
        for (int i = left; i <= right; i++) {
            arr[top][i] = val++;
        }
        top++;

        // Columna derecha
        for (int i = top; i <= bottom; i++) {
            arr[i][right] = val++;
        }
        right--;

        // Fila inferior
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                arr[bottom][i] = val++;
            }
            bottom--;
        }

        // Columna izquierda
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                arr[i][left] = val++;
            }
            left++;
        }
    }
}

int main() {
    int n, m;
    int arr[MAX][MAX];

    printf("Ingrese el numero de filas (N): ");
    scanf("%d", &n);
    printf("Ingrese el numero de columnas (M): ");
    scanf("%d", &m);

    // Llenar matriz normal
    fillNormal(arr, n, m);

    printf("Matriz original:\n");
    printMatrix(arr, n, m);

    // Llenar en espiral
    fillSpiral(arr, n, m);

    printf("Matriz en espiral:\n");
    printMatrix(arr, n, m);

    return 0;
}
