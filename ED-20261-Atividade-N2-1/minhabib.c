#include <stdio.h>
#include <stdlib.h>
#include "minhabib.h"

No* criar_no(int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->esq != NULL || raiz->dir != NULL) {
        printf("%d ", raiz->valor);
    }

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("%d ", raiz->valor);
    }

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    if (raiz == NULL) {
        return;
    }

    if (nivel_atual == 0) {
        printf("%d ", raiz->valor);
    } else {
        imprimir_niveis(raiz->esq, nivel_atual - 1);
        imprimir_niveis(raiz->dir, nivel_atual - 1);
    }
}

int calcular_altura(No* no) {
    int esq, dir;

    if (no == NULL) {
        return -1;
    }

    esq = calcular_altura(no->esq);
    dir = calcular_altura(no->dir);

    if (esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL) {
        return -1;
    }

    if (raiz->valor == valor) {
        return profundidade_atual;
    }

    if (valor < raiz->valor) {
        return calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    } else {
        return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
    }
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return;
    }

    printf("%d ", raiz->valor);

    if (valor < raiz->valor) {
        imprimir_ancestrais(raiz->esq, valor);
    } else {
        imprimir_ancestrais(raiz->dir, valor);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL) {
        return;
    }

    imprimir_descendentes(no->esq);

    if (no->valor != 0) {
        printf("%d ", no->valor);
    }

    imprimir_descendentes(no->dir);
}

void analisar_arvore(No* raiz, int valorBusca) {
    No* no;
    int altura;
    int grau = 0;
    int i;

    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    printf("Raiz: %d\n", raiz->valor);

    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    altura = calcular_altura(raiz);

    printf("Niveis:\n");
    for (i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    no = buscar(raiz, valorBusca);

    if (no == NULL) {
        printf("Valor nao encontrado.\n");
        return;
    }

    if (no->esq != NULL) {
        grau++;
    }

    if (no->dir != NULL) {
        grau++;
    }

    printf("\nValor buscado: %d\n", valorBusca);
    printf("Grau: %d\n", grau);

    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    printf("Descendentes/subarvore: ");
    imprimir_descendentes(no);
    printf("\n");

    printf("Altura: %d\n", calcular_altura(no));
    printf("Profundidade: %d\n", calcular_profundidade(raiz, valorBusca, 0));
    printf("Endereco: %p\n", (void*) no);
}
