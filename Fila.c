#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funcoes.h"

//======================Funções referentes as filas ======================

//Função cria fila
void CriaFila(Tipofila *fila) {
    fila->frente = (Tipoapontador) malloc(sizeof (Tipocelula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
    fila->tam = 0;
    fila->TempoEspera = 0;
    fila->numAvioes = 0;
}

//Função para testar se a fila está vazia
int Vazia(Tipofila fila) {
    return fila.frente == fila.tras;
}

//Função adicionar um aviao a fila
void Enfileira(Tipoitem x, Tipofila *fila) {

    fila->tras->prox = (Tipoapontador) malloc(sizeof (Tipocelula));
    fila->tras = fila->tras->prox;
    fila->tras->aviao = x;
    fila->tras->prox = NULL;
    fila->tam++;
}

//Função retirar um aviao da fila
Tipoitem Desenfileira(Tipofila *fila, int loopAtual) {
    Tipoapontador aux;
    Tipoitem retirado;

    if (Vazia(*fila)) {
        printf("\nErro: a fila está vazia.\n");
        retirado.id = -1; // Indica erro
        retirado.gasolina = -1; // Indica erro
        return retirado;
    }

    aux = fila->frente->prox;
    fila->frente->prox = aux->prox;

    if (fila->frente->prox == NULL) {
        fila->tras = fila->frente;
    }

    retirado = aux->aviao;

    //caso o aviao tenha caido ele não ira contailizar na média
    if (aux ->aviao.gasolina > 0) {

        //calculo do tempo de espera para ser feito a média
        fila->TempoEspera += (loopAtual - retirado.tempoEntrada);
        // Incrementa o contador de aviões que conseguiram decolar ou aterrissar
        fila->numAvioes++; 
    }

    free(aux);
    
    //para saber o tamanho da fila, usado para saber a menor fila onde será adicionado o próximo avião
    fila->tam--;

    return retirado;
}

//Função para imprimir a fila
void Imprime(Tipofila fila) {
    Tipoapontador aux = fila.frente->prox;

    while (aux != NULL) {
        printf("ID: %d, Gasolina: %d\n", aux->aviao.id, aux->aviao.gasolina);
        aux = aux->prox;
    }
}