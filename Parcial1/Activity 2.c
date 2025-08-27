#include <stdio.h>

int main() {

    int a[5] = {2, 4, 6, 8, 10};

    for (int i = 0; i < 5; i++) {
        printf("Element a[%d] = %d\t Address = %p\n", i, a[i], (void*)&a[i]);
    }

    printf("\nSize of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Array size a[5]: %zu bytes\n", sizeof(a));

    return 0;
}
