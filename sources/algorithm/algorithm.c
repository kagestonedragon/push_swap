#include "push_swap.h"

int         algorithm(t_push_swap *p)
{
    if (p->size > 3)
        sorting_a(p, p->size_a);
    else
        primitive_sorting(p);
    return (0);

}
