/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:04:35 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:35:46 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
/*
static int		*sort_array(int *array, int size)
{
	int			temporary;
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temporary = array[i];
				array[i] = array[j];
				array[j] = temporary;
			}
		}
	}
	return (array);
}

static int		*get_array(int size, t_push_swap *p)
{
	t_list		*list;
	int			*result;
	int			i;

	if (!(result = (int *)malloc(sizeof(int) * size)))
		write(1, "Error\n", 6);
	list = p->stack_a;
	i = -1;
	while (list)
	{
		result[++i] = list.value;
		list = list->next;
	}
	return (result);
}
*/
t_push_swap		*initialization(int size, char **elements)
{
	t_push_swap	*p;

	(void)size;
	p = (t_push_swap *)malloc(sizeof(t_push_swap));
	p->stack_a = new_list(elements);

	return (p);
}
