#ifndef LIST
#define LIST

#include <stdbool.h>

typedef struct Cell Cell;

struct Cell
{
    Cell *next;
    char value;
};

extern Cell *createCell(char value);
extern void push(Cell **list, char value);
extern bool find(Cell *list, char value);
extern char pop(Cell **list);
extern Cell *peekFirst(Cell *list);
extern Cell *peekLast(Cell *list);
extern Cell *edit(Cell *list, char old, char n);
extern Cell *rem(Cell *list, char value);
extern int size(Cell *list);
extern void display(Cell *list);

#endif