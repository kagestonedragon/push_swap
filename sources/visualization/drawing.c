#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

static int      get_width(int max, int current)
{
    float       percent;

    percent = (float)current / (float)max;
    return (ABS((int)(LINE_WIDTH * percent)));
}

static int      draw_box(t_push_swap *p, int current, int x, int y, int color)
{
    int         height;
    int         width;
    int         temporary_x;
    int         line_width;

    height = -1;
    temporary_x = x;
    line_width = get_width(p->max_value, current);
    while (++height <= LINE_HEIGHT)
    {
        width = -1;
        x = temporary_x;
        while (++width <= line_width)
        {
            pixel_put(p->w, x, y, color);
            x += 1;
        }
        y += 1;
    }
    return (0);
}

int             draw_stack_a(t_push_swap *p)
{
    int         x;
    int         y;
    t_list      *temporary;

    x = 50;
    y = 50;
    temporary = p->stack_a;
    while (temporary)
    {
        draw_box(p, temporary->value, x, y, WHITE);
        y += 5;
        temporary = temporary->next;
    }
    return (0);
}

int             draw_stack_b(t_push_swap *p)
{
    int         x;
    int         y;
    t_list      *temporary;

    x = 450;
    y = 50;
    temporary = p->stack_b;
    while (temporary)
    {
        draw_box(p, temporary->value, x, y, YELLOW);
        y += 5;
        temporary = temporary->next;
    }
    return (0);
}

int             draw_background(t_push_swap *p)
{
    int         *image;
    int         i;


    ft_bzero(p->w->image.data, W_WIDTH * W_HEIGHT * (p->w->image.bpp / 8));
    image = (int *)(p->w->image.data);
    i = -1;
    while (++i < W_WIDTH * W_HEIGHT)
        image[i] = GREY;
    return (0);
}

