#include "cabecalho.h"

void main() {
    if((in_fp = fopen("programa.txt", "r")) == NULL) {
        printf("ERROR - não foi possível abrir o arquivo\n");
    }
    else {
        linha = 0;
        coluna = 1;
        getChar();
        do {
            lex();
        } while(nextToken != EOF && nextToken != INVALID_TOKEN); //ele para se o token for invalido. dv 1
    }
}
