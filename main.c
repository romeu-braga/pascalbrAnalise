#include "cabecalho.h"

/* um analisador léxico e analisador sintático simples para expressões aritméticas simples */
/* Função principal */
void main() {
    /* Abrir o arquivo de dados de entrada e processar seu conteúdo */
    if((in_fp = fopen("testeanalise.txt", "r")) == NULL)
        printf("ERROR - não foi possível abrir o arquivo\n");
    else {
        getChar();
        do {
            lex();
        } while(nextToken != EOF);
    }
}

