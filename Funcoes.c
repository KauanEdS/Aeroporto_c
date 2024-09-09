#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"


//======================Funções referentes aos aviões ======================


//compara qual a menor fila para adicionar um avião
int MenorFilaDecolagem(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3) {
    Tipofila *aux = fila1;
    int fila = 1;

    if (fila2->tam < aux->tam) {
        aux = fila2;
        fila = 2;
    }
    if (fila3->tam < aux->tam) {
        aux = fila3;
        fila = 3;
    }

    //retorna qual a menor fila
    return fila;
}

//compara qual a menor fila para adicionar um avião
int MenorFilaAterrissagem(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4) {
    Tipofila *aux = fila1;
    int fila = 1;

    if (fila2->tam < aux->tam) {
        aux = fila2;
        fila = 2;
    }
    if (fila3->tam < aux->tam) {
        aux = fila3;
        fila = 3;
    }
    if (fila4->tam < aux->tam) {
        aux = fila4;
        fila = 4;
    }

    //retorna qual a menor fila
    return fila;
}

//gera avioes para decolagem
void GeraAviaoDecola(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, int *id_par, int loopAtual) {
    int fila;
    Tipoitem Aviao;
    int Num_gerado;

    //Usa a geração de número aleatório para gerar um numero de 0 a 3 
    Num_gerado = (rand() % 4);

    printf("Foi gerado %d aviaões para a pista de decolagem\n", Num_gerado);

    
    //for para atribuir os valores aos aviões
    for (int i = 0; i < Num_gerado; i++) {
        (*id_par) += 2;
        Aviao.id = *id_par;
        Aviao.gasolina = 20;
        Aviao.tempoEntrada = loopAtual;
        
        //busca a menor fila e adiciona o avião 
        fila = MenorFilaDecolagem(fila1, fila2, fila3);

        if (fila == 1) {
            Enfileira(Aviao, fila1);
        } else if (fila == 2) {
            Enfileira(Aviao, fila2);
        } else {
            Enfileira(Aviao, fila3);
        }
    }
}

//gera avioes para aterrissagem
void GeraAviaoAterrissa(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4, int *id_impar, int loopAtual) {
    int fila;
    Tipoitem Aviao;
    int Num_gerado;

    //Usa a geração de número aleatório para gerar um numero de 0 a 3 
    Num_gerado = (rand() % 4);

    printf("Foi gerado %d aviaões para a pista de aterrissagem\n", Num_gerado);

    //for para atribuir os valores aos aviões
    for (int i = 0; i < Num_gerado; i++) {
        (*id_impar) += 2;
        Aviao.id = *id_impar;
        
       //Usa a geração de numero aleatório para gerar um numero de 1 a 20 referente a gasolina 
        Aviao.gasolina = (rand() % 20) + 1;
        Aviao.tempoEntrada = loopAtual;
        
        //busca a menor fila e adiciona o avião 
        fila = MenorFilaAterrissagem(fila1, fila2, fila3, fila4);

        if (fila == 1) {
            Enfileira(Aviao, fila1);
        } else if (fila == 2) {
            Enfileira(Aviao, fila2);
        } else if (fila == 3) {
            Enfileira(Aviao, fila3);
        } else {
            Enfileira(Aviao, fila4);
        }
    }
}

