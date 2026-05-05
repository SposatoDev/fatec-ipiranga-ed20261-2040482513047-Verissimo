#include <stdio.h>
#include "minhabib.h"

No* inserir(No* raiz, int valor);

int main() {
    No* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    int valorBusca;

    for (i = 0; i < 7; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Digite o valor para buscar: ");
    scanf("%d", &valorBusca);

    analisar_arvore(raiz, valorBusca);

    return 0;
}
