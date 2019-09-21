#include "../../includes/push_swap.h"
#include <stdlib.h>

static int      get_solution(t_list *o)
{
    int         solution;

    if (o->next == NULL)
        return (0);
    solution = 0;
    if ((o->value == OP_SWAP_A && o->next->value == OP_SWAP_B) || (o->value == OP_SWAP_B && o->next->value == OP_SWAP_A))
        solution = 1;
    if ((o->value == OP_ROTATE_A && o->next->value == OP_ROTATE_B) || (o->value == OP_ROTATE_B && o->next->value == OP_ROTATE_A))
        solution = 2;
    if ((o->value == OP_R_ROTATE_A && o->next->value == OP_R_ROTATE_B) || (o->value == OP_R_ROTATE_B && o->next->value == OP_R_ROTATE_A))
        solution = 3; 
    if ((o->value == OP_PUSH_A && o->next->value == OP_PUSH_B) || (o->value == OP_PUSH_B && o->next->value == OP_PUSH_A))
        solution = 4;
    if ((o->value == OP_ROTATE_A && o->next->value == OP_R_ROTATE_A) || (o->value == OP_R_ROTATE_A && o->next->value == OP_ROTATE_A))
        solution = 5;
    if ((o->value == OP_ROTATE_B && o->next->value == OP_R_ROTATE_B) || (o->value == OP_R_ROTATE_B && o->next->value == OP_ROTATE_B))
        solution = 6;
    return (solution); 
}

static t_list   *optimize_by_solution(t_list *temporary, t_list *temporary_1, int solution)
{
    if (solution == 1)
        temporary->value = OP_SWAP;
    else if (solution == 2)
        temporary->value = OP_ROTATE;
    else if (solution == 3)
        temporary->value = OP_R_ROTATE;
    else if (solution == 4 || solution == 5 || solution == 6)
    {
        temporary_1->next = temporary->next->next;
        free(temporary->next);
        free(temporary);
        temporary = temporary_1;
    }
    if (solution != 4 && solution != 5 && solution != 6)
    {
        temporary_1 = temporary->next;
        temporary->next = temporary->next->next;
        free(temporary_1);
    }
    return (temporary);
}

int             optimization(t_push_swap *p)
{
    t_list      *temporary;
    t_list      *temporary_1;
    int         end;
    int         solution;   

    end = 1;
    while (end)
    {
        end = 0;
        temporary = p->operations;
        temporary_1 = temporary;
        while (temporary)
        {
            if ((solution = get_solution(temporary)))
            {
                end = 1;
                temporary = optimize_by_solution(temporary, temporary_1, solution);
            }
            temporary_1 = temporary;
            temporary = temporary->next;
        }
        
    }
    return (0);
}
