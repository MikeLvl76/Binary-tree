#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tree.h"
#include "list.c"

/**
 * @brief Create a Node variable with initializing all its attributes
 *
 * @param value
 * @return Node*
 */
extern Node *createNode(char value)
{
    if (!value)
    {
        return NULL;
    }
    Node *node = malloc(sizeof(Node));
    if (!node)
    {
        fprintf(stderr, "%s", "memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

/**
 * @brief Insert a new node to an existing node, by order according to decimal value in ASCII table
 *
 * @param node
 * @param value
 * @return Node*
 */
extern Node *insert(Node *node, char value)
{
    if (!value)
    {
        return NULL;
    }
    if (!node)
    {
        return createNode(value);
    }

    if ((int)value < (int)node->value)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
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
extern Node *search(Node *tree, char value)
{
    if (tree)
    {
        if (tree->value == value)
        {
            return tree;
        }
        if ((int)value < (int)tree->value)
        {
            return search(tree->left, value);
        }
        if ((int)value > (int)tree->value)
        {
            return search(tree->right, value);
        }
    }
    return tree;
}

/**
 * @brief Change value of a node and return it
 *
 * @param tree
 * @param old
 * @param actual
 * @return Node* or NULL if value isn't in the tree
 */
extern Node *edit(Node *tree, char old, char current)
{
    Node *o = search(tree, old);
    if (o)
    {
        o->value = current;
    }
    return o;
}

/**
 * @brief Find the left child recursively
 *
 * @param tree
 * @return Node* or NULL
 */
Node *findLeftest(Node *tree)
{
    Node *current = tree;

    while (current && current->left != NULL)
    {
        current = current->left;
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
extern Node *delete (Node *root, char value)
{

    if (!root)
    {
        return root;
    }

    if ((int)value < (int)root->value)
    {
        root->left = delete (root->left, value);
    }
    else if ((int)value > (int)root->value)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findLeftest(root->right);
        root->value = temp->value;
        root->right = delete (root->right, temp->value);
    }
    return root;
}

/**
 * @brief Display non-null tree
 *
 * @param tree
 */
void display(Node *tree)
{
    if (tree)
    {
        display(tree->left);
        printf("%c ", tree->value);
        display(tree->right);
    }
}

int main()
{
    srand(time(NULL));
    Node *tree = NULL;
    Cell *list = NULL;
    for (int i = 0; i < 26; i++)
    {
        char c = 97 + rand() % 25;
        push(&list, c);
        tree = insert(tree, list->value);
    }
    display(tree);
    printf("\n");
    return EXIT_SUCCESS;
}