//Função que gerencia quais aviões vão aterrisar e quais vão decolar
void GerenciamentoAeroporto(Tipofila *filaater1, Tipofila *filaater2, Tipofila *filaater3, Tipofila *filaater4, Tipofila *filadecol1, Tipofila *filadecol2, Tipofila *filadecol3, int *caidos, int *pousoucom1, int *turno, int loopAtual) {

    //mostra em qual ciclo está, sendo 1 para decolagem e 0 para aterrissagem
    if ((*turno) == 1) {
        printf("\n\n ====================== Turno decolagem ====================== \n");
        (*turno)--;
    } else {
        printf("\n\n====================== Turno aterrissagem ======================\n");
        (*turno)++;
    }

    //variavel para saber quem desceu ou subiu
    Tipoitem aviao;

    // Verifica em todas as filas de aterrissagem se algum avião caiu por falta de gasolina
    
    if (!Vazia(*filaater1) && filaater1->frente->prox->aviao.gasolina < 1) {
        aviao = Desenfileira(filaater1, loopAtual);
        printf("\nAvião com Id: %d caiu\n", aviao.id);
        (*caidos)++;
    }
    if (!Vazia(*filaater2) && filaater2->frente->prox->aviao.gasolina < 1) {
        aviao = Desenfileira(filaater2, loopAtual);
        printf("\nAvião com Id: %d caiu\n", aviao.id);
        (*caidos)++;
    }
    if (!Vazia(*filaater3) && filaater3->frente->prox->aviao.gasolina < 1) {
        aviao = Desenfileira(filaater3, loopAtual);
        printf("\nAvião com Id: %d caiu\n", aviao.id);
        (*caidos)++;
    }
    if (!Vazia(*filaater4) && filaater4->frente->prox->aviao.gasolina < 1) {
        aviao = Desenfileira(filaater4, loopAtual);
        printf("\nAvião com Id: %d caiu\n", aviao.id);
        (*caidos)++;
    }

    //Váriaveis para pista, sendo 0 igual a vazio e 1 igual a ocupado
    int Pista1 = 0;
    int Pista2 = 0;
    int Pista3 = 0;

    //flags para controle das filas
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;

    // Verifica se existe algum avião com 1 de combustivel e aterrissa na pista 3
    if (!Vazia(*filaater1) && filaater1->frente->prox->aviao.gasolina == 1) {
        aviao = Desenfileira(filaater1, loopAtual);
        printf("\nAvião da fila 1 Id: %d aterrissou com %d de gasolina na pista 3\n", aviao.id, aviao.gasolina);
        Pista3 = 1;
        flag1 = 1;
        (*pousoucom1)++;
    }
    if (!Vazia(*filaater2) && filaater2->frente->prox->aviao.gasolina == 1 && Pista3 == 0) {
        aviao = Desenfileira(filaater2, loopAtual);
        printf("\nAvião da fila 2 Id: %d aterrissou com %d de gasolina na pista 3\n", aviao.id, aviao.gasolina);
        Pista3 = 1;
        flag2 = 1;
        (*pousoucom1)++;
    }
    if (!Vazia(*filaater3) && filaater3->frente->prox->aviao.gasolina == 1 && Pista3 == 0) {
        aviao = Desenfileira(filaater3, loopAtual);
        printf("\nAvião da fila 3 Id: %d aterrissou com %d de gasolina na pista 3\n", aviao.id, aviao.gasolina);
        Pista3 = 1;
        flag3 = 1;
        (*pousoucom1)++;
    }
    if (!Vazia(*filaater4) && filaater4->frente->prox->aviao.gasolina == 1 && Pista3 == 0) {
        aviao = Desenfileira(filaater4, loopAtual);
        printf("\nAvião da fila 4 Id: %d aterrissou com %d de gasolina na pista 3\n", aviao.id, aviao.gasolina);
        Pista3 = 1;
        flag4 = 1;
        (*pousoucom1)++;
    }
    if (Pista3 == 0) {
        if (!Vazia(*filadecol3)) {
            Pista3 = 1;
            aviao = Desenfileira(filadecol3, loopAtual);
            printf("\nAvião da fila 3 Id: %d decolou com %d de gasolina na pista 3 \n", aviao.id, aviao.gasolina);
        } else {
            printf("\nNão foi encontrado aviões nas filas destinados a pista 3\n");
        }
    }

    // Verifica o turno se é a vez de decolagem ou aterrissagem. Verifica se as filas estão vazias. Verifica usando flag se alguma fila já foi utilizada
    if ((*turno) == 0) {
        
        
        if (!Vazia(*filadecol1)) {
            Pista1 = 1;
            aviao = Desenfileira(filadecol1, loopAtual);
            printf("\nAvião da fila 1 Id: %d decolou com %d de gasolina na pista 1\n", aviao.id, aviao.gasolina);
        } else {
            printf("\nNão foi encontrado aviões nas filas destinados a pista 1\n");
        }
        
    } else if (!Vazia(*filaater1) && !Vazia(*filaater2)) {
        if ((filaater1->frente->prox->aviao.gasolina < filaater2->frente->prox->aviao.gasolina && flag1 == 0) || (flag2 == 1 && flag1 == 0)) {
            Pista1 = 1;
            flag1 = 1;
            aviao = Desenfileira(filaater1, loopAtual);
            printf("\nAvião da fila 1 Id: %d aterrissou com %d de gasolina na pista 1\n", aviao.id, aviao.gasolina);
        } else {
            Pista1 = 1;
            flag2 = 1;
            aviao = Desenfileira(filaater2, loopAtual);
            printf("\nAvião da fila 2 Id: %d aterrissou com %d de gasolina na pista 1\n", aviao.id, aviao.gasolina);
        }
    } else if ((!Vazia(*filaater1) && Vazia(*filaater2)) && flag1 == 0) {
        Pista1 = 1;
        flag1 = 1;
        aviao = Desenfileira(filaater1, loopAtual);
        printf("\nAvião da fila 1 Id: %d aterrissou com %d de gasolina na pista 1\n", aviao.id, aviao.gasolina);
    } else if ((Vazia(*filaater1) && !Vazia(*filaater2)) && flag2 == 0) {
        Pista1 = 1;
        flag2 = 1;
        aviao = Desenfileira(filaater2, loopAtual);
        printf("\nAvião da fila 2 Id: %d aterrissou com %d de gasolina na pista 1\n", aviao.id, aviao.gasolina);
    } else {
        printf("\nNão foi encontrado aviões nas filas destinados a pista 1\n");
    }

    // Verifica o turno se é a vez de decolagem ou aterrissagem. Verifica se as filas estão vazias. Verifica usando flag se alguma fila já foi utilizada
    if ((*turno) == 0) {
        if (!Vazia(*filadecol2)) {
            Pista2 = 1;
            aviao = Desenfileira(filadecol2, loopAtual);
            printf("\nAvião da fila 2 Id: %d decolou com %d de gasolina na pista 2\n", aviao.id, aviao.gasolina);
        } else {
            printf("\nNão foi encontrado aviões nas filas destinados a pista 2\n");
        }
    } else if (!Vazia(*filaater3) && !Vazia(*filaater4)) {
        if ((filaater3->frente->prox->aviao.gasolina < filaater4->frente->prox->aviao.gasolina && flag3 == 0) || (flag4 == 1 && flag3 == 0)) {
            Pista2 = 1;
            flag3 = 1;
            aviao = Desenfileira(filaater3, loopAtual);
            printf("\nAvião da fila 3 Id: %d aterrissou com %d de gasolina na pista 2\n", aviao.id, aviao.gasolina);
        } else {
            Pista2 = 1;
            flag4 = 1;
            aviao = Desenfileira(filaater4, loopAtual);
            printf("\nAvião da fila 4 Id: %d aterrissou com %d de gasolina na pista 2\n", aviao.id, aviao.gasolina);
        }
    } else if ((!Vazia(*filaater3) && Vazia(*filaater4)) && flag3 == 0) {
        Pista2 = 1;
        flag3 = 1;
        aviao = Desenfileira(filaater3, loopAtual);
        printf("\nAvião da fila 3 Id: %d aterrissou com %d de gasolina na pista 2\n", aviao.id, aviao.gasolina);
    } else if ((Vazia(*filaater3) && !Vazia(*filaater4)) && flag4 == 0) {
        Pista2 = 1;
        flag4 = 1;
        aviao = Desenfileira(filaater4, loopAtual);
        printf("\nAvião da fila 4 Id: %d aterrissou com %d de gasolina na pista 2\n", aviao.id, aviao.gasolina);
    } else {
        printf("\nNão foi encontrado aviões nas filas destinados a pista 2\n");
    }

}

