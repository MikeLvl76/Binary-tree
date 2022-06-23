#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    node -> value = value;
    return node;
}

/**
 * @brief Insert a new node to an existing node
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
    if(tree -> left == NULL){
        tree -> left = n;
        return n;
    }
    if(tree -> right == NULL){
        tree -> right = n;
        return n;
    }
    return insert(tree -> left, n);
}

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
    Node * tree = createNode('A');
    for(int i = 98; i < 123; i++){
        Node * n = createNode(i);
        insert(tree, n);
    }
    display(tree);
    return EXIT_SUCCESS;
}