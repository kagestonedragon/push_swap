#include "push_swap.h"

int         push_b(t_push_swap *p)
{
    t_list  *temporary;

    if (!p->stack_a)
        return (0);
    temporary = p->stack_a->next;
    p->stack_a->next = p->stack_b;
    p->stack_b = p->stack_a;
    p->stack_a = temporary;
    return (0);
}

int         push_a(t_push_swap *p)
{
    t_list  *temporary;

    if (!p->stack_b)
        return (0);
    temporary = p->stack_b->next;
    p->stack_b->next = p->stack_a;
    p->stack_a = p->stack_b;
    p->stack_b = temporary;
    return (0);
}
