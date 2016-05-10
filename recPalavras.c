#include "cabecalho.h"

int recIdentificador() {
    while(charClass == LETTER || charClass == DIGIT) {
        addChar();
        getChar();
    }
    nextToken = IDENT;

    return nextToken;
}

/*********************************************************/

int recPRograma() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recPrOgrama();
    } else {
        return recIdentificador();
    }
}

int recPrOgrama() {
    addChar();
    getChar();
    if(nextChar == 'g') {
        return recProGrama();
    } else {
        return recIdentificador();
    }
}

int recProGrama() {
    addChar();
    getChar();
    if(nextChar == 'r') {
        return recProgRama();
    } else {
        recIdentificador();
    }
}

int recProgRama() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recProgrAma();
    } else {
        return recIdentificador();
    }
}

int recProgrAma() {
    addChar();
    getChar();
    if(nextChar == 'm') {
        return recPrograMa();
    } else {
        return recIdentificador();
    }
}

int recPrograMa() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recProgramA();
    } else {
        return recIdentificador();
    }
}

int recProgramA() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = PROGRAMA_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/*********************************************************/

int recPAra() {
    addChar();
    getChar();
    if(nextChar == 'r') {
        return recPaRa();
    } else {
        return recIdentificador();
    }
}

int recPaRa() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recParA();
    } else {
        return recIdentificador();
    }
}

int recParA() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = PARA_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/*********************************************************/
int recIN() {
    addChar();
    getChar();
    if(nextChar == 'i') {
        return recInIcio();
    } else if(nextChar == 't') {
        return recInTeiro();
    } else {
        recIdentificador();
    }
}

int recInIcio() {
    addChar();
    getChar();
    if(nextChar == 'c') {
        return recIniCio();
    } else {
        return recIdentificador();
    }
}

int recIniCio() {
    addChar();
    getChar();
    if(nextChar == 'i') {
        return recInicIo();
    } else {
        return recIdentificador();
    }
}

int recInicIo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recIniciO();
    } else {
        return recIdentificador();
    }
}

int recIniciO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = INICIO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/********************************************************/

int recInTeiro() {
    addChar();
    getChar();
    if(nextChar == 'e') {
        return recIntEiro();
    } else {
        return recIdentificador();
    }
}

int recIntEiro() {
    addChar();
    getChar();
    if(nextChar == 'i') {
        return recInteIro();
    } else {
        return recIdentificador();
    }
}

int recInteIro() {
    addChar();
    getChar();
    if(nextChar == 'r') {
        return recInteiRo();
    } else {
        return recIdentificador();
    }
}

int recInteiRo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recInteirO();
    } else {
        return recIdentificador();
    }
}

int recInteirO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = INTEIRO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/*************************************************************/

int recFAca() {
    addChar();
    getChar();
    if(nextChar == 'c') {
        return recFaCa();
    } else {
        return recIdentificador();
    }
}

int recFaCa() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recFacA();
    } else {
        return recIdentificador();
    }
}

int recFacA() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = FACA_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/***************************************************************/

int recFIm() {
    addChar();
    getChar();
    if(nextChar == 'm') {
        return recFiM();
    } else {
        return recIdentificador();
    }
}

int recFiM() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = FIM_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/****************************************************************/

int recSeNao() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recSenAo();
    } else {
        return recIdentificador();
    }
}

int recSenAo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recSenaO();
    } else {
        return recIdentificador();
    }
}

int recSenaO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = SENAO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/*****************************************************************/
int recEN() {
    addChar();
    getChar();
    if(nextChar == 'q') {
        return recEnQuanto();
    } else if(nextChar == 't') {
        return recEnTao();
    } else {
        return recIdentificador();
    }
}

int recEnQuanto() {
    addChar();
    getChar();
    if(nextChar == 'u') {
        return recEnqUanto();
    } else {
        return recIdentificador();
    }
}

int recEnqUanto() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recEnquAnto();
    } else {
        return recIdentificador();
    }
}

int recEnquAnto() {
    addChar();
    getChar();
    if(nextChar == 'n') {
        return recEnquaNto();
    } else {
        return recIdentificador();
    }
}

int recEnquaNto() {
    addChar();
    getChar();
    if(nextChar == 't') {
        return recEnquanTo();
    } else {
        return recIdentificador();
    }
}

int recEnquanTo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recEnquantO();
    } else {
        return recIdentificador();
    }
}

int recEnquantO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = ENQUANTO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/************************************************************/

int recEnTao() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recEntAo();
    } else {
        return recIdentificador();
    }
}

int recEntAo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recEntaO();
    } else {
        return recIdentificador();
    }
}

int recEntaO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = ENTAO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/****************************************************************/

int recEScolha() {
    addChar();
    getChar();
    if(nextChar == 'c') {
        return recEsColha();
    } else {
        return recIdentificador();
    }
}

int recEsColha() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recEscOlha();
    } else {
        return recIdentificador();
    }
}

int recEscOlha() {
    addChar();
    getChar();
    if(nextChar == 'l') {
        return recEscoLha();
    } else {
        return recIdentificador();
    }
}

int recEscoLha() {
    addChar();
    getChar();
    if(nextChar == 'h') {
        return recEscolHa();
    } else {
        return recIdentificador();
    }
}

int recEscolHa() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recEscolhA();
    } else {
        return recIdentificador();
    }
}

int recEscolhA() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = ESCOLHA_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/***********************************************************/
int recRE() {
    addChar();
    getChar();
    if(nextChar == 'p') {
        return recRePita();
    } else if(nextChar == 'a') {
        return recReAl();
    } else {
        return recIdentificador();
    }
}

int recRePita() {
    addChar();
    getChar();
    if(nextChar == 'i') {
        return recRepIta();
    } else {
        return recIdentificador();
    }
}

int recRepIta() {
    addChar();
    getChar();
    if(nextChar == 't') {
        return recRepiTa();
    } else {
        return recIdentificador();
    }
}

int recRepiTa() {
    addChar();
    getChar();
    if(nextChar == 'a') {
        return recRepitA();
    } else {
        return recIdentificador();
    }
}

int recRepitA() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = REPITA_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/**************************************************/

int recATe() {
    addChar();
    getChar();
    if(nextChar == 'e') {
        return recAtE();
    } else {
        return recIdentificador();
    }
}

int recAtE() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = ATE_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/******************************************************/

int recVAr() {
    addChar();
    getChar();
    if(nextChar == 'r') {
        return recVaR();
    } else {
        return recIdentificador();
    }
}

int recVaR() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = VAR_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/**********************************************************/

int recCAso() {
    addChar();
    getChar();
    if(nextChar == 's') {
        return recCaSo();
    } else {
        return recIdentificador();
    }
}

int recCaSo() {
    addChar();
    getChar();
    if(nextChar == 'o') {
        return recCasO();
    } else {
        return recIdentificador();
    }
}

int recCasO() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = CASO_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}

/**************************************************************/

int recReAl() {
    addChar();
    getChar();
    if(nextChar == 'l') {
        return recReaL();
    } else {
        return recIdentificador();
    }
}

int recReaL() {
    addChar();
    getChar();
    if(fimPalavraReservada() == 1) {
        nextToken = REAL_CODE;
        return nextToken;
    } else {
        return recIdentificador();
    }
}
