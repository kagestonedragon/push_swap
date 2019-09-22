/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:36:46 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:37:05 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int		max(t_list *stack)
{
	t_list		*temporary_a;
	int			temporary;

	temporary_a = stack;
	temporary = 0;
	while (temporary_a)
	{
		if (temporary_a->value > temporary)
			temporary = temporary_a->value;
		temporary_a = temporary_a->next;
	}
	return (temporary);
}

static t_list	*get_flags(char **argv)
{
	t_list		*flags;

	flags = NULL;
	if (argv[0][0] == '-' && argv[0][1] == 'v')
		flags = create_list(FLAG_VISUALIZATION);
	else if (argv[0][0] == '-' && argv[0][1] == 'n')
		flags = create_list(FLAG_TOTAL);
	return (flags);
}

t_push_swap		*initialization(char **elements)
{
	t_push_swap	*p;

	p = (t_push_swap *)malloc(sizeof(t_push_swap));
	p->flags = get_flags(elements);
	p->size = 0;
	p->elem = collect_elements(p->flags ? &elements[1] : &elements[0]);
	p->stack_a = new_list(p);
	p->max_value = max(p->stack_a);
	p->w = NULL;
	p->stack_b = NULL;
	p->operations = NULL;
	p->size_a = p->size;
	p->size_b = 0;
	return (p);
}
