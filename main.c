#include "cabecalho.h"

void main() {
    
    out = fopen("resultado.txt","w");
    
    if((in_fp = fopen("programa2.txt", "r")) == NULL) {
        fprintf(out,">>> ERROR: não foi possível abrir o arquivo\n");
    }
    else {        
        linha = 1;
        coluna = 0;
        getChar();
        lex();
        programaPascal();
    }
}