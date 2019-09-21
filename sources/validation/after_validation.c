#include "push_swap.h"

int         after_validation(t_push_swap *p)
{
    if (p->flags && p->flags->value == FLAG_VISUALIZATION)
    	p->w = create_window();
    algorithm(p);
    optimization(p);
    if (p->w)
    	create_visual_stack_a(p);
    print_operations(p);
    return (0);
}