/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:04:35 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:35:46 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_push_swap		*initialization(int size, char **elements)
{
	t_push_swap	*p;

	(void)size;
	p = (t_push_swap *)malloc(sizeof(t_push_swap));
	p->stack_a = new_list(elements);
    p->stack_b = NULL;
    p->size = size;
    get_indexes(p);
	return (p);
}
