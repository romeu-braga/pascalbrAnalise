#include "cabecalho.h"

int lex() {
    lexLen = 0;
    getNonBlank();
    int linhaLexema = linha;
    int colunaLexema = coluna;

    switch (charClass) {
    case LETTER :
        switch(nextChar) {
            case 'p' :
                addChar();
                getChar();
                if(nextChar == 'r') {
                    recPRograma();
                } else if(nextChar == 'a') {
                    recPAra();
                } else {
                    recIdentificador();
                }
                break;
            case 'i' :
                addChar();
                getChar();
                if(nextChar == 'n') {
                    recIN();
                } else {
                    recIdentificador();
                }
                break;
            case 'f' :
                addChar();
                getChar();
                if(nextChar == 'a') {
                    recFAca();
                } else if(nextChar == 'i') {
                    recFIm();
                } else {
                    recIdentificador();
                }
                break;
            case 's' :
                addChar();
                getChar();
                if(nextChar == 'e') {
                    addChar();
                    getChar();
                    nextToken = SE_CODE;
                    if(nextChar == 'n') {
                        recSeNao();
                    }
                } else {
                    recIdentificador();
                }
                break;
            case 'e' :
                addChar();
                getChar();
                if(nextChar == 'n') {
                    recEN();
                } else if(nextChar == 's') {
                    recEScolha();
                } else {
                    recIdentificador();
                }
                break;
            case 'r' :
                addChar();
                getChar();
                if(nextChar == 'e') {
                    recRE();
                } else {
                    recIdentificador();
                }
                break;
            case 'a' :
                addChar();
                getChar();
                if(nextChar == 't') {
                    recATe();
                } else {
                    recIdentificador();
                }
                break;
            case 'v' :
                addChar();
                getChar();
                if(nextChar == 'a') {
                    recVAr();
                } else {
                    recIdentificador();
                }
                break;
            case 'c' :
                addChar();
                getChar();
                if(nextChar == 'a') {
                    recCAso();
                } else {
                    recIdentificador();
                }
                break;
            default :
                addChar();
                getChar();
                recIdentificador();
                break;
        }
        break;
    case DIGIT :
        recNumeros();
        break;
    case UNKNOWN :
        recDelimitadoresOperadores();
        break;
    case EOF :
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    }

    printf("token: %02d, lexema: %s (%d, %d)\n", nextToken, lexeme, linhaLexema, colunaLexema);
    return nextToken;

}
