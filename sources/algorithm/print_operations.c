#include "../../includes/push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static int  get_operation(int operation)
{
    if (operation == OP_PUSH_A)
        write(1, "pa\n", 3);
    else if (operation == OP_PUSH_B)
        write(1, "pb\n", 3);
    else if (operation == OP_R_ROTATE_A)
        write(1, "rra\n", 4);
    else if (operation == OP_R_ROTATE_B)
        write(1, "rrb\n", 4);
    else if (operation == OP_R_ROTATE)
        write(1, "rrr\n", 4);
    else if (operation == OP_ROTATE_A)
        write(1, "ra\n", 3);
    else if (operation == OP_ROTATE_B)
        write(1, "rb\n", 3);
    else if (operation == OP_ROTATE)
        write(1, "rr\n", 3);
    else if (operation == OP_SWAP_A)
        write(1, "sa\n", 3);
    else if (operation == OP_SWAP_B)
        write(1, "sb\n", 3);
    else if (operation == OP_SWAP)
        write(1, "ss\n", 3);
    return (0);
}

int         create_visual_stack_a(t_push_swap *p, char **elements)
{
    list_free(p->stack_a);
    p->stack_a = new_list(elements);
    return (0);
}

int         print_operations(t_push_swap *p)
{
    t_list  *temporary;

    temporary = p->operations;
    if (p->flags && p->flags->value == FLAG_VISUALIZATION)
    { 
        draw_stacks(p);
        while (temporary)
        {
            do_operation(p, temporary->value);
            get_operation(temporary->value);
            p->w->operation = temporary->value;
            draw_stacks(p);
            temporary = temporary->next;
        }
    }
    else
    {
        while (temporary)
        {
            get_operation(temporary->value);
            temporary = temporary->next;
        }
    }
    return (0);
}