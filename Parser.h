typedef enum{
    ND_ADD,
    ND_SUB,
    ND_NUM,
    ND_INT_VAR,
    ND_DECL,
    ND_RETURN,
    ND_ASSIGN
} NodeKind;

typedef struct Node Node;
struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    Node *stmts;
    Node *expr;
    int val;
    char *str;
    int varindex;
};

Node *new_node_num(int);
Node *new_node_var(char *, int);
Node *new_node_decl(char *, int);
Node *new_node(NodeKind, Node *, Node *);
Node *new_node_return(Node *);
Node *stmt(void);
Node *expr(void);
