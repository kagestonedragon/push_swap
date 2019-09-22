/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:21:36 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:21:39 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algorithm(t_push_swap *p)
{
	if (p->size > 3)
		sorting_a(p, p->size_a);
	else
		primitive_sorting(p);
	return (0);
}
