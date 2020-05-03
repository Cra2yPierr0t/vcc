void gen(Node *);
void gen(Node *node){
    if(ND_NUM){
        vPush(node->val);
    } else if(ND_ADD){
        gen(node->lhs);
        vaddi();
        gen(node->rhs);
    } else if(ND_SUB){
        gen(node->lhs);
        vsubi();
        gen(node->rhs);
    } else if(ND_ASSIGN){
        gen(node->lhs);
        gen(node->rhs);
    } else if(ND_INT_VAR){
    }
}
