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
    inserted->previous = list->next;

    return list;
}

/**
 * @brief Search a cell by its value in a list
 *
 * @param list
 * @param value
 * @return Cell* or NULL if value isn't in the list
 */
extern Cell *search(Cell *list, char value)
{
    if (list != NULL)
    {

        if (list->value == value)
        {
            return list;
        }

        Cell *prev = search(list->previous, value);
        Cell *nxt = search(list->next, value);
        if (prev == NULL)
        {
            return nxt;
        }
        return prev;
    }
    return list;
}

int main()
{
    srand(time(NULL));
    Cell *cell = NULL;
    for (int i = 0; i < 26; i++)
    {
        char c = 97 + rand() % 25;
        printf("%c\n", c);
        cell = insert(cell, c);
    }
    while(cell -> next != NULL){
        printf("Value %c\n", cell -> next -> value);
        cell = cell -> next;
    }
    return EXIT_SUCCESS;
}