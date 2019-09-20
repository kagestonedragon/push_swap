#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include <stdio.h>

static int      get_operation(t_push_swap *p, char *line)
{
    if (!ft_strcmp("sa", line))
        return (swap_a(p));
    else if (!ft_strcmp("sb", line))
        return (swap_b(p));
    else if (!ft_strcmp("ss", line))
        return (swap(p));
    else if (!ft_strcmp("pa", line))
        return (push_a(p));
    else if (!ft_strcmp("pb", line))
        return (push_b(p));
    else if (!ft_strcmp("ra", line))
        return (rotate_a(p));
    else if (!ft_strcmp("rb", line))
        return (rotate_b(p));
    else if (!ft_strcmp("rr", line))
        return (rotate(p));
    else if (!ft_strcmp("rra", line))
        return (reverse_rotate_a(p));
    else if (!ft_strcmp("rrb", line))
        return (reverse_rotate_b(p));
    else if (!ft_strcmp("rrr", line))
        return (reverse_rotate(p));
    return (1);
}

static int      is_sorted(t_push_swap *p)
{
    if (!p->stack_a || !p->stack_a->next || p->stack_b)
        return (0);
    while (p->stack_a->next)
    {
        if (p->stack_a->value > p->stack_a->next->value)
            return (0);
        p->stack_a = p->stack_a->next;
    }
    return (1);
}
/*
static int          visualization(t_push_swap *p)
{
    t_list          *a;
    t_list          *b;

    a = p->stack_a;
    b = p->stack_b;
    dprintf(1, "\e[30;45m%-11s\e[30;106m%-11s\e[0m\n", "STACK A", "STACK B");
    while (a || b)
    {
        if (a && b)
            dprintf(1, "\e[30;47m%-11d\e[37;44m%-11d\e[0m\n", a->value, b->value);
        else if (a && !b)
            dprintf(1, "\e[30;47m%-11d\e[37;44m%-11s\e[0m\n", a->value, "-----------");
        else if (!a && b)
            dprintf(1, "\e[30;47m%-11s\e[37;44m%-11d\e[0m\n", "-----------", b->value);
        if (a)
            a = a->next;
        if (b)
            b = b->next;
    }
    return (0);
}
*/
int                 main(int argc, char **argv)
{
    t_push_swap     *p;
    char            *line;
    int             i;

    p = initialization(argc - 1, &argv[1]);
    //dprintf(1, "Your command: ");
    i = 0;
    line = NULL;
    while (get_next_line(0, &line))
    {
        if (get_operation(p, line))
        {
            dprintf(1, "\e[91mWrong Command!");
            break ;
        }
        //visualization(p);
        i++;
        //dprintf(1, "\nYour command: ");
    }
    if (is_sorted(p))
        dprintf(1, "\n\e[92mOK!\n");
    else
        dprintf(1, "\n\e[91mKO!\n");
    dprintf(1, "\e[91mTotal commands: %d\n", i);
    return (0);
}