//Função que tira a gasolina dos avioes a cada loop
void RetiraGasolina(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4) {
    Tipoapontador aux;

    // Percorre e retira gasolina da fila1
    aux = fila1->frente->prox;
    while (aux != NULL) {
        if (aux->aviao.gasolina > 0) {
            //retira 1 de gasolina
            aux->aviao.gasolina--; 
        }
        // Move para o próximo elemento da fila
        aux = aux->prox; 
    }

    // Percorre e retira gasolina da fila2
    aux = fila2->frente->prox;
    while (aux != NULL) {
        if (aux->aviao.gasolina > 0) {
            //retira 1 de gasolina
            aux->aviao.gasolina--;
        }
        // Move para o próximo elemento da fila
        aux = aux->prox; 
    }

    // Percorre e retira gasolina da fila3
    aux = fila3->frente->prox;
    while (aux != NULL) {
        if (aux->aviao.gasolina > 0) {
            //retira 1 de gasolina
            aux->aviao.gasolina--;
        }
        // Move para o próximo elemento da fila
        aux = aux->prox; 
    }

    // Percorre e retira gasolina da fila4
    aux = fila4->frente->prox;
    while (aux != NULL) {
        if (aux->aviao.gasolina > 0) {
            //retira 1 de gasolina
            aux->aviao.gasolina--;
        }
        // Move para o próximo elemento da fila
        aux = aux->prox; 
    }
}

