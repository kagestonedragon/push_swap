#include "push_swap.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include "ft_printf.h"

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

static int          color_visualization(t_push_swap *p)
{
    t_list          *a;
    t_list          *b;

    a = p->stack_a;
    b = p->stack_b;
    ft_dprintf(1, "\e[30;45m%-11s\e[30;106m%-11s\e[0m\n", "STACK A", "STACK B");
    while (a || b)
    {
        if (a && b)
            ft_dprintf(1, "\e[30;47m%-11d\e[37;44m%-11d\e[0m\n", a->value, b->value);
        else if (a && !b)
            ft_dprintf(1, "\e[30;47m%-11d\e[37;44m%-11s\e[0m\n", a->value, "-----------");
        else if (!a && b)
            ft_dprintf(1, "\e[30;47m%-11s\e[37;44m%-11d\e[0m\n", "-----------", b->value);
        if (a)
            a = a->next;
        if (b)
            b = b->next;
    }
    return (0);
}

int 				read_lines(t_push_swap *p)
{
	char 			*line;
	int 			counter;
	
	line = NULL;
	counter = 0;
	while (get_next_line(0, &line))
	{
		counter += 1;
		if (get_operation(p, line))
		{
			write(1, "Error\n", 6);
			break ;
		}
		if (p->flags && p->flags->value == FLAG_VISUALIZATION)
			color_visualization(p);
	}
	if (is_sorted(p))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (p->flags && p->flags->value == FLAG_TOTAL)
		ft_putnbr(counter);
	return (0);
}

int                 main(int argc, char **argv)
{
    t_push_swap     *p;

    if (argc == 1)
    	return (0);
    p = initialization(&argv[1]);
    validation(p);
    read_lines(p);
    push_swap_free(p);
    return (0);
}