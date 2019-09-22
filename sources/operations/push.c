/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:39:20 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:39:59 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_b(t_push_swap *p)
{
	t_list	*temporary;

	if (!p->stack_a)
		return (0);
	temporary = p->stack_a->next;
	p->stack_a->next = p->stack_b;
	p->stack_b = p->stack_a;
	p->stack_a = temporary;
	p->size_a--;
	p->size_b++;
	return (0);
}

int			push_a(t_push_swap *p)
{
	t_list	*temporary;

	if (!p->stack_b)
		return (0);
	temporary = p->stack_b->next;
	p->stack_b->next = p->stack_a;
	p->stack_a = p->stack_b;
	p->stack_b = temporary;
	p->size_b--;
	p->size_a++;
	return (0);
}
