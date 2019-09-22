/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:28:18 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:29:30 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_push_swap *p)
{
	t_list	*temporary;

	temporary = p->stack_a;
	if (!p->stack_a || !p->stack_a->next || p->stack_b)
		return (0);
	while (temporary->next)
	{
		if (temporary->value > temporary->next->value)
			return (0);
		temporary = temporary->next;
	}
	return (1);
}

int			get_last_element(t_push_swap *p)
{
	t_list	*temporary;

	temporary = p->stack_a;
	while (temporary->next)
		temporary = temporary->next;
	return (temporary->value);
}

int			primitive_sorting(t_push_swap *p)
{
	if (p->size_a == 1)
		return (0);
	while (!is_sorted(p) && p->size_a <= 3)
	{
		if (p->stack_a->value > p->stack_a->next->value)
		{
			if (p->size_a > 2 && p->stack_a->value < get_last_element(p))
				add_operation(p, OP_SWAP_A);
			else
				add_operation(p, OP_ROTATE_A);
		}
		else if (!is_sorted(p))
		{
			if (p->stack_a->value < p->stack_a->next->value)
			{
				if (p->size_a > 2 && p->stack_a->value > get_last_element(p))
					add_operation(p, OP_R_ROTATE_A);
				else
					add_operation(p, OP_ROTATE_A);
			}
		}
	}
	return (0);
}

int			primitive_sorting_a(t_push_swap *p)
{
	(p->size_a > 1 && p->stack_a->value > p->stack_a->next->value) ?
		add_operation(p, OP_SWAP_A) : 0;
	if (p->size_a > 2 && p->stack_a->next->value >
			p->stack_a->next->next->value)
	{
		add_operation(p, OP_ROTATE_A);
		add_operation(p, OP_SWAP_A);
		add_operation(p, OP_R_ROTATE_A);
	}
	(p->size_a > 1 && p->stack_a->value > p->stack_a->next->value) ?
		add_operation(p, OP_SWAP_A) : 0;
	return (0);
}

int			primitive_sorting_b(t_push_swap *p)
{
	(p->size_b > 1 && p->stack_b->value < p->stack_b->next->value) ?
		add_operation(p, OP_SWAP_B) : 0;
	if (p->size_b > 2 && p->stack_b->next->value <
			p->stack_b->next->next->value)
	{
		add_operation(p, OP_ROTATE_B);
		add_operation(p, OP_SWAP_B);
		add_operation(p, OP_R_ROTATE_B);
	}
	(p->size_b > 1 && p->stack_b->value < p->stack_b->next->value) ?
		add_operation(p, OP_SWAP_B) : 0;
	return (0);
}
