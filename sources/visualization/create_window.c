/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:46:29 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 17:34:53 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlx.h"
#include <stdlib.h>

t_window		*create_window(void)
{
	t_window	*w;

	w = (t_window *)malloc(sizeof(t_window));
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, W_WIDTH, W_HEIGHT,
			"push_swap visualization");
	w->image.image = mlx_new_image(w->mlx, W_WIDTH, W_HEIGHT);
	w->image.data = mlx_get_data_addr(w->image.image, &w->image.bpp,
			&w->image.size_line, &w->image.endian);
	w->operation = 0;
	w->size = 0;
	mlx_hook(w->win, 17, 0, close_window, (void *)0);
	return (w);
}
