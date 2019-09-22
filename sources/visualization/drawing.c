/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:02:07 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 18:20:26 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int		get_width(int max, int current)
{
	float		percent;

	percent = (float)current / (float)max;
	return (ABS((int)(LINE_WIDTH * percent)));
}

static int		draw_box(t_push_swap *p, int *current, int x, int y)
{
	int			height;
	int			width;
	int			temporary_x;
	int			line_width;

	height = -1;
	temporary_x = x;
	line_width = get_width(p->max_value, current[0]);
	while (++height <= LINE_HEIGHT)
	{
		width = -1;
		x = temporary_x;
		while (++width <= line_width)
		{
			pixel_put(p->w, x, y, current[1]);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int				draw_stack_a(t_push_swap *p)
{
	int			current[2];
	int			x;
	int			y;
	t_list		*temporary;

	x = 50;
	y = 50;
	temporary = p->stack_a;
	while (temporary)
	{
		current[0] = temporary->value;
		current[1] = WHITE;
		draw_box(p, &current[0], x, y);
		y += 5;
		temporary = temporary->next;
	}
	return (0);
}

int				draw_stack_b(t_push_swap *p)
{
	int			current[2];
	int			x;
	int			y;
	t_list		*temporary;

	x = 450;
	y = 50;
	temporary = p->stack_b;
	while (temporary)
	{
		current[0] = temporary->value;
		current[1] = YELLOW;
		draw_box(p, &current[0], x, y);
		y += 5;
		temporary = temporary->next;
	}
	return (0);
}

int				draw_background(t_push_swap *p)
{
	int			*image;
	int			i;

	ft_bzero(p->w->image.data, W_WIDTH * W_HEIGHT * (p->w->image.bpp / 8));
	image = (int *)(p->w->image.data);
	i = -1;
	while (++i < W_WIDTH * W_HEIGHT)
		image[i] = GREY;
	return (0);
}
