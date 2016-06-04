#include "cabecalho.h"

void listaComandos() {
    
    fprintf(out,"---> analisando <listaComandos>\n");
    
    comando();
    
    while(nextToken == SEMICOLON) {
        lex();
        
        if(nextToken == INICIO_CODE || nextToken == IDENT || 
           nextToken == ENQUANTO_CODE || nextToken == REPITA_CODE ||
           nextToken == CASO_CODE || nextToken == PARA_CODE || nextToken == SE_CODE) {
            
            comando();
            
        }
        
    }
    
    
    fprintf(out,"<--- fim analise <listaComandos>\n");
    
}

void listaIdentificadores() {
    
    fprintf(out,"---> analisando <listaIdentificadores>\n");
    
    if(nextToken == IDENT) {
        lex();
    } else {
        ERROR(IDENT);
    }
    
    while(nextToken == COMMA) {
        lex();
        if(nextToken == IDENT) {
            lex();
        } else {
            ERROR(IDENT);
        }    
    }
    
    fprintf(out,"<--- fim analise <listaIdentificadores>\n");
    
}

void blocoPascal() {

    fprintf(out,"---> analisando <blocoPascal>\n");
    
    if(nextToken == INICIO_CODE) {
        lex();
        listaComandos();
        
        if(nextToken == SEMICOLON) {
            lex();
        }
        
        if(nextToken == FIM_CODE) {
            lex();
        } else {
            ERROR(FIM_CODE);
        }
    } else {
        ERROR(INICIO_CODE);
    }
    
    fprintf(out,"<--- fim analise <blocoPascal>\n");
    
}

void parametros() {
    
    fprintf(out,"---> analisando <parametros>\n");
    
    if(nextToken == LEFT_PAREN) {
        lex();
        listaIdentificadores();
        if(nextToken == RIGHT_PAREN) {
            lex();
        } else {
            ERROR(RIGHT_PAREN);            
        }
    }
    
    fprintf(out,"<--- fim analise <parametros>\n");
    
}

void declaracaoVariaveis() {
    
    fprintf(out,"---> analisando <declaracaoVariaveis>\n");
    
    listaIdentificadores();
    
    if(nextToken == COLON) {
        lex();
    } else {
        ERROR(COLON);
    }
    
    if(nextToken == INTEIRO_CODE || nextToken == REAL_CODE) {
        lex();
    } else {
        ERROR(INTEIRO_CODE);
    }
    
    fprintf(out,"<--- fim analise <declaracaoVariaveis>\n");
    
}

void cabecalho() {
    
    fprintf(out,"---> analisando <cabecalho>\n");
    
    if(nextToken == VAR_CODE) {
        lex();
        declaracaoVariaveis();
        if(nextToken == SEMICOLON) {
            lex();
            while(nextToken == IDENT) {
                declaracaoVariaveis();
                if(nextToken == SEMICOLON) {
                    lex();
                }
            }
        }
    }
    
    fprintf(out,"<--- fim analise <cabecalho>\n");
    
}

void programaPascal() {

    fprintf(out,"---> analisando <programaPascal>\n");
    
    if(nextToken == PROGRAMA_CODE) {
        lex();
    } else {
        ERROR(PROGRAMA_CODE);
    }
    
    if(nextToken == IDENT) {
        lex();
    } else {
        ERROR(IDENT);
    }
    
    if(nextToken == LEFT_PAREN) {
        parametros();
    }
    
    if(nextToken == SEMICOLON) {
        lex();
        cabecalho();
        blocoPascal();
    } else {
        ERROR(SEMICOLON);
    }
    
    if(nextToken == POINT) {
        lex();
        if(nextToken == EOF) {
            fprintf(out,"###### FIM DO PROGRAMA. ######\n");
            //exit(100);
        } else {
            fprintf(out,">>> ERROR: instrucoes apos o ponto final\n");
            exit(0);
        }
    } else {
        ERROR(POINT);
    }
    
    fprintf(out,"<--- fim analise <programaPascal>\n");
    
}

void constante() {
    
    fprintf(out,"---> analisando <constante>\n");
    
    if(nextToken == ADD_OP || nextToken == SUB_OP) {
        lex();
    }
    
    if(nextToken == INT_LIT || nextToken == REAL_LIT) {
        lex();
    } else {
        ERROR(INT_LIT);
    }
    
    fprintf(out,"<--- fim analise <constante>\n");
    
}

void opcaoCaso() {
    
    fprintf(out,"---> analisando <opcaoCaso>\n");
    
    constante();
    
    while(nextToken == COMMA) {
        lex();
        constante();
    }
    
    if(nextToken == COLON) {
        lex();
        comando();
    } else {
        ERROR(COLON);
    }
    
    fprintf(out,"<--- fim analise <opcaoCaso>\n");
    
}

void listaOpcoes() {
    
    fprintf(out,"---> analisando <listaOpcoes>\n");
    
    opcaoCaso();
    
    if(nextToken == SEMICOLON) {
        lex();
    } else {
        ERROR(SEMICOLON);
    }
    
    while(nextToken == ADD_OP || nextToken == SUB_OP || nextToken == INT_LIT || nextToken == REAL_LIT) {
        opcaoCaso();
        if(nextToken == SEMICOLON) {
            lex();
        } else {
            ERROR(SEMICOLON);
        }
    }
    
    fprintf(out,"<--- fim analise <listaOpcoes>\n");
    
}

