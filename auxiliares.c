#include "cabecalho.h"

void addChar() {
    if(lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        fprintf(out,">>> ERROR: lexema muito grande\n");
    }
}

void getChar() {
    if((nextChar = getc(in_fp)) != EOF) {
        
        if(nextChar == 10) {
            coluna = 0;
            linha = linha + 1;
        } else {
            coluna = coluna + 1;
        }
        
        if(isupper(nextChar)) {
            nextChar = tolower(nextChar);
        }
        
        if(isalpha(nextChar)) {
            charClass = LETTER;
        } else if (isdigit(nextChar)) {
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
        
    } else {
        
        coluna = coluna + 1;
        charClass = EOF;
    }
}

void getNonBlank() {
    while(isspace(nextChar)) {
        getChar();
    }
}

int fimPalavraReservada() {
    if(charClass == UNKNOWN || nextChar == EOF){
        return 1;
    } else {
        return 0;
    }
}


void ERROR(int tokenEsperado) {
    fprintf(out,"\n>>> ERROR: Esperava algo como %d e obteve %d na linha %d coluna %d\n", 
            tokenEsperado, nextToken, linhaLexema, colunaLexema);
    exit(tokenEsperado);
}