#include "push_swap.h"

int             main(int argc, char **argv)
{
    t_push_swap *p;
    
    if (argc == 1)
    	return (0);
    p = initialization(&argv[1]);
    validation(p);
    after_validation(p);
    push_swap_free(p);
    return (0);
}
