#include "cabecalho.h"

int main() {
    
    out = fopen("resultado.txt","w");
    
    if((in_fp = fopen("programa.txt", "r")) == NULL) {
        fprintf(out,">>> ERROR: não foi possível abrir o arquivo\n");
    }
    else {        
        linha = 1;
        coluna = 0;
        getChar();
        lex();
        programaPascal();
    }
    
    
    return 0;
    
}