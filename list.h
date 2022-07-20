#ifndef LIST
#define LIST

#include <stdbool.h>

typedef struct Cell Cell;

struct Cell {
    Cell * next;
    Cell * previous;
    char value;
};

extern Cell * createCell(char value);
extern Cell * insert(Cell * list, char value);
extern bool search(Cell * list, char value);
extern Cell * edit(Cell * list, char old, char n);
extern Cell * rem(Cell * list, char value);
extern int length(Cell * list);
extern void display(Cell * list);

#endif