#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>

/* Q1.3 */
typedef struct s_cell
{
    int val;
    struct s_cell *next;
    struct s_cell *below;
} Cell;

typedef struct s_layer
{
    int level;
    Cell *first;
    struct s_layer *below;
    struct s_layer *above;
} Layer;

typedef struct
{
    float p;
    int numLevels;
    Layer *top;
    Layer *bottom;
} Skiplist;

int isRandomOK(float p);
void skiplist_init(Skiplist *sl, float p);

/* Q1.4 */
void skiplist_print(Skiplist *sl);

/* Q1.6 */
Cell **construct_path(Skiplist *sl, int value);
void add_layer(Skiplist *sl, Cell *new);
void insert_rec(Skiplist *sl, int value, Cell **path, Layer *layer, Cell *below);
void skiplist_add(Skiplist *sl, int value);

#endif
