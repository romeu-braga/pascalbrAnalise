#include <stdio.h>
#include <ctype.h>

/*******************************************************
 ****************** Variáveis Globais ******************
 *******************************************************/
int linha;
int coluna;
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp;
/*******************************************************
 ****************** Classes de Caracteres***************
 *******************************************************/
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/*******************************************************
 ****************** Códigos de tokens ******************
 *******************************************************/
// Delimitadores
#define SEMICOLON 03 //OK
#define LEFT_PAREN 04 //OK
#define RIGHT_PAREN 05 //OK
#define COMMA 06 //OK
#define POINT 07 //OK
#define COLON 8 //OK

// Operadores
#define ASSIGN_OP 11 //OK

// Operadores Aritméticos
#define ADD_OP 21 //OK
#define SUB_OP 22 //OK
#define MULT_OP 23 //OK
#define DIV_OP 24 //OK

// Operadores Relacionais
#define EQUAL 31 //OK
#define NOT_EQUAL 32 //OK
#define GREATER 33 //OK
#define LESS 34 //OK
#define GREATER_EQUAL 35 //OK
#define LESS_EQUAL 36 //OK

// Identificadores
#define IDENT 41 //OK

// Números
#define INT_LIT 51 //OK
#define REAL_LIT 52 //OK

// Palavras Reservadas
#define PROGRAMA_CODE 61 //OK
#define INICIO_CODE 62 //OK
#define FIM_CODE 63 //OK
#define VAR_CODE 64 //OK
#define INTEIRO_CODE 65 //OK
#define REAL_CODE 66 //OK
#define SE_CODE 67 //OK
#define ENTAO_CODE 68 //OK
#define SENAO_CODE 69 //OK
#define CASO_CODE 70 //OK
#define ESCOLHA_CODE 71 //OK
#define ENQUANTO_CODE 72 //OK
#define FACA_CODE 73 //OK
#define REPITA_CODE 74 //OK
#define ATE_CODE 75 //OK
#define PARA_CODE 76 //OK
#define E_CODE 77 //OK
#define OU_CODE 78 //OK
#define NAO_CODE 79 //OK

// Outros
#define INVALID_TOKEN 98

/*******************************************************
 *************** Declarações de Funções ****************
 *******************************************************/
void addChar();
void getChar();
void getNonBlank();
int recDelimitadoresOperadores();
int recNumeros();
int recReal();
int recIdentificador();
int lex();
