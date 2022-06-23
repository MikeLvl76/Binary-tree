#ifndef TREE
#define TREE

typedef struct Node Node;

struct Node {
    Node * left;
    Node * right;
    void * value;
};

extern Node * createNode(void * value);
extern Node * insert(Node * tree, Node * n);
extern Node * search(Node * tree, void * value);
extern Node * remove(Node * tree, void * value);
extern int height(Node * tree);
extern void display(Node * tree);

#endif