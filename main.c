#include "cabecalho.h"

/* um analisador l�xico e analisador sint�tico simples para express�es aritm�ticas simples */
/* Fun��o principal */
void main() {
    /* Abrir o arquivo de dados de entrada e processar seu conte�do */
    if((in_fp = fopen("testeanalise.txt", "r")) == NULL)
        printf("ERROR - n�o foi poss�vel abrir o arquivo\n");
    else {
        getChar();
        do {
            lex();
        } while(nextToken != EOF);
    }
}

