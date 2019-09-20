#include "../../includes/push_swap.h"
#include <stdio.h>

static int  get_operation(int operation)
{
    if (operation == OP_PUSH_A)
        printf("pa\n");
    else if (operation == OP_PUSH_B)
        printf("pb\n");
    else if (operation == OP_R_ROTATE_A)
        printf("rra\n");
    else if (operation == OP_R_ROTATE_B)
        printf("rrb\n");
    else if (operation == OP_R_ROTATE)
        printf("rrr\n");
    else if (operation == OP_ROTATE_A)
        printf("ra\n");
    else if (operation == OP_ROTATE_B)
        printf("rb\n");
    else if (operation == OP_ROTATE)
        printf("rr\n");
    else if (operation == OP_SWAP_A)
        printf("sa\n");
    else if (operation == OP_SWAP_B)
        printf("sb\n");
    else if (operation == OP_SWAP)
        printf("ss\n");
    return (0);
}

int         print_operations(t_push_swap *p)
{
    t_list  *temporary;

    temporary = p->operations;
    while (temporary)
    {
        get_operation(temporary->value);
        temporary = temporary->next;
    }
    return (0);
}

int         print_total(t_push_swap *p)
{
    int     i;
    t_list  *temporary;

    temporary = p->operations;
    i = 0;
    while (temporary)
    {
        if (temporary->value != 0)
            i++;
        temporary = temporary->next;
    }
    printf("TOTAL %d\n", i);
    return (0);
}
