#include "cabecalho.h"

void addChar() {
    if(lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("ERROR - lexema muito grande\n");
    }
}

void getChar() {
    if((nextChar = getc(in_fp)) != EOF) {
        if(nextChar == 10) {
            linha = 0;
            coluna = coluna + 1;
        } else {
            linha = linha + 1;
        }
        if(isalpha(nextChar)) {
            charClass = LETTER;
        } else if (isdigit(nextChar)) {
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
    } else {
        linha = linha + 1;
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
