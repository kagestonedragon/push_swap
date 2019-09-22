/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:33:53 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:34:14 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int				list_free(t_list *list)
{
	t_list		*temporary;

	while (list)
	{
		temporary = list;
		list = list->next;
		free(temporary);
	}
	return (0);
}

int				elements_free(t_element *elements)
{
	t_element	*temporary;

	while (elements)
	{
		temporary = elements;
		elements = elements->next;
		free(temporary->value);
		free(temporary);
	}
	return (0);
}

int				push_swap_free(t_push_swap *p)
{
	list_free(p->flags);
	list_free(p->stack_a);
	list_free(p->operations);
	elements_free(p->elem);
	free(p);
	return (0);
}
