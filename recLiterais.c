#include "cabecalho.h"

int recNumeros() {
    addChar();
    getChar();
    while(charClass == DIGIT) {
        addChar();
        getChar();
    }
    nextToken = INT_LIT;

    if(nextChar == '.') {
        recReal();
    }
    return nextToken;
}

int recReal() {
    addChar();
    getChar();
    while(charClass == DIGIT) {
        addChar();
        getChar();
    }
    nextToken = REAL_LIT;

    return nextToken;
}
