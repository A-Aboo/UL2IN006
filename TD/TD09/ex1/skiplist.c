#include "skiplist.h"

int isRandomOK(float p)
{
    return (rand() / (float)RAND_MAX) < p;
}

void skiplist_init(Skiplist *sl, float p)
{
    sl->p = p;
    sl->numLevels = 0;
    sl->top = NULL;
    sl->bottom = NULL;
}

/* Q1.4 */
void skiplist_print(Skiplist *sl)
{
    Layer *current = sl->top;

    while (current != NULL){
        printf("%d : ", current->level);

        Cell *c = current->first;
        while (c != NULL){
            printf("->%d", c->val);
            c = c->next;
        }

        printf("\n");
        current = current->below;
    }
}

/* Q1.6 */
Cell **construct_path(Skiplist *sl, int value)
{
    if (sl->numLevels == 0)
        return NULL;

    Cell **path = (Cell **)malloc((sl->numLevels) * sizeof(Cell *));
    Layer *layer = sl->top;

    while (layer != NULL && layer->first->val > value){
        path[layer->level] = NULL;
        layer = layer->below;
    }

    if (layer != NULL){
        Cell *c = layer->first;

        while (c != NULL){
            if (c->next == NULL || c->next->val > value){
                path[layer->level] = c;
                c = c->below;
                layer = layer->below;
            }
            else
                c = c->next;
        }
    }

    return path;
}

void add_layer(Skiplist *sl, Cell *new)
{
    Layer *layer = (Layer *)malloc(sizeof(Layer));

    layer->level = sl->numLevels;
    layer->first = new;
    layer->above = NULL;
    layer->below = sl->top;

    if (sl->top != NULL)
        sl->top->above = layer;
    else
        sl->bottom = layer;

    sl->top = layer;
    sl->numLevels++;
}

void insert_rec(Skiplist *sl, int value, Cell **path, Layer *layer, Cell *below)
{
    Cell *new = (Cell *)malloc(sizeof(Cell));

    new->val = value;
    new->below = below;

    if (layer == NULL){
        new->next = NULL;
        add_layer(sl, new);

        if (isRandomOK(sl->p))
            insert_rec(sl, value, NULL, NULL, new);

        return;
    }

    if (path[layer->level] != NULL){
        new->next = path[layer->level]->next;
        path[layer->level]->next = new;
    }
    else {
        new->next = layer->first;
        layer->first = new;
    }

    if (isRandomOK(sl->p))
        insert_rec(sl, value, path, layer->above, new);
}

void skiplist_add(Skiplist *sl, int value)
{
    Cell **path = construct_path(sl, value);

    insert_rec(sl, value, path, sl->bottom, NULL);
    free(path);
}

int main(void)
{
    Skiplist sl;
    int t[] = {1, 6, 8, 9, 10, 11, 12, 17, 33, 40, 43};

    skiplist_init(&sl, 0.5);

    for (int i = 0; i < 11; i++)
        skiplist_add(&sl, t[i]);

    skiplist_print(&sl);

    return 0;
}
