#include "../../includes/push_swap.h"
#include "../../includes/mlx.h"
#include <stdlib.h>

t_window        *create_window(void)
{
    t_window    *w;

    w = (t_window *)malloc(sizeof(t_window));
    w->mlx = mlx_init();
    w->win = mlx_new_window(w->mlx, W_WIDTH, W_HEIGHT, "push_swap visualization");
    w->image.image = mlx_new_image(w->mlx, W_WIDTH, W_HEIGHT);
    w->image.data = mlx_get_data_addr(w->image.image, &w->image.bpp, &w->image.size_line, &w->image.endian);
    w->operation = 0;
    w->size = 0;
    return (w);
}
