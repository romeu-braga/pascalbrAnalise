#include "cabecalho.h"

/* lookup - uma função para processar operadores e parênteses e retornar o token */
int lookup(char ch) {
    switch(ch) {
    case '(' :
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')' :
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    case '+' :
        addChar();
        nextToken = ADD_OP;
        break;
    case '-' :
        addChar();
        nextToken = SUB_OP;
        break;
    case '*' :
        addChar();
        nextToken = MULT_OP;
        break;
    case '/' :
        addChar();
        nextToken = DIV_OP;
        break;
    default :
        addChar();
        nextToken = EOF;
        break;
    }
    return nextToken;
}

/* addChar - uma função para adicionar nextChar ao vetor lexeme */
void addChar() {
    if(lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0; //DUVIDA
    } else {
        printf("ERROR - lexema muito grande\n");
    }
}

/* getChar - uma função para obter o próximo caractere da entrada e determinar sua classe de caracteres */
void getChar() {
    if((nextChar = getc(in_fp)) != EOF) {
        if(isalpha(nextChar)) {
            charClass = LETTER;
        } else if (isdigit(nextChar)) {
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
    } else {
        charClass = EOF;
    }
}


/* getNonBlank - uma função para chamar getChar até que ela retorne um caractere diferente de espaço em branco */
void getNonBlank() {
    while(isspace(nextChar)) {
        getChar();
    }
}
