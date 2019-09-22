/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:35:05 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:52:52 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static t_element	*add_element(t_element *new, char *str)
{
	new = (t_element *)malloc(sizeof(t_element));
	new->value = str;
	new->next = NULL;
	return (new);
}

static t_element	*add_elements(char *elements,
		t_element *list, t_element **temporary_list)
{
	int				j;
	char			**split_elements;

	j = -1;
	split_elements = ft_strsplit(elements, ' ');
	while (split_elements[++j])
	{
		validation_integer_limits(split_elements[j]);
		validation_correct_input(split_elements[j]);
		if (list)
		{
			list->next = add_element(list->next, split_elements[j]);
			list = list->next;
			continue;
		}
		list = add_element(list, split_elements[j]);
		*temporary_list = list;
	}
	free(split_elements);
	return (list);
}

t_element			*collect_elements(char **elements)
{
	int				i;
	t_element		*list;
	t_element		*temporary_list;

	i = -1;
	list = NULL;
	temporary_list = NULL;
	while (elements[++i])
		list = add_elements(elements[i], list, &temporary_list);
	return (temporary_list);
}
