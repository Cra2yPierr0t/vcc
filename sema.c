#include"sema.h"
#include"Tokenizer.h"
#include"Parser.h"

LVar table_head;
LVar *symbol_table;
LVar *table_cur = &table_head;
int varIndex;

LVar *new_member(LVar *table_cur, char *str, int index){    
    LVar *lvar = (LVar *)malloc(sizeof(LVar));
    lvar->varName = (char *)malloc(sizeof(char) * strlen(str));
    strcpy(lvar->varName, str);
    lvar->index = index;
    table_cur->next = lvar;
    return lvar;
}
void sema(Node *node){
    if(node->kind == ND_DECL){
        table_cur = new_member(table_cur, node->str, varIndex++);
        table_cur->next = NULL;
        symbol_table = table_cur;
    }
    setHead();
    if(node->kind == ND_INT_VAR){
        node->varindex = search_symbol_table(node->str);
        printf("%s's index is %d.\n", node->str, node->varindex);
    } else if((node->kind != ND_DECL) && (node->kind != ND_NUM)){
        sema(node->rhs);
        sema(node->lhs);
    }
    return;
}
char *getVarName(void){
    return symbol_table->varName;
}
int getVarIndex(void){
    return symbol_table->index;
}
void setHead(){
    symbol_table = table_head.next;
//    printf("%s\n", symbol_table->varName);
    return;
}
bool hasMoreMembers(){
    return symbol_table != NULL;
}
void setnext(){
    symbol_table = symbol_table->next;
    return;
}
int search_symbol_table(char *name){
    while(hasMoreMembers()){
        if(strcmp(name, getVarName()) == 0){
            return getVarIndex();
        }
        setnext();
    }
    fprintf(stderr, "%sが未定義です.\n", name);
    exit(1);
}
