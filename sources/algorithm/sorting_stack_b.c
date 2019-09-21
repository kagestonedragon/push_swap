#include "../../includes/push_swap.h"

static int  compare_elements_b(t_list *stack_b, int mediana, int amount)
{
    int     i;
    t_list  *temporary;

    i = -1;
    temporary = stack_b;
    while (++i < amount)
    {
        if (temporary->value > mediana)
            return (1);
        temporary = temporary->next;
    }
    return (0);
}

static int get_operation(t_push_swap *p, int mediana, int *push_counter, int *rotate_counter)
{
    if (p->stack_b->value > mediana)
    {
        add_operation(p, OP_PUSH_A);
        *push_counter += 1;
    }
    else
    {
        add_operation(p, OP_ROTATE_B);
        *rotate_counter += 1;
    }
    return (0);
}

int         sorting_b(t_push_swap *p, int size)
{
    int     mediana_b;
    int     rotate_counter;
    int     push_counter;
    int     i;

    if (size <= 3)
        return (primitive_sorting_b(p));
    i = 0;
    rotate_counter = 0;
    push_counter = 0;
    mediana_b = mediana_stack_b(p, size);
    while (compare_elements_b(p->stack_b, mediana_b, (size - i)) && i++ < size)
        get_operation(p, mediana_b, &push_counter, &rotate_counter);
    sorting_a(p, push_counter);
    if (rotate_counter > (p->size_b / 2) && p->size_b > 3)
        while (rotate_counter++ < p->size_b)
            add_operation(p, OP_ROTATE_B);
    else if (p->size_b > 3)
        while (rotate_counter--)
            add_operation(p, OP_R_ROTATE_B);
    sorting_b(p, (size - push_counter));
    while (push_counter--)
        add_operation(p, OP_PUSH_B);
    return (0);
}
