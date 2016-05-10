#include "cabecalho.h"

int recDelimitadoresOperadores() {
    switch(nextChar) {
        case '.' :
            addChar();
            nextToken = POINT;
            getChar();
            if(charClass == DIGIT) {
                recReal();
            }
            break;
        case '(' :
            addChar();
            nextToken = LEFT_PAREN;
            getChar();
            break;
        case ',' :
            addChar();
            nextToken = COMMA;
            getChar();
            break;
        case ')' :
            addChar();
            nextToken = RIGHT_PAREN;
            getChar();
            break;
        case '+' :
            addChar();
            nextToken = ADD_OP;
            getChar();
            break;
        case '-' :
            addChar();
            nextToken = SUB_OP;
            getChar();
            break;
        case '*' :
            addChar();
            nextToken = MULT_OP;
            getChar();
            break;
        case '/' :
            addChar();
            nextToken = DIV_OP;
            getChar();
            break;
        case ';' :
            addChar();
            nextToken = SEMICOLON;
            getChar();
            break;
        case '=' :
            addChar();
            nextToken = EQUAL;
            getChar();
            break;
        case '>' :
            addChar();
            nextToken = GREATER;
            getChar();
            if(nextChar == '=') {
                addChar();
                nextToken = GREATER_EQUAL;
                getChar();
            }
            break;
        case '<' :
            addChar();
            nextToken = LESS;
            getChar();
            if(nextChar == '=') {
                addChar();
                nextToken = LESS_EQUAL;
                getChar();
            } else if(nextChar == '>') {
                addChar();
                nextToken = NOT_EQUAL;
                getChar();
            }
            break;
        case ':' :
            addChar();
            getChar();
            if(nextChar == '=') {
                addChar();
                nextToken = ASSIGN_OP;
                getChar();
            }
            break;
        default :
            addChar();
            //getChar(); //O analisador léxico original não analisava o restante se encontrasse erro.
            nextToken = INVALID_TOKEN;
            break;
    }
    return nextToken;
}
