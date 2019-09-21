#include "../../includes/push_swap.h"

static int  compare_elements_a(t_list *stack_a, int mediana, int amount)
{
    int     i;
    t_list  *temporary;

    i = -1;
    temporary = stack_a;
    while (++i < amount)
    {
        if (temporary->value < mediana)
            return (1);
        temporary = temporary->next;
    }
    return (0);
}

static int  get_operation(t_push_swap *p, int mediana, int *push_counter, int *rotate_counter)
{
    if (p->stack_a->value < mediana)
    {
        add_operation(p, OP_PUSH_B);
        *push_counter += 1;
    }
    else
    {
        add_operation(p, OP_ROTATE_A);
        *rotate_counter += 1;
    }
    return (0);
}

int         sorting_a(t_push_swap *p, int size)
{
    int     rotate_counter;
    int     push_counter;
    int     mediana_a;
    int     i;

    if (size <= 3)
        return (primitive_sorting_a(p));
    i = 0;
    rotate_counter = 0;
    push_counter = 0;
    mediana_a = mediana_stack_a(p, size);
    while (compare_elements_a(p->stack_a, mediana_a, (size - i)) && i++ < size)
        get_operation(p, mediana_a, &push_counter, & rotate_counter);
    if (rotate_counter > (p->size_a / 2) && p->size_a > 3)
        while (rotate_counter++ < p->size_a)
            add_operation(p, OP_ROTATE_A);
    else if (p->size_a > 3)
        while (rotate_counter--)
            add_operation(p, OP_R_ROTATE_A);
    sorting_a(p, (size - push_counter));
    sorting_b(p, push_counter);
    while (push_counter--)
        add_operation(p, OP_PUSH_A);
    return (0);
}
