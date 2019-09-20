#include "../../includes/push_swap.h"
#include <stdlib.h>

int         optimize(t_list *h, int f)
{
    if (h->next == NULL)
        return (0);
    if (h->value == OP_SWAP_A && h->next->value == OP_SWAP_B)
        f = 1;
    else if (h->value == OP_SWAP_B && h->next->value == OP_SWAP_A)
        f = 1;
    if (h->value == OP_ROTATE_A && h->next->value == OP_ROTATE_B)
        f = 2;
    else if (h->value == OP_ROTATE_B && h->next->value == OP_ROTATE_A)
        f = 2;
    if (h->value == OP_R_ROTATE_A && h->next->value == OP_R_ROTATE_B)
        f = 3;
    else if (h->value == OP_R_ROTATE_B && h->next->value == OP_R_ROTATE_A)
        f = 3;
    if (h->value == OP_PUSH_A && h->next->value == OP_PUSH_B)
        f = 4;
    else if (h->value == OP_PUSH_B && h->next->value == OP_PUSH_A)
        f = 4;
    if (h->value == OP_ROTATE_A && h->next->value == OP_R_ROTATE_A)
        f = 5;
    else if (h->value == OP_R_ROTATE_A && h->next->value == OP_ROTATE_A)
        f = 5;
    if (h->value == OP_ROTATE_B && h->next->value == OP_R_ROTATE_B)
        f = 6;
    else if (h->value == OP_R_ROTATE_B && h->next->value == OP_ROTATE_B)
        f = 6;
    if (f == 1)
        h->value = OP_SWAP;
    else if (f == 2)
        h->value = OP_ROTATE;
    else if (f == 3)
        h->value = OP_R_ROTATE;
    return (f);
}

int         optimization(t_push_swap *p, int f, int x)
{
    t_list  *point;
    t_list  *del;

    while (f)
    {
        point = p->operations;
        f = 0;
        del = point;
        while (point != NULL)
        {
            if ((x = optimize(point, 0)) != 0)
            {
                f = 1;
                if (x == 4 || x == 5 || x == 6)
                {
                    del->next = point->next->next;
                    free(point->next);
                    free(point);
                    point = del;
                }
                else
                {
                    del = point->next;
                    point->next = point->next->next;
                    free(del);
                }
            }
            del = point;
            point = point->next;
        }
        
    }
    return (0);
}
