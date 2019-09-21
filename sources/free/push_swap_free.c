#include "../../includes/push_swap.h"
#include <stdlib.h>

int         list_free(t_list *list)
{
    t_list  *temporary;

    while (list)
    {
        temporary = list;
        list = list->next;
        free(temporary);
    }
    return (0);
}

int         push_swap_free(t_push_swap *p)
{
    list_free(p->flags);
    list_free(p->stack_a);
    list_free(p->operations);
    free(p);
    return (0);
}
