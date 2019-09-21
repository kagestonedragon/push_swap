#include "../includes/push_swap.h"
#include "../includes/mlx.h"
#include <stdlib.h>

int             main(int argc, char **argv)
{
    t_push_swap *p;
    t_list      *flags;
    int         elements;

    flags = get_flags(argc, argv);
    elements = (flags) ? 2 : 1;
    validation(argc - elements, &argv[elements]);
    p = initialization(argc - elements, &argv[elements]);
    p->flags = flags;
    after_validation(p, elements, argc, argv);
    visualization_loop(p);
    push_swap_free(p);
    return (0);
}
