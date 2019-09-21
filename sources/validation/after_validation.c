#include "../../includes/push_swap.h"
#include <stdlib.h>

t_list      *get_flags(int argc, char **argv)
{
    t_list  *flags;

    flags = NULL;
    if (argc >= 2)
    {
        if (argv[1][0] == '-' && argv[1][1] == 'v')
            flags = create_list(FLAG_VISUALIZATION);
    }
    return (flags);
}

int         after_validation(t_push_swap *p, int elements, int argc, char **argv)
{
    if (!((!p->flags && argc == 2) || (p->flags && argc == 3) || is_sorted(p)))
    {
        if (p->flags && p->flags->value == FLAG_VISUALIZATION)
            p->w = create_window();
        algorithm(p);
        optimization(p);
        if (p->w)
            create_visual_stack_a(p, &argv[elements]);
        print_operations(p);;
    }
    return (0);
}
