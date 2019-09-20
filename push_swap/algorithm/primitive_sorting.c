#include "../../includes/push_swap.h"

int         is_sorted(t_push_swap *p)
{
    t_list  *temporary;

    temporary = p->stack_a;
    if (!p->stack_a || !p->stack_a->next || p->stack_b)
        return (0);
    while (temporary->next)
    {
        if (temporary->value > temporary->next->value)
            return (0);
        temporary = temporary->next;
    }
    return (1);
}

int         get_last_element(t_push_swap *p)
{
    t_list  *temporary;

    temporary = p->stack_a;
    while (temporary->next)
        temporary = temporary->next;
    return (temporary->value);
}

int     primitive_sorting(t_push_swap *p)
{
    while (!is_sorted(p) && p->size_a <= 3)
    {
        if (p->stack_a->value > p->stack_a->next->value)
        {
            if (p->size_a > 2 && p->stack_a->value < get_last_element(p))
                add_operation(p, OP_SWAP_A);
            else
                add_operation(p, OP_ROTATE_A);
        }
        else if (!is_sorted(p))
        {
            if (p->stack_a->value < p->stack_a->next->value)
            {
                if (p->size_a > 2 && p->stack_a->value > get_last_element(p))
                    add_operation(p, OP_R_ROTATE_A);
                else
                    add_operation(p, OP_ROTATE_A);
            }
        }
    }
    return (0);
}
