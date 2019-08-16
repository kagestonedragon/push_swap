#include "../includes/push_swap.h"
#include <stdio.h>

t_list      *flag_sa(t_list *list_a)
{
    t_list  *swap;

    swap = list_a->next;
    list_a->next = list_a->next->next;
    swap->next = list_a;
    return (swap);
}

t_list      *flag_ra(t_list *list_a)
{
    t_list  *_list;

    _list = list_a->next;
    while (list_a->next->next)
    {
        list_a = flag_sa(list_a);
        list_a = list_a->next;
    }
    return (_list);
}
