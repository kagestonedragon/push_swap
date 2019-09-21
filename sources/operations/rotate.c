#include "push_swap.h"
#include <stdlib.h>

int         rotate_a(t_push_swap *p)
{
    t_list  *list;
    t_list  *temporary;

    if (!p->stack_a || !p->stack_a->next)
        return (0);
    list = p->stack_a;
    temporary = p->stack_a->next;
    while (list->next)
        list = list->next;
    p->stack_a->next = NULL;
    list->next = p->stack_a;
    p->stack_a = temporary;
    return (0);
}

int         rotate_b(t_push_swap *p)
{
    t_list  *list;
    t_list  *temporary;

    if (!p->stack_b || !p->stack_b->next)
        return (0);
    list = p->stack_b;
    temporary = p->stack_b->next;
    while (list->next)
        list = list->next;
    p->stack_b->next = NULL;
    list->next = p->stack_b;
    p->stack_b = temporary;
    return (0);
}

int         rotate(t_push_swap *p)
{
    rotate_a(p);
    rotate_b(p);
    return (0);
}
