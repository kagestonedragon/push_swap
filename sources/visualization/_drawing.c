#include "../../includes/push_swap.h"
#include "../../includes/mlx.h"
#include "../../includes/libft.h"
#include <stdlib.h>

int             pixel_put(t_window *w, int x, int y, int color)
{
    int         i;

    if (x < W_WIDTH && y < W_HEIGHT)
    {
        i = (x * w->image.bpp / 8) + (y * w->image.size_line);
        w->image.data[i] = color;
        w->image.data[++i] = color >> 8;
        w->image.data[++i] = color >> 16;
    }
    return (0);
}


static int      draw_borders(t_push_swap *p)
{
    int         x;
    int         y;

    x = 45;
    y = -1;
    while (++y < W_HEIGHT)
        pixel_put(p->w, x, y, LINE);
    x = 355;
    y = -1;
    while (++y < W_HEIGHT)
        pixel_put(p->w, x, y, LINE);
    x = 445;
    y = -1;
    while (++y < W_HEIGHT)
        pixel_put(p->w, x, y, LINE);
    x = 755;
    y = -1;
    while (++y < W_HEIGHT)
        pixel_put(p->w, x, y, LINE);
    return (0);

}

static int      get_operation_mlx(t_push_swap *p)
{
    if (p->w->operation == OP_PUSH_A)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "pa");
    else if (p->w->operation == OP_PUSH_B)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "pb");
    else if (p->w->operation == OP_R_ROTATE_A)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "rra");
    else if (p->w->operation == OP_R_ROTATE_B)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "rrb");
    else if (p->w->operation == OP_R_ROTATE)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "rrr");
    else if (p->w->operation == OP_ROTATE_A)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "ra");
    else if (p->w->operation == OP_ROTATE_B)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "rb");
    else if (p->w->operation == OP_ROTATE)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "rr");
    else if (p->w->operation == OP_SWAP_A)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "sa");
    else if (p->w->operation == OP_SWAP_B)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "sb");
    else if (p->w->operation == OP_SWAP)
        mlx_string_put(p->w->mlx, p->w->win, 395, 40, GREEN, "ss");
    return (0);
}

static int      draw_information(t_push_swap *p)
{
    char        *counter;

    counter = ft_itoa(p->w->size);
    mlx_string_put(p->w->mlx, p->w->win, 50, 15, STACK, "Stack A");
    mlx_string_put(p->w->mlx, p->w->win, 450, 15, STACK, "Stack B");
    mlx_string_put(p->w->mlx, p->w->win, 395, 20, CYAN, counter);
    free(counter);
    p->w->size += 1;
    get_operation_mlx(p);
    return (0);
}

int             draw_stacks(t_push_swap *p)
{
    mlx_clear_window(p->w->mlx, p->w->win);
    draw_background(p);
    draw_borders(p);
    draw_stack_a(p);
    draw_stack_b(p);
    mlx_put_image_to_window(p->w->mlx, p->w->win, p->w->image.image, 0, 0);
    draw_information(p);
    mlx_do_sync(p->w->mlx);
    return (0);
}
