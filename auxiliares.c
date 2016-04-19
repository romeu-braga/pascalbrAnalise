#include "cabecalho.h"

/* lookup - uma fun��o para processar operadores e par�nteses e retornar o token */
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

/* addChar - uma fun��o para adicionar nextChar ao vetor lexeme */
void addChar() {
    if(lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0; //DUVIDA
    } else {
        printf("ERROR - lexema muito grande\n");
    }
}

/* getChar - uma fun��o para obter o pr�ximo caractere da entrada e determinar sua classe de caracteres */
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


/* getNonBlank - uma fun��o para chamar getChar at� que ela retorne um caractere diferente de espa�o em branco */
void getNonBlank() {
    while(isspace(nextChar)) {
        getChar();
    }
}
