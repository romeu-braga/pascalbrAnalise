#include "cabecalho.h"

/* lex - um analisador léxico simples para expressões aritméticas */
int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
    //reconhecer identificadores
    case LETTER :
        addChar();
        getChar();
        while(charClass == LETTER || charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = IDENT;
        break;
    //reconhecer literais inteiros
    case DIGIT :
        addChar();
        getChar();
        while(charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;
    //parênteses e operadores
    case UNKNOWN :
        lookup(nextChar);
        getChar();
        break;
    case EOF :
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    }

    printf("next token is: %d, next lexeme is %s\n", nextToken, lexeme);
    return nextToken;

}
