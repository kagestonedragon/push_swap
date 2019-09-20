#include "../../includes/push_swap.h"
#include <stdlib.h>

t_push_swap     *initialization(int size, char **elements)
{
    t_push_swap *p;

    (void)size;
    p = (t_push_swap *)malloc(sizeof(t_push_swap));
    p->stack_a = new_list(elements);
    p->stack_b = NULL;
    p->operations = NULL;
    p->size = size;
    p->size_a = size;
    p->size_b = 0;
    return (p);
}
