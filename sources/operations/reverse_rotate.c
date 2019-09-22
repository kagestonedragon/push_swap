/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:40:06 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:40:07 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int			reverse_rotate_a(t_push_swap *p)
{
	t_list	*list;
	t_list	*temporary;

	if (!p->stack_a || !p->stack_a->next)
		return (0);
	list = p->stack_a;
	while (list->next->next)
		list = list->next;
	temporary = list->next;
	temporary->next = p->stack_a;
	list->next = NULL;
	p->stack_a = temporary;
	return (0);
}

int			reverse_rotate_b(t_push_swap *p)
{
	t_list	*list;
	t_list	*temporary;

	if (!p->stack_b || !p->stack_b->next)
		return (0);
	list = p->stack_b;
	while (list->next->next)
		list = list->next;
	temporary = list->next;
	temporary->next = p->stack_b;
	list->next = NULL;
	p->stack_b = temporary;
	return (0);
}

int			reverse_rotate(t_push_swap *p)
{
	reverse_rotate_a(p);
	reverse_rotate_b(p);
	return (0);
}
