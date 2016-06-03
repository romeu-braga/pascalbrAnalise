#include "cabecalho.h"

void listaComandos() {
    
    printf("analisando listaComandos\n");
    
    comando();
    
    while(nextToken == SEMICOLON) {
        lex();
        comando();
    }
    
}

void listaIdentificadores() {
    
    printf("analisando listaIdentificadores\n");
    
    if(nextToken == IDENT) {
        lex();
    } else {
        printf(">>> ERROR: identificador nao encontrado\n");
    }
    
    while(nextToken == COMMA) {
        lex();
        if(nextToken == IDENT) {
            lex();
        } else {
            printf(">>> ERROR: identificador nao encontrado\n");
        }    
    }
    
}

void blocoPascal() {

    printf("analisando blocoPascal\n");
    
    if(nextToken == INICIO_CODE) {
        lex();
        listaComandos();
        if(nextToken == FIM_CODE) {
            lex();
        } else {
            printf(">>> ERROR: palavra chave 'fim' nao encontrada no final do blocoPascal\n");
        }
    }
    
}

void parametros() {
    
    printf("analisando parametros\n");
    
    if(nextToken == LEFT_PAREN) {
        lex();
        listaIdentificadores();
        if(nextToken == RIGHT_PAREN) {
            lex();
        } else {
            printf(">>> ERROR: parentese direito na lista de parametros nao encontrado\n");
        }
    }
}

void declaracaoVariaveis() {
    
    printf("analisando declaracaoVariaveis\n");
    
    listaIdentificadores();
    
    if(nextToken == COLON) {
        lex();
    } else {
        printf(">>> ERROR: delimitador ':' nao encontrado\n");
    }
    
    if(nextToken == INTEIRO_CODE || nextToken == REAL_CODE) {
        lex();
    } else {
        printf(">>> ERROR: definicao de tipo nao encontrada\n");
    }
}

void cabecalho() {
    
    printf("analisando cabecalho\n");
    
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
}

void programaPascal() {

    printf("analisando programaPascal\n");
    
    if(nextToken == PROGRAMA_CODE) {
        lex();
    } else {
        printf(">>> ERROR: palavra reservada 'programa' nao encontrada\n");
    }
    
    if(nextToken == IDENT) {
        lex();
    } else {
        printf(">>> ERROR: palavra identificador do programa nao encontrado\n");
    }
    
    if(nextToken == LEFT_PAREN) {
        parametros();
    }
    
    if(nextToken == SEMICOLON) {
        lex();
        cabecalho();
        blocoPascal();
    } else {
        printf(">>> ERROR: delimitador ';' nao encontrado programaPascal\n");
    }
    
    if(nextToken == POINT) {
        lex();
        if(nextToken == EOF) {
            printf("\nPROGRAMA SINTATICAMENTE CORRETO.\n");
        } else {
            printf(">>> ERROR: instrucoes apos o ponto final\n");
        }
    } else {
        printf(">>> ERROR: ponto final nao encontrado\n");
    }
}

void constante() {
    
    printf("analisando constante\n");
    
    if(nextToken == ADD_OP || nextToken == SUB_OP) {
        lex();
    }
    
    if(nextToken == INT_LIT || nextToken == REAL_LIT) {
        lex();
    } else {
        printf(">>> ERROR: numero nao encontrado\n");
    }
    
}

void opcaoCaso() {
    
    printf("analisando opcaoCaso\n");
    
    constante();
    
    while(nextToken == COMMA) {
        lex();
        constante();
    }
    
    if(nextToken == COLON) {
        lex();
        comando();
    } else {
        printf(">>> ERROR: simbolo ':' nao encontrado\n");
    }
}

