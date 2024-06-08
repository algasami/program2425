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

struct node nil = {0};
struct node *root = &nil;

int is_nil(struct node const *const n)
{
    return n == &nil;
}

int is_root(struct node const *const n)
{
    return n->parent == &nil;
}

char get_color(struct node const *const n)
{
    return n->color == RBT_BLACK ? 'B' : 'R';
}

void transplant(struct node *const child, struct node *const parent, int pos)
{
    printf("Transplant %d to %d\n", child->key, parent->key);
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
    if (is_root(n))
    {
        root = n->left_child;
        printf("Root is now %d\n", n->left_child->key);
    }
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
    if (is_root(n))
    {
        root = n->right_child;
        printf("Root is now %d\n", n->right_child->key);
    }
    struct node *z = n->right_child;
    struct node *zl = z->left_child;
    transplant(z, n->parent, get_position(n));
    transplant(n, z, LEFT);
    transplant(zl, n, RIGHT);
}

void fixup(struct node *const node)
{
    // case 0: root is not black -> root is black
    if (is_root(node))
    {
        node->color = RBT_BLACK;
        return;
    }
    // red red
    if (node->parent->color == RBT_RED && node->color == RBT_RED)
    {
        if (is_root(node->parent))
        {
            node->parent->color = RBT_BLACK;
            return;
        }
        struct node *uncle;
        int parent_pos = get_position(node->parent);
        int self_pos = get_position(node);
        if (parent_pos == RIGHT)
        {
            uncle = node->parent->parent->left_child;
        }
        else
        {
            uncle = node->parent->parent->right_child;
        }

        // case 1: uncle is red
        if (uncle->color == RBT_RED)
        {
            node->parent->color = uncle->color = RBT_BLACK;
            node->parent->parent->color = RBT_RED;
            fixup(node->parent->parent);
            return;
        }
        // case 2: uncle is black
        if (parent_pos == RIGHT)
        {
            // line
            if (self_pos == RIGHT)
            {
                node->parent->color = RBT_BLACK;
                node->parent->parent->color = RBT_RED;
                rot_left(node->parent->parent);
            }
            else
            { // triangle
                struct node *current = node->parent;
                rot_right(node->parent);
                fixup(current);
            }
        }
        else
        {
            // line
            if (self_pos == LEFT)
            {
                node->parent->color = RBT_BLACK;
                node->parent->parent->color = RBT_RED;
                rot_right(node->parent->parent);
            }
            else
            { // triangle
                struct node *current = node->parent;
                rot_left(node->parent);
                fixup(current);
            }
        }
    }
}

void rbt_insertion(struct node *const node)
{
    struct node *cur = root;
    while (1)
    {
        if (node->key > cur->key)
        {
            if (is_nil(cur->right_child))
            {
                transplant(node, cur, RIGHT);
                fixup(node);
                break;
            }
            else
            {

                cur = cur->right_child;
            }
        }
        else
        {
            if (is_nil(cur->left_child))
            {
                transplant(node, cur, LEFT);
                fixup(node);
                break;
            }
            else
            {
                cur = cur->left_child;
            }
        }
        if (is_nil(cur))
        {
            break;
        }
    }
}
void rbt_deletion(struct node *const cur, struct node *const node)
{
}

void dfs(struct node *const cur, unsigned int depth)
{
    if (is_nil(cur))
        return;
    for (unsigned int i = 0; i < depth; i++)
    {
        printf("\t");
    }
    printf("%c%d\n", get_color(cur), cur->key);
    dfs(cur->right_child, depth + 1);
    dfs(cur->left_child, depth + 1);
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
    root = instantiate(&p, 1);
    root->color = RBT_BLACK;
    int x;
    while (scanf("%d", &x))
    {
        struct node *n = instantiate(&p, x);
        rbt_insertion(n);
    }
    dfs(root, 0);
    free_pool(&p);
    return 0;
}