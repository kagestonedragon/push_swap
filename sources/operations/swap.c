#include "../../includes/push_swap.h"

int         swap_a(t_push_swap *p)
{
    t_list  *temporary;

    if (!p->stack_a || !p->stack_a->next)
        return (0);
    temporary = p->stack_a->next;
    p->stack_a->next = p->stack_a->next->next;
    temporary->next = p->stack_a;
    p->stack_a = temporary;
    return (0);
}

int         swap_b(t_push_swap *p)
{
    t_list  *temporary;

    if (!p->stack_b || !p->stack_b->next)
        return (0);
    temporary = p->stack_b->next;
    p->stack_b->next = p->stack_b->next->next;
    temporary->next = p->stack_b;
    p->stack_b = temporary;
    return (0);
}

int         swap(t_push_swap *p)
{
    swap_a(p);
    swap_b(p);
    return (0);
}
