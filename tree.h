#ifndef TREE
#define TREE

typedef struct Node Node;

struct Node {
    Node * parent;
    Node * left;
    Node * right;
    char value;
};

extern Node * createNode(char value);
extern Node * getRoot(Node * tree);
extern Node * insert(Node * tree, Node * n);
extern Node * search(Node * tree, char value);
extern Node * edit(Node * tree, char old, char actual);
extern Node * delete(Node * tree, char value);
extern int height(Node * tree);
extern void display(Node * tree);

#endif