#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"
#include "Funcoes.h"

int main(int argc, char** argv) {
    
    //variaveis para controle das filas
    Tipofila filaAtr1, filaAtr2, filaAtr3, filaAtr4;
    Tipofila filaDec1, filaDec2, filaDec3;
    int idpar = 0, idimpar = -1;
    int ciclos, caidos = 0, pousoucom1 = 0;

    //variavel para controle de turnos sendo 0 para decolagem e 1 para aterrissagem
    int turno = 1;

    srand(time(NULL));

    // Criando as filas
    CriaFila(&filaAtr1);
    CriaFila(&filaAtr2);
    CriaFila(&filaAtr3);
    CriaFila(&filaAtr4);
    CriaFila(&filaDec1);
    CriaFila(&filaDec2);
    CriaFila(&filaDec3);

    printf("Digite a quantidade de tempo que deseja: ");
    scanf("%d", &ciclos);

    for (int i = 0; i < ciclos; i++) {
        printf("\n========================\n");
        printf("\nAviões Gerados:\n");
        GeraAviaoDecola(&filaDec1, &filaDec2, &filaDec3, &idpar, i);
        GeraAviaoAterrissa(&filaAtr1, &filaAtr2, &filaAtr3, &filaAtr4, &idimpar, i);
        printf("\n========================\n");
        printf("\nFilas de Decolagen: \n");
        printf("\nFila 1:\n");
        Imprime(filaDec1);
        printf("\nFila 2:\n");
        Imprime(filaDec2);
        printf("\nFila 3:\n");
        Imprime(filaDec3);
        printf("\n========================\n");
        printf("\nFilas de Aterrissagem: \n");
        printf("\nFila 1:\n");
        Imprime(filaAtr1);
        printf("\nFila 2:\n");
        Imprime(filaAtr2);
        printf("\nFila 3:\n");
        Imprime(filaAtr3);
        printf("\nFila 4:\n");
        Imprime(filaAtr4);

        GerenciamentoAeroporto(&filaAtr1, &filaAtr2, &filaAtr3, &filaAtr4, &filaDec1, &filaDec2, &filaDec3, &caidos, &pousoucom1, &turno, i);
        RetiraGasolina(&filaAtr1, &filaAtr2, &filaAtr3, &filaAtr4);
    }

    printf("\n========================\n");

    printf("\nNúmero de aviões caidos: %d.\n", caidos);
    printf("Número de aviões que aterrissaram com 1 de gasolina: %d.\n", pousoucom1);

    CalculaMedia(filaAtr1, filaAtr2, filaAtr3, filaAtr4, filaDec1, filaDec2, filaDec3);

    return (EXIT_SUCCESS);
}