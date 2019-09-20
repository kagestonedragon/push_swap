#include "../includes/push_swap.h"
#include <stdio.h>

int             debug_a(t_push_swap *p)
{
    t_list      *temporary;

    temporary = p->stack_a;
    while (temporary)
    {
        printf("%d ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
    return (0);
}

int             debug_b(t_push_swap *p)
{
    t_list      *temporary;

    temporary = p->stack_b;
    while (temporary)
    {
        printf("%d ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
    return (0);
}

int             test_print(t_list *stack)
{
    t_list      *temporary;

    temporary = stack;
    while (temporary)
    {
        printf("%d ", temporary->value);
        temporary = temporary->next;
    }
    return (0);
}

int             main(int argc, char **argv)
{
    t_push_swap *p;

    p = initialization(argc - 1, &argv[1]);
    algorithm(p);
    optimization(p, 1, 0);
    print_operations(p);
    //print_total(p);
    //test_print(p->stack_a);
    return (0);
}
