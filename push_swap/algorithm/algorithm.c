#include "../../includes/push_swap.h"
#include <stdio.h>

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

int         ft_sort_new(t_push_swap *p, int f)
{
    if (f == 1)
    {
        (p->size_a > 1 && p->stack_a->value > p->stack_a->next->value) ? add_operation(p, OP_SWAP_A) : 0;
        if (p->size_a > 2 && p->stack_a->next->value > p->stack_a->next->next->value)
        {
            add_operation(p, OP_ROTATE_A);
            add_operation(p, OP_SWAP_A);
            add_operation(p, OP_R_ROTATE_A);
        }
        (p->size_a > 1 && p->stack_a->value > p->stack_a->next->value) ? add_operation(p, OP_SWAP_A) : 0;
    }
    else
    {
        (p->size_b > 1 && p->stack_b->value < p->stack_b->next->value) ? add_operation(p, OP_SWAP_B) : 0;
        if (p->size_b > 2 && p->stack_b->next->value < p->stack_b->next->next->value)
        {
            add_operation(p, OP_ROTATE_B);
            add_operation(p, OP_SWAP_B);
            add_operation(p, OP_R_ROTATE_B);
        }
        (p->size_b > 1 && p->stack_b->value < p->stack_b->next->value) ? add_operation(p, OP_SWAP_B) : 0;
    }
    return (0);
}

int         step_one(t_push_swap *p, int size, int i)
{
    int     rotate_counter;
    int     push_counter;
    int     mediana_a;

    if (size <= 3)
        return (ft_sort_new(p, 1));
    rotate_counter = 0;
    push_counter = 0;
    mediana_a = mediana_stack_a(p, size);
    while (compare_elements_a(p->stack_a, mediana_a, (size - i)) && i++ < size)
    {
        (p->stack_a->value < mediana_a) ? push_counter++ : rotate_counter++;
        (p->stack_a->value < mediana_a) ? add_operation(p, OP_PUSH_B) : add_operation(p, OP_ROTATE_A);
    }
    if (rotate_counter > (p->size_a / 2) && p->size_a > 3)
        while (rotate_counter++ < p->size_a)
            add_operation(p, OP_ROTATE_A);
    else if (p->size_a > 3)
        while (rotate_counter--)
            add_operation(p, OP_R_ROTATE_A);
    step_one(p, (size - push_counter), 0);
    step_two(p, push_counter, 0);
    while (push_counter--)
        add_operation(p, OP_PUSH_A);
    return (0);
}

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

int         step_two(t_push_swap *p, int size, int i)
{
    int     mediana_b;
    int     rotate_counter;
    int     push_counter;

    if (size <= 3)
        return (ft_sort_new(p, 0));
    rotate_counter = 0;
    push_counter = 0;
    mediana_b = mediana_stack_b(p, size);
    while (compare_elements_b(p->stack_b, mediana_b, (size - i)) && i++ < size)
    {
        (p->stack_b->value > mediana_b) ? push_counter++ : rotate_counter++;
        (p->stack_b->value > mediana_b) ? add_operation(p, OP_PUSH_A) : add_operation(p, OP_ROTATE_B);
    }
    step_one(p, push_counter, 0);
    if (rotate_counter > (p->size_b / 2) && p->size_b > 3)
        while (rotate_counter++ < p->size_b)
            add_operation(p, OP_ROTATE_B);
    else if (p->size_b > 3)
        while (rotate_counter--)
            add_operation(p, OP_R_ROTATE_B);
    step_two(p, (size - push_counter), 0);
    while (push_counter--)
        add_operation(p, OP_PUSH_B);
    return (0);

}

int         algorithm(t_push_swap *p)
{
    if (p->size > 3)
        step_one(p, p->size_a, 0);
    else
        primitive_sorting(p);
    return (0);

}
