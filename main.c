#include "cabecalho.h"

void main() {
    if((in_fp = fopen("programa.txt", "r")) == NULL) {
        printf("ERROR - não foi possível abrir o arquivo\n");
    }
    else {
        linha = 0;
        coluna = 1;
        getChar();
        lex();
        programaPascal();
    }
}
