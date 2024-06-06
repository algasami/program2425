#include <stdio.h>
#include <stdlib.h>

#define RBT_BLACK 0
#define RBT_RED 1

#define LEFT 0
#define RIGHT 1

struct node
{
    int color, key;
    struct node *parent, *left_child, *right_child;
};

struct node_pool
{
    struct node *seq;
    size_t size, capacity;
};

const struct node nil = {0};

int is_nil(struct node const *const n)
{
    return n == &nil;
}

int is_root(struct node const *const n)
{
    return n->parent == &nil;
}

void transplant(struct node *const child, struct node *const parent, int pos)
{
    child->parent = parent;
    if (is_nil(parent))
        return;
    if (pos == LEFT)
        parent->left_child = child;
    else
        parent->right_child = child;
}

int get_position(struct node *const n)
{
    if (is_nil(n->parent))
        return LEFT;
    if (n->parent->left_child == n)
        return LEFT;
    return RIGHT;
}

void rot_right(struct node *const n)
{
    if (is_nil(n->left_child))
        return;
    struct node *z = n->left_child;
    struct node *zr = z->right_child;
    transplant(z, n->parent, get_position(n));
    transplant(n, z, RIGHT);
    transplant(zr, n, LEFT);
}

void rot_left(struct node *const n)
{
    if (is_nil(n->right_child))
        return;
    struct node *z = n->right_child;
    struct node *zl = z->left_child;
    transplant(z, n->parent, get_position(n));
    transplant(n, z, LEFT);
    transplant(zl, n, RIGHT);
}

void rbt_insertion(struct node *const root, int key)
{
}
void rbt_deletion(struct node *const root, int key)
{
}

struct node_pool alloc_pool(size_t size)
{
    struct node *pool = (struct node *)malloc(sizeof(struct node) * size);

    return (struct node_pool){
        .seq = pool,
        .capacity = size,
        .size = 0};
}

void free_pool(struct node_pool *const p)
{
    free(p->seq);
}

struct node *instantiate(struct node_pool *const p, int key)
{
    if (p->size + 1 > p->capacity)
    {
        printf("Warning! Pool overloaded...");
        return &nil;
    }
    struct node *n = p->seq + ++p->size;
    n->left_child = &nil;
    n->right_child = &nil;
    n->parent = &nil;
    n->key = key;
    n->color = RBT_RED;
    return n;
}

int main()
{
    struct node_pool p = alloc_pool(100);

    free_pool(&p);
    return 0;
}