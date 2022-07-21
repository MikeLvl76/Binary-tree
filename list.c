#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"

/**
 * @brief Create a Cell variable with initializing all its attributes
 *
 * @param value
 * @return Cell*
 */
extern Cell *createCell(char value)
{
    if (!value)
    {
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    Cell *cell = (Cell *)malloc(sizeof(Cell));
    if (!cell)
    {
        fprintf(stderr, "%s", "memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    cell->next = NULL;
    cell->value = value;
    return cell;
}

/**
 * @brief Push a new cell to list of cells,
 * if list is NULL then a cell is created with value in arg
 *
 * @param list
 * @param value
 * @return Cell*
 */
extern void push(Cell **list, char value)
{
    if (!value)
    {
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    Cell *n = createCell(value);
    n->next = *list;
    *list = n;
}

/**
 * @brief Find a cell by its value in a list
 *
 * @param list
 * @param value
 * @return true or false whether the cell is in or not
 */
extern bool find(Cell *list, char value)
{
    Cell *current = list;
    while (current)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

/**
 * @brief Retrieve and remove the first cell of the list
 *
 * @param list
 * @return Cell* or NULL if list is empty
 */
extern char pop(Cell **list)
{
    if (!(*list))
    {
        return '/';
    }
    Cell *removed = *list;
    char result = (*list)->value;

    (*list) = (*list)->next;
    free(removed);

    return result;
}

/**
 * @brief Get the size of a list
 *
 * @param list
 * @return int
 */
extern int size(Cell *list)
{
    Cell *current = list;
    int count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

extern void display(Cell *list)
{
    Cell *current = list;
    while (current != NULL)
    {
        printf("%c -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    srand(time(NULL));
    Cell *cell = NULL;
    for (int i = 0; i < 26; i++)
    {
        char c = 97 + rand() % 25;
        push(&cell, c);
    }
    display(cell);
    printf("Size: %d\n", size(cell));
    char r = pop(&cell);
    printf("Pop %c\n", r ? r : '/');
    display(cell);
    printf("Size: %d\n", size(cell));
    return EXIT_SUCCESS;
}