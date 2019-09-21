#include "../../includes/push_swap.h"
#include "../../includes/mlx.h"
#include <stdlib.h>

static int  close(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int         visualization_loop(t_push_swap *p)
{
    if (p->w)
    {
        mlx_hook(p->w->win, 17, 0, close, p->w);
        mlx_loop(p->w->mlx);
    }
    return (0);
}