//Fução que calcula a media de espera das filas, printando a media e o numero de avioes 
void CalculaMedia(Tipofila filaAtr1, Tipofila filaAtr2, Tipofila filaAtr3, Tipofila filaAtr4, Tipofila filaDec1, Tipofila filaDec2, Tipofila filaDec3) {
    
    //Váriaveis para o calculo de tempo de espera de cada fila
    float mediaAtr1 = 0, mediaAtr2 = 0, mediaAtr3 = 0, mediaAtr4 = 0;
    float mediaDec1 = 0, mediaDec2 = 0, mediaDec3 = 0;

    //Váriaveis para o calculo de tempo de espera em geral de decolagem e aterrissagem 
    float mediaAtr = 0, mediaDec = 0;
    
     //Váriaveis para o calculo do numero total de decolagem e aterrissagem 
    int NumDeco = 0, NumAtr = 0;

    //Verifica se alguma fila nuca recebeu avião para que não ocorra divisão por 0
    if (filaAtr1.numAvioes > 0 && filaAtr2.numAvioes > 0 && filaAtr3.numAvioes > 0 && filaAtr4.numAvioes > 0) {

        mediaAtr1 = ((float) filaAtr1.TempoEspera / filaAtr1.numAvioes);
        mediaAtr2 = ((float) filaAtr2.TempoEspera / filaAtr2.numAvioes);
        mediaAtr3 = ((float) filaAtr3.TempoEspera / filaAtr3.numAvioes);
        mediaAtr4 = ((float) filaAtr4.TempoEspera / filaAtr4.numAvioes);

        mediaAtr = (mediaAtr1 + mediaAtr2 + mediaAtr3 + mediaAtr4) / 4;
        NumAtr = filaAtr1.numAvioes + filaAtr2.numAvioes + filaAtr3.numAvioes + filaAtr4.numAvioes;

        printf("\nNúmero de aviões que conseguiram aterrissar: %d.\n", NumAtr);
        printf("Tempo médio de espera por fila de aterrissagem: %f.\n", mediaAtr);
    } else {
        printf("\nNão foram gerados aviões o suficiente para fazer uma média.\n");
    }

    if (filaDec1.numAvioes > 0 && filaDec2.numAvioes > 0 && filaDec3.numAvioes > 0) {

        mediaDec1 = ((float) filaDec1.TempoEspera / filaDec1.numAvioes);
        mediaDec2 = ((float) filaDec2.TempoEspera / filaDec2.numAvioes);
        mediaDec3 = ((float) filaDec3.TempoEspera / filaDec3.numAvioes);

        mediaDec = (mediaDec1 + mediaDec2 + mediaDec3) / 3;
        NumDeco = filaDec1.numAvioes + filaDec2.numAvioes + filaDec3.numAvioes;

        printf("\nNúmero de aviões que conseguiram decolar: %d.\n", NumDeco);
        printf("Tempo médio de espera por fila de decolagem: %f.\n", mediaDec);
    } else {
        printf("\nNão foram gerados aviões o suficiente para fazer uma média.\n");
    }

}