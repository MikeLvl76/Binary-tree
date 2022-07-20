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
    if (value == '\0')
    {
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    Cell *cell = malloc(sizeof(Cell));
    if (!cell)
    {
        fprintf(stderr, "%s", "memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    cell->next = NULL;
    cell->previous = NULL;
    cell->value = value;
    return cell;
}

/**
 * @brief Insert a new cell to list of cells,
 * if list is NULL then a cell is created with value in arg
 *
 * @param list
 * @param value
 * @return Cell*
 */
extern Cell *insert(Cell *list, char value)
{
    if (value == '\0')
    {
        fprintf(stderr, "%s", "error empty value\n");
        exit(EXIT_FAILURE);
    }
    if (list == NULL)
    {
        return createCell(value);
    }

    Cell *inserted = insert(list->next, value);
    list->next = inserted;
    list->next->previous = list;

    return list;
}

/**
 * @brief Search a cell by its value in a list
 *
 * @param list
 * @param value
 * @return true or false whether the cell is in or not
 */
extern bool search(Cell *list, char value)
{
    Cell *forward = list;
    Cell *backward = list;
    while (forward != NULL)
    {
        if (forward->value == value)
            return true;
        forward = forward->next;
    }
    while (backward != NULL)
    {
        if (backward->value == value)
            return true;
        backward = backward->previous;
    }
    return false;
}

/**
 * @brief Get the size of a list
 *
 * @param list
 * @return int
 */
extern int size(Cell *list)
{
    Cell *forward = list;
    Cell *backward = list;
    int count = 0;
    while (forward != NULL)
    {
        count++;
        forward = forward->next;
    }
    while (backward != NULL)
    {
        count++;
        backward = backward->previous;
    }
    return count - 1; // one element counted twice
}

int main()
{
    srand(time(NULL));
    Cell *cell = NULL;
    for (int i = 0; i < 26; i++)
    {
        char c = 97 + rand() % 25;
        printf("%c ", c);
        cell = insert(cell, c);
    }
    printf("\n%c ", cell->value);
    Cell *iterate = cell;
    while (iterate->next != NULL)
    {
        printf("%c ", iterate->next->value);
        iterate = iterate->next;
    }
    char c = 97 + rand() % 25;
    if (search(cell, c))
    {
        printf("\nFound %c !\n", c);
    }
    else
    {
        printf("\n%c was not found !\n", c);
    }
    printf("Size: %d\n", size(cell));
    return EXIT_SUCCESS;
}