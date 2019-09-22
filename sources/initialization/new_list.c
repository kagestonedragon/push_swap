/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:37:55 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:38:39 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list				*new_element(t_list *list, int value)
{
	if (!(list->next = (t_list *)malloc(sizeof(t_list))))
		push_swap_log(ERROR_MALLOC);
	list->next->value = value;
	list->next->next = NULL;
	return (list->next);
}

t_list				*create_list(int value)
{
	t_list			*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		push_swap_log(ERROR_MALLOC);
	list->value = value;
	list->next = NULL;
	return (list);
}

t_list				*new_list(t_push_swap *p)
{
	t_list			*list;
	t_list			*temporary_list;
	t_element		*temporary;

	if (!p->elem)
		return (NULL);
	temporary = p->elem;
	list = create_list(ft_atoi(temporary->value));
	p->size += 1;
	temporary_list = list;
	while ((temporary = temporary->next))
	{
		p->size += 1;
		list->next = new_element(list, ft_atoi(temporary->value));
		list = list->next;
	}
	return (temporary_list);
}