void comando() {
    
    fprintf(out,"---> analisando <comando>\n");
    
    switch(nextToken) {
        case IDENT : 
            lex();
            if(nextToken == ASSIGN_OP) {
                lex();
                expressao();
            } else {
                ERROR(ASSIGN_OP);
            }
            break;
        case INICIO_CODE :
            lex();
            listaComandos();
            if(nextToken == SEMICOLON) {
                lex();
            }
            if(nextToken == FIM_CODE) {
                lex();
            } else {
                ERROR(FIM_CODE);
            }
            break;
        case ENQUANTO_CODE : 
            lex();
            expressao();
            if(nextToken == FACA_CODE) {
                lex();
                comando();
            } else {
                ERROR(FACA_CODE);
            }
            break;
        case PARA_CODE :
            lex();
            if(nextToken == IDENT) {
                lex();
                if(nextToken == ASSIGN_OP) {
                    lex();
                    expressao();
                    if(nextToken == ATE_CODE) {
                        lex();
                        expressao();
                        if(nextToken == FACA_CODE) {
                            lex();
                            comando();
                        } else {
                            ERROR(FACA_CODE);
                        }
                    } else {
                        ERROR(ATE_CODE);
                    }
                } else {
                    ERROR(ASSIGN_OP);
                }
            } else {
                ERROR(IDENT);
            }
            break;
        case REPITA_CODE :
            lex();
            listaComandos();
            if(nextToken == SEMICOLON) {
                lex();
            }
            if(nextToken == ATE_CODE) {
                lex();
                expressao();
            } else {
                ERROR(ATE_CODE);
            }
            break;
        case SE_CODE :
            lex();
            expressao();
            if(nextToken == ENTAO_CODE) {
                lex();
                comando();
                if(nextToken == SENAO_CODE) {
                    lex();
                    comando();
                }
            } else {
                ERROR(ENTAO_CODE);
            }
            break;
        case CASO_CODE :
            lex();
            expressao();
            if(nextToken == ESCOLHA_CODE) {
                lex();
                listaOpcoes();
                if(nextToken == SENAO_CODE) {
                    lex();
                    comando();
                    if(nextToken == SEMICOLON) {
                        lex();
                    } else {
                        ERROR(SEMICOLON);
                    }
                }
                if(nextToken == FIM_CODE) {
                    lex();
                } else {
                    ERROR(FIM_CODE);
                }
            } else {
                ERROR(ESCOLHA_CODE);
            }
            break;
        default:
            fprintf(out,">>> ERROR comando nao encontrado\n");
            exit(0);
    }
    
    fprintf(out,"<--- fim analise <comando>\n");
}

void expressao() {
    //<EXPRESSAO_SIMPLES> [ (=|<>|<|<=|>|>=) <EXPRESSAO_SIMPLES> ]
    fprintf(out,"---> analisando <expressao>\n");
    
    expressaoSimples();
    
    if(nextToken == EQUAL || nextToken == NOT_EQUAL || nextToken == LESS || nextToken == LESS_EQUAL || nextToken == GREATER || nextToken == GREATER_EQUAL) {
        lex();
        expressaoSimples();
    }
    
    fprintf(out,"<--- fim analise <expressao>\n");
    
}

void expressaoSimples() {
    // [+|-] <TERMO> { (+|-|ou) <TERMO> }
    fprintf(out,"---> analisando <expresaoSimples>\n");
    
    if(nextToken == ADD_OP|| nextToken == SUB_OP) {
        lex();        
    }
    
    term();
    
    while(nextToken == ADD_OP || nextToken == SUB_OP || nextToken == OU_CODE) {
        lex();
        term();
    }
    
    fprintf(out,"<--- fim analise <expressaoSimples>\n");
}

void term() {
    //<FATOR> { (*|/|e) <FATOR> }
    fprintf(out,"---> analisando <termo>\n");
    
    fator();
    
    while(nextToken == MULT_OP || nextToken == DIV_OP || nextToken == E_CODE) {
        lex();
        fator();
    }
    
    fprintf(out,"<--- fim analise <termo>\n");
}

void fator() {
    //identificador | int_lit | real_lit | (<EXPRESSAO>) | not <FATOR>
    fprintf(out,"---> analisando <fator>\n");
    
    if(nextToken == IDENT) {
        lex();
    } else if(nextToken == NAO_CODE) {
        lex();
        fator();
    } else if(nextToken == INT_LIT || nextToken == REAL_LIT) {        
        lex();
    } else if (nextToken == LEFT_PAREN) {
        lex();
        expressao();
        if(nextToken == RIGHT_PAREN) {
            lex();
        } else {
            ERROR(RIGHT_PAREN);
        }
    } else if(nextToken != ADD_OP && nextToken != SUB_OP && nextToken != OU_CODE) {
        fprintf(out,">>> ERROR fator(): proximo simbolo invalido\n");
        exit(0);
    }
    
    fprintf(out,"<--- fim analise <fator>\n");
    
}