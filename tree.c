#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tree.h"

/**
 * @brief Create a Node object with initializing all its attributes
 * 
 * @param value 
 * @return Node* 
 */
extern Node * createNode(char value){
    if(value == '\0'){
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    Node * node = malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "%s", "memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node -> left = NULL;
    node -> right = NULL;
    node -> parent = NULL;
    node -> value = value;
    return node;
}

/**
 * @brief Get the root of a tree
 * 
 * @param tree 
 * @return Node* 
 */
extern Node * getRoot(Node * tree){
    if(tree == NULL){
        fprintf(stderr, "%s", "null pointer error\n");
        exit(EXIT_FAILURE);
    }
    if(tree -> parent != NULL){
        return getRoot(tree -> parent);
    }
    return tree;
}

/**
 * @brief Insert a new node to an existing node, by order according to decimal value in ASCII table
 * 
 * @param tree 
 * @param n 
 * @return Node* 
 */
extern Node * insert(Node * tree, Node * n){
    if(tree == NULL || n == NULL){
        fprintf(stderr, "%s", "null pointer error\n");
        exit(EXIT_FAILURE);
    }
    if((int) n -> value < (int) tree -> value){
        if(tree -> left == NULL){
            tree -> left = n;
            tree -> left -> parent = tree;
            return n;
        }
        return insert(tree -> left, n);
    }
    if(tree -> right == NULL){
            tree -> right = n;
            tree -> right -> parent = tree;
            return n;
        }
        return insert(tree -> right, n);
    return NULL;
}

/**
 * @brief Search a node by its value in a tree
 * 
 * @param tree 
 * @param value 
 * @return Node* or NULL if value isn't in the tree
 */
extern Node * search(Node * tree, char value){
    if(tree == NULL){
        fprintf(stderr, "%s", "null pointer error\n");
        exit(EXIT_FAILURE);
    }
    if(value == '\0'){
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    if(tree -> value == value){
        return tree;
    } 
    if((int) value < (int) tree -> value){
        if(tree -> left != NULL){
            return search(tree -> left, value);
        }
    }
    if(tree -> right != NULL){
        return search(tree -> right, value);
    }

    return NULL;
}

/**
 * @brief Change value of a node and return it
 * 
 * @param tree
 * @param old 
 * @param actual
 * @return Node* or NULL if value isn't in the tree
 */
extern Node * edit(Node * tree, char old, char actual){
    Node * o = search(tree, old);
    if(o != NULL){
        printf("old : %c\n", o -> value);
        o -> value = actual;
        printf("new : %c\n", o -> value);
    }
    return o;
}

/**
 * @brief Display non-null tree
 * 
 * @param tree 
 */
extern void display(Node * tree){
    if(tree == NULL){
        fprintf(stderr, "%s", "null pointer error\n");
        exit(EXIT_FAILURE);
    }
    printf("%c\n", tree -> value);
    if(tree -> left != NULL){
        display(tree -> left);
    }
    if(tree -> right != NULL){
        display(tree -> right);
    }
}

int main(){
    srand(time(NULL));
    Node * tree = createNode(97 + rand() % 25);
    for(int i = 0; i < 26; i++){
        Node * n = createNode(97 + rand() % 25);
        insert(tree, n);
    }
    display(tree);
    printf("%p\n", edit(tree, 'g', 'h'));
    display(tree);
    return EXIT_SUCCESS;
}