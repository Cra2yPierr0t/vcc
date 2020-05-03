#include"Tokenizer.h"
#include"Parser.h"
#include"sema.h"

void sema(Node *);

int main(int argc, char *argv[]){
    token = tokenize(argv[1]);
    Node *node[100];
    int i = 0;
    do {
        puts("[parse]");
        node[i++] = stmt();
        puts("[done]");
    } while(hasMoreTokens());

    for(int j = 0;j < i; j++){
        sema(node[j]);
    }
}
