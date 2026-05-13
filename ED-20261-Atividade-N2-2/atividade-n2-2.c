#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

struct No* novoNo(int valor) {
    struct No* no = malloc(sizeof(struct No));

    no->valor = valor;
    no->altura = 0;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

int calcularAltura(struct No* n) {
    int esq;
    int dir;

    if (n == NULL) {
        return -1;
    }

    esq = calcularAltura(n->esq);
    dir = calcularAltura(n->dir);

    if (esq > dir) {
        n->altura = esq + 1;
    } else {
        n->altura = dir + 1;
    }

    return n->altura;
}

int obterFB(struct No* n) {
    if (n == NULL) {
        return 0;
    }

    return calcularAltura(n->esq) - calcularAltura(n->dir);
}

int main() {
    struct No* raiz = novoNo(20);
    struct No* no10 = novoNo(10);
    struct No* no5 = novoNo(5);
    struct No* no2 = novoNo(2);

    raiz->esq = no10;
    no10->esq = no5;
    no5->esq = no2;

    printf("Altura do no 2: %d\n", calcularAltura(no2));
    printf("Altura do no 5: %d\n", calcularAltura(no5));
    printf("Altura do no 10: %d\n", calcularAltura(no10));
    printf("Altura da raiz 20: %d\n", calcularAltura(raiz));

    printf("Fator de balanceamento da raiz: %d\n", obterFB(raiz));

    return 0;
}
