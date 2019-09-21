#include "../../includes/push_swap.h"
#include <stdlib.h>

int             max(t_list *stack)
{
    t_list      *temporary_a;
    int         temporary;

    temporary_a = stack;
    temporary = 0;
    while (temporary_a)
    {
        if (temporary_a->value > temporary)
            temporary = temporary_a->value;
        temporary_a = temporary_a->next;
    }
    return (temporary);
}

t_push_swap     *initialization(int size, char **elements)
{
    t_push_swap *p;

    (void)size;
    p = (t_push_swap *)malloc(sizeof(t_push_swap));
    p->stack_a = new_list(elements);
    p->max_value = max(p->stack_a);
    p->w = NULL;
    p->stack_b = NULL;
    p->operations = NULL;
    p->size = size;
    p->size_a = size;
    p->size_b = 0;
    return (p);
}