void listaOpcoes() {
    
    printf("analisando listaOpcoes\n");
    
    opcaoCaso();
    
    if(nextToken == SEMICOLON) {
        lex();
    } else {
        printf(">>> ERROR: ';' nao encontrado no final da opcao do caso\n");
    }
    
    while(nextToken == ADD_OP || nextToken == SUB_OP || nextToken == INT_LIT || nextToken == REAL_LIT) {
        opcaoCaso();
        if(nextToken == SEMICOLON) {
            lex();
        } else {
            printf(">>> ERROR: ';' nao encontrado no final da opcao do caso\n");
        }
    }
}

void comando() {
    
    printf("analisando comando\n");
    
    switch(nextToken) {
        case IDENT : 
            lex();
            if(nextToken == ASSIGN_OP) {
                lex();
                expressao();
            }
            break;
        case INICIO_CODE :
            lex();
            listaComandos();
            if(nextToken == FIM_CODE) {
                lex();
            } else {
                printf(">>> ERROR: palavra reservada 'fim' nao encontrada\n");
            }
            break;
        case ENQUANTO_CODE : 
            lex();
            expressao();
            if(nextToken == FACA_CODE) {
                lex();
                comando();
            } else {
                printf(">>> ERROR: palavra reservada 'faca' nao encontrada\n");
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
                            printf(">>> ERROR: palavra reservada 'faca' nao encontrada\n");
                        }
                    } else {
                        printf(">>> ERROR: palavra reservada 'ate' nao encontrada\n");
                    }
                } else {
                    printf(">>> ERROR: operador de atribuicao ':=' nao encontrado\n");
                }
            } else {
                printf(">>> ERROR: identificador nao encontrado\n");
            }
            break;
        case REPITA_CODE :
            lex();
            listaComandos();
            if(nextToken == ATE_CODE) {
                lex();
                expressao();
            } else {
                printf(">>> ERROR: palavra reservada 'ate' nao encontrada\n");
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
                printf(">>> ERROR: palavra reservada 'entao' nao encontrada\n");
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
                        printf(">>> ERROR: ';' nao encontrado no final do 'senao' do case\n");
                    }
                }
                if(nextToken == FIM_CODE) {
                    lex();
                } else {
                    printf(">>> ERROR: palavra reservada 'fim' nao encontrada\n");
                }
            } else {
                printf(">>> ERROR: palavra reservada 'escolha' nao encontrada\n");
            }
            break;
        default:
            printf(">>> ERROR comando(): comando nao encontrado\n");
    }
}

void expressao() {
    //<EXPRESSAO_SIMPLES> [ (=|<>|<|<=|>|>=) <EXPRESSAO_SIMPLES> ]
    printf("analisando expressao\n");
    
    expressaoSimples();
    
    if(nextToken == EQUAL || nextToken == NOT_EQUAL || nextToken == LESS || nextToken == LESS_EQUAL || nextToken == GREATER || nextToken == GREATER_EQUAL) {
        lex();
        expressaoSimples();
    } 
    
}

void expressaoSimples() {
    // [+|-] <TERMO> { (+|-|ou) <TERMO> }
    printf("analisando expresaoSimples\n");
    
    if(nextToken == ADD_OP|| nextToken == SUB_OP) {
        lex();        
    }
    
    term();
    
    while(nextToken == ADD_OP || nextToken == SUB_OP || nextToken == OU_CODE) {
        lex();
        term();
    }
    
}

void term() {
    //<FATOR> { (*|/|e) <FATOR> }
    printf("analisando termo\n");
    
    fator();
    
    while(nextToken == MULT_OP || nextToken == DIV_OP || nextToken == E_CODE) {
        lex();
        fator();
    }
}

void fator() {
    //identificador | int_lit | real_lit | (<EXPRESSAO>) | not <FATOR>
    printf("analisando fator\n");
    
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
            printf(">>> ERROR fator(): nao encontrou parentese direito\n");
        }
    } else if(nextToken != ADD_OP && nextToken != SUB_OP && nextToken != OU_CODE) {
        printf(">>> ERROR fator(): proximo simbolo invalido\n");
    }
    
}