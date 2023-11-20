#include <stdio.h>

struct Stack
{
    int *data;
    int size;
    int capacity;
};

enum ERROR
{
    REALLOC_FAIL = 1,
    POP_FAIL;
};

const int POISON = 666;
const float sample = 2.5;

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

void StackPush (struct Stack *pstk, int elem, enum ERROR* error)
{
    if (pstk->size >= pstk->capacity)
    {
        int *temp = realloc (pstk->data, pstk->capacity * 2);
        if (temp == NULL)
        {
            *error = REALLOC_FAIL;
            return POISON;
        }
        else
            pstk->data = temp;
    }
    *(pstk->data + pstk->size) = elem;
    ++(pstk->size);
}

int StackPop (struct Stack *pstk, enum ERROR* error)
{
    if (pstk->size <= 0)
    {
        *error = POP_FAIL;
        return POISON;
    }
    --(pstk->size);
    int elem = *(pstk->data + pstk->size);
    if (pstk->size * 2 < pstk->capacity / sample)
    {
        int *temp = realloc (pstk->data, pstk->capacity / 2);
        if (temp == NULL)
        {
            *error = REALLOC_FAIL;
            return POISON;
        }
        else
            pstk->data = temp;
    }
    return elem;
}
