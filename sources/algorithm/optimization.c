/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:27:22 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 18:06:37 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int		get_solution(t_list *o)
{
	int			solution;

	if (o->next == NULL)
		return (0);
	solution = 0;
	if ((o->value == OP_SWAP_A && o->next->value == OP_SWAP_B) ||
			(o->value == OP_SWAP_B && o->next->value == OP_SWAP_A))
		solution = 1;
	if ((o->value == OP_ROTATE_A && o->next->value == OP_ROTATE_B) ||
			(o->value == OP_ROTATE_B && o->next->value == OP_ROTATE_A))
		solution = 2;
	if ((o->value == OP_R_ROTATE_A && o->next->value == OP_R_ROTATE_B) ||
			(o->value == OP_R_ROTATE_B && o->next->value == OP_R_ROTATE_A))
		solution = 3;
	if ((o->value == OP_PUSH_A && o->next->value == OP_PUSH_B) ||
			(o->value == OP_PUSH_B && o->next->value == OP_PUSH_A))
		solution = 4;
	if ((o->value == OP_ROTATE_A && o->next->value == OP_R_ROTATE_A) ||
			(o->value == OP_R_ROTATE_A && o->next->value == OP_ROTATE_A))
		solution = 4;
	if ((o->value == OP_ROTATE_B && o->next->value == OP_R_ROTATE_B) ||
			(o->value == OP_R_ROTATE_B && o->next->value == OP_ROTATE_B))
		solution = 4;
	return (solution);
}

static t_list	*optimize_by_solution(t_list *t1, t_list *t2, int solution)
{
	if (solution == 1)
		t1->value = OP_SWAP;
	else if (solution == 2)
		t1->value = OP_ROTATE;
	else if (solution == 3)
		t1->value = OP_R_ROTATE;
	else if (solution == 4)
	{
		t2->next = t1->next->next;
		free(t1->next);
		free(t1);
		t1 = t2;
	}
	if (solution != 4)
	{
		t2 = t1->next;
		t1->next = t1->next->next;
		free(t2);
	}
	return (t1);
}

int				optimization(t_push_swap *p)
{
	t_list		*temporary;
	t_list		*temporary_1;
	int			end;
	int			solution;

	end = 1;
	while (end)
	{
		end = 0;
		temporary = p->operations;
		temporary_1 = temporary;
		while (temporary)
		{
			if ((solution = get_solution(temporary)))
			{
				end = 1;
				temporary = optimize_by_solution(temporary,
						temporary_1, solution);
			}
			temporary_1 = temporary;
			temporary = temporary->next;
		}
	}
	return (0);
}
