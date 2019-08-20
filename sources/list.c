/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:15:13 by emedea            #+#    #+#             */
/*   Updated: 2019/08/20 18:39:02 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	delete(t_list *list)
{
	free(list);
	list = NULL;
}

void	delete_all(t_list *list)
{
	while (list)
	{
		delete(list);
		list = list->next;
	}
}
