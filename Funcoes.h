#ifndef FUNCOES_H
#define FUNCOES_H

//======================Funções referentes aos aviões ======================

//compara qual a menor fila para adicionar um avião
int MenorFilaDecolagem(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3) ;

//compara qual a menor fila para adicionar um avião
int MenorFilaAterrissagem(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4) ;

//gera avioes para decolagem
void GeraAviaoDecola(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, int *id_par, int loopAtual) ;

//gera avioes para aterrissagem
void GeraAviaoAterrissa(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4, int *id_impar, int loopAtual) ;

//função que gerencia qual avião vai aterrisar e qual vai decolar
void GerenciamentoAeroporto(Tipofila *filaater1, Tipofila *filaater2, Tipofila *filaater3, Tipofila *filaater4, Tipofila *filadecol1, Tipofila *filadecol2, Tipofila *filadecol3, int *caidos, int *pousoucom1, int *turno, int loopAtual) ;

//Função que tira a gasolina dos avioes a cada loop
void RetiraGasolina(Tipofila *fila1, Tipofila *fila2, Tipofila *fila3, Tipofila *fila4) ;

//Fução que calcula a media de espera das filas, printando a media e o numero de avioes 
void CalculaMedia(Tipofila filaAtr1, Tipofila filaAtr2, Tipofila filaAtr3, Tipofila filaAtr4, Tipofila filaDec1, Tipofila filaDec2, Tipofila filaDec3);


#endif /* FUNCOES_H */

