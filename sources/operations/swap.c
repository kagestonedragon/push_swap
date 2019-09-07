/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:54 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 17:47:10 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         is_empty_stack_a(t_push_swap *p)
{
    if (!p->stack_a || !p->stack_a->next)
        return (1);
    return (0);
}

int         is_empty_stack_b(t_push_swap *p)
{
    if (!p->stack_b || !p->stack_b->next)
        return (1);
    return (0);
}

int			swap_a(t_push_swap *p)
{
	t_list	*temporary;

    if (is_empty_stack_a(p))
        return (0);
    temporary = p->stack_a->next;
	p->stack_a->next = p->stack_a->next->next;
    temporary->next = p->stack_a;
    p->stack_a = temporary;
    return (0);
}

int			swap_b(t_push_swap *p)
{
	t_list	*temporary;

    if (is_empty_stack_b(p))
        return (0);
    temporary = p->stack_b->next;
	p->stack_b->next = p->stack_b->next->next;
    temporary->next = p->stack_b;
    p->stack_b = temporary;
    return (0);
}

int         swap(t_push_swap *p)
{
    swap_a(p);
    swap_b(p);
    return (0);
}
