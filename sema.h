#include<stdbool.h>
//#include"Parser.h"
typedef struct LVar LVar;
struct LVar {
    char *varName;
    int index;
    LVar *next;
};


//void sema(Node *);
LVar *new_member(LVar *, char *, int);
char *getVarName(void);
int getVarIndex(void);
void setHead(void);
bool hasMoreMembers(void);
void setnext(void);
int search_symbol_table(char *);
