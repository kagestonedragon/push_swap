#include "push_swap.h"

int         count_keeps(t_list *list)
{
    int     counter;
    t_list  *temporary;

    counter = 0;
    temporary = list;
    while (temporary)
    {
        if (temporary->keep)
            counter += 1;
        temporary = temporary->next;
    }
    return (counter);
}

int         algorithm(t_push_swap *p)
{
    p->keeps_a = count_keeps(p->stack_a);
}
