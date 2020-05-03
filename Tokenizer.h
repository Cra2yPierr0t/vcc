#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef enum{
    TK_KEYWORD,
    TK_SYMBOL,
    TK_IDENTIFIER,
    TK_INT_CONST,
    TK_STRING_CONST
} TokenKind;
typedef enum {
    KW_INT,
    KW_CHAR,
    KW_VOID,
    KW_STATIC,
    KW_DO,
    KW_IF,
    KW_ELSE,
    KW_WHILE,
    KW_RETURN,
    KW_TRUE,
    KW_FALSE,
    KW_NULL,
} KeyWord;
typedef struct Token Token;
struct Token {
    TokenKind kind;
    KeyWord word;
    Token *next;
    char *str;
    int len;
    int val;
};

Token *token;

Token *new_token(TokenKind, Token *, char *str, int);
Token *tokenize(char *);
bool hasMoreTokens(void);
void advance(void);
TokenKind tokenKind(void);
KeyWord keyWord(void);
char symbol(void);
char *identifier(void);
int intVal(void);
char *stringVal(void);

int consume_number(void);
bool expect_symbol(char);
void consume_symbol(char);
bool expect_keyword(KeyWord);
void consume_keyword(KeyWord);
