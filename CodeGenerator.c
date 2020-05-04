#include"Parser.h"
#include"CodeGenerator.h"
#include<stdio.h>
void gen(Node *node){
    if(node->kind == ND_NUM){
        ipush(node->val);
    } else if(node->kind == ND_ADD){
        gen(node->lhs);
        gen(node->rhs);
        add();
    } else if(node->kind == ND_SUB){
        gen(node->lhs);
        gen(node->rhs);
        sub();
    } else if(node->kind == ND_ASSIGN){
        gen(node->rhs);
        pop(node->lhs->varindex);
    } else if(node->kind == ND_INT_VAR){
        vpush(node->varindex);
    } else if(node->kind == ND_DECL){
    } else if(node->kind == ND_RETURN){
        gen(node->expr);
        do_return();
    }
    return;
}
void ipush(int imm){
    printf("addi    t1, zero, %d\n", imm);
    printf("sw      t1, 0x0(sp)\n");
    printf("addi    sp, sp, -4\n");
    return;
}
void vpush(int varindex){
    printf("sw      a%d, 0x0(sp)\n", varindex + 1);
    printf("addi    sp, sp, -4\n");
}
void pop(int varindex){
    printf("addi    sp, sp, 4\n");
    printf("lw      a%d, 0x0(sp)\n", varindex + 1);
}
void add(){
    printf("addi    sp, sp, 4\n");
    printf("lw      t1, 0x0(sp)\n");
    printf("addi    sp, sp, 4\n");
    printf("lw      t2, 0x0(sp)\n");
    printf("add     t1, t1, t2\n");
    printf("sw      t1, 0x0(sp)\n");
    printf("addi    sp, sp, -4\n");
    return;
}
void sub(){
    printf("addi    sp, sp, 4\n");
    printf("lw      t1, 0x0(sp)\n");
    printf("addi    sp, sp, 4\n");
    printf("lw      t2, 0x0(sp)\n");
    printf("sub     t1, t1, t2\n");
    printf("sw      t1, 0x0(sp)\n");
    printf("addi    sp, sp, -4\n");
    return;
}
void do_return(){
    printf("addi    sp, sp, 4\n");
    printf("lw      a0, 0x0(sp)\n");
}
