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
    node -> value = value;
    return node;
}

/**
 * @brief Insert a new node to an existing node, by order according to decimal value in ASCII table
 * 
 * @param tree 
 * @param n 
 * @return Node* 
 */
extern Node * insert(Node * node, char value){
    if(value == '\0'){
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    if(node == NULL){
        return createNode(value);
    }

    if((int) value < (int) node -> value){
        node -> left = insert(node -> left, value);
    } else {
        node -> right = insert(node -> right, value);
    }
    return node;
}

/**
 * @brief Search a node by its value in a tree
 * 
 * @param tree 
 * @param value 
 * @return Node* or NULL if value isn't in the tree
 */
Node * searchNode(Node * tree, char value){
    if(tree -> value == value){
        return tree;
    } 
    if(tree -> left != NULL){
        if((int) value < (int) tree -> value){
            return searchNode(tree -> left, value);
        }
    }
    if(tree -> right != NULL){
        return searchNode(tree -> right, value);
    }
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
    return searchNode(tree, value);
}

/**
 * @brief Change value of a node and return it
 * 
 * @param tree
 * @param old 
 * @param actual
 * @return Node* or NULL if value isn't in the tree
 */
extern Node * edit(Node * tree, char old, char current){
    Node * o = search(tree, old);
    if(o != NULL){
        o -> value = current;
    }
    return o;
}

/**
 * @brief Find the left child recursively
 * 
 * @param tree 
 * @return Node* or NULL
 */
Node * findLeftest(Node * tree){
    Node * current = tree;

    while (current && current -> left != NULL) {
        current = current -> left;
    }
 
    return current;
}

/**
 * @brief Remove an existing node from a tree by its value and
 * change the root after the deletion,
 * if the value cannot be found, root isn't changed
 * 
 * @param root 
 * @param value 
 * @return Node*
 */
extern Node * delete(Node * root, char value){

    if (root == NULL){
        return root;
    }
 
    if ((int) value < (int) root -> value){
        root -> left = delete(root -> left, value);
    } else if ((int) value > (int) root -> value){
        root -> right = delete(root -> right, value);
    } else {
        if (root -> left == NULL) {
            Node * temp = root -> right;
            free(root);
            return temp;
        } else if (root -> right == NULL) {
            Node * temp = root -> left;
            free(root);
            return temp;
        }

        Node * temp = findLeftest(root -> right);
        root -> value = temp -> value;
        root -> right = delete(root -> right, temp -> value);
    }
    return root;
}

/**
 * @brief Display non-null tree
 * 
 * @param tree 
 */
void display(Node * tree){
    if(tree != NULL){
        display(tree -> left);
        printf("%c ", tree -> value);
        display(tree -> right);
    }
}

int main(){
    srand(time(NULL));
    Node * tree = NULL;
    for(int i = 0; i < 26; i++){
        tree = insert(tree, 97 + rand() % 25);
    }
    display(tree);
    tree = delete(tree, 'b');
    printf("new root : %c\n", tree -> value);
    display(tree);
    return EXIT_SUCCESS;
}