// RA: 2040482513047 - Kauã Sato Sposato

#include <stdio.h>

void trocar(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Antes da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("Endereco de x: %p\n", (void*) &x);
    printf("Endereco de y: %p\n", (void*) &y);

    trocar(&x, &y);

    printf("\nDepois da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("Endereco de x: %p\n", (void*) &x);
    printf("Endereco de y: %p\n", (void*) &y);

    return 0;
}
