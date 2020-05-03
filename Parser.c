#include"Tokenizer.h"
#include"Parser.h"

Node *new_node_num(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->kind = ND_NUM;
    return node;
}
Node *new_node_decl(char *var_name, int len){
    Node *node = (Node *)malloc(sizeof(Node));
    node->str = (char *)malloc(sizeof(char) * len);
    strcpy(node->str, var_name);
    node->kind = ND_DECL;
    return node;
}
Node *new_node_var(char *var_name, int len){
    Node *node = (Node *)malloc(sizeof(Node));
    node->str = (char *)malloc(sizeof(char) * len);
    strcpy(node->str, var_name);
    node->kind = ND_INT_VAR;
    return node;
}
Node *new_node(NodeKind kind, Node *lhs, Node *rhs){
    Node *node = (Node *)malloc(sizeof(Node));
    node->kind = kind;
    node->lhs = lhs;
    node->rhs = rhs;
    return node;
}
Node *stmt(){
    Node *node;
    while(!expect_symbol(';')){
        if((tokenKind() == TK_KEYWORD) && expect_keyword(KW_INT)){   
            printf("<keyword> int </keyword>\n");
            node = new_node_decl(identifier(), strlen(identifier()));
            printf("<identifier> %s </identifier>\n", node->str);
            advance();
        } else if(tokenKind() == TK_IDENTIFIER){
            node = new_node_var(identifier(), strlen(identifier()));
            printf("<identifier> %s </identifier>\n", node->str);
            advance();
            printf("<symbol> %c </symbol>\n", symbol());
            consume_symbol('=');
            node = new_node(ND_ASSIGN, node, expr());
        } else {
            consume_keyword(KW_RETURN);
            printf("<keyword> return </keyword>\n");
            node = expr();
        }
    }
    printf("<symbol> ; </symbol>\n");
    return node;
}
Node *expr(){
    Node *node;
    if(tokenKind() == TK_IDENTIFIER){
        node = new_node_var(identifier(), strlen(identifier()));
        printf("<identifier> %s </identifier>\n", identifier());
        advance();
    } else if(tokenKind() == TK_INT_CONST){
        node = new_node_num(intVal());
        printf("<intConst> %d </intConst>\n", intVal());
        advance();
    }

    if(expect_symbol('+')){
        printf("<symbol> + </symbol>\n");
        node = new_node(ND_ADD, node, expr());
    } else if(expect_symbol('-')){
        printf("<symbol> - </symbol>\n");
        node = new_node(ND_SUB, node, expr());
    }

    return node;
}
