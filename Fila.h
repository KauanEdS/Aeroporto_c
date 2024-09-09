#ifndef FILA_H
#define FILA_H

typedef struct {
    int id;
    int gasolina;
    int tempoEntrada; 
} Tipoitem;

typedef struct Tipocelula *Tipoapontador;

typedef struct Tipocelula {
    Tipoitem aviao;
    Tipoapontador prox;
} Tipocelula;

typedef struct {
    Tipoapontador frente, tras;
    int tam;
    int TempoEspera;
    int numAvioes;
} Tipofila;

//======================Funções referentes as filas ======================

//Função cria fila
void CriaFila(Tipofila *fila) ;

//Função para testar se a fila está vazia
int Vazia(Tipofila fila) ;

//Função adicionar um aviao a fila
void Enfileira(Tipoitem x, Tipofila *fila) ;

//Função retirar um aviao da fila
Tipoitem Desenfileira(Tipofila *fila, int loopAtual) ;

//Função para imprimir a fila
void Imprime(Tipofila fila) ;

#endif /* FILA_H */

