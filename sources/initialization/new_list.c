/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:14:03 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:36:16 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static t_list	*new_element(t_list *list, int value)
{
	if (!(list->next = (t_list *)malloc(sizeof(t_list))))
		write(1, "Error\n", 1);
	list->next->value = value;
	list->next->next = NULL;
	return (list->next);
}

static t_list	*create_list(int value)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		write(1, "Error\n", 6);
	list->value = value;
	list->next = NULL;
	return (list);
}

t_list			*new_list(char **elements)
{
	int			i;
	t_list		*list;
	t_list		*_list;

	list = create_list(atoi(elements[0]));
	_list = list;
	i = 0;
	while (elements[++i])
	{
		list->next = new_element(list, atoi(elements[i]));
		list = list->next;
	}
	return (_list);
}
