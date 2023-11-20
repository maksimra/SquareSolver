#include <stdio.h>

struct Stack
{
    int *data;
    int size;
    int capacity;
};

enum ERROR
{
    realloc_FAIL = 1,
    pop_FAIL;
};

int main (void)
{
    enum ERROR error = 0;
    struct Stack stk = {0};
    StackCtor (&stk, 20);
    StackPush (&stk, 10, &error);
    int x = StackPop (&stk, &error);
    StackDtor (&stk);
    return 0;
}

void StackCtor (struct Stack *pstk, int funct_capacity)
{
    pstk->data = (int*) calloc (capacity, sizeof (int));
    stk->size = 0;
    stk->capacity = funct_capacity;
}

void StackDtor (struct Stack *pstk)
{
    free (pstk->data);
    pstk->data = NULL;
    pstk->capacity = 0;
    pstk->size = 0;
}

void StackPush (struct Stack *pstk, int el, enum ERROR* error)
{
    //if (pstk->size >= pstk->capacity)
    //{
    //    pstk->data = (realloc (pstk->data, pstk->capacity * 2) != NULL) ? realloc (pstk->data, pstk->capacity * 2) ://TODO:спросить
    *(pstk->data + pstk->size) = el;
    ++(pstk->size);
}

int StackPop (struct Stack *pstk, enum ERROR* error)
{
    if (pstk->pop == 0)
    {
        *error = pop_FAIL;
        return -1; //спросить, что лучше
    }
    --(pstk->size);
    int el = *(pstk->data + pstk->size);
    return el;
}
