/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:48:35 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:37:15 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int		validation_duplicates(int size, char **elements)
{
	int			i;
	int			j;
	int			temporary;

	i = -1;
	while (++i < size)
	{
		temporary = atoi(elements[i]);
		j = i;
		while (++j < size)
			if (temporary == atoi(elements[j]))
				return (1);
	}
	return (0);
}

static int		validation_correct_input(int size, char **elements)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (elements[i][++j])
			if (!(elements[i][j] >= '0' && elements[i][j] <= '9'))
				return (1);
	}
	return (0);
}
/*
static int		validation_overflow(int size, char **elements)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		if (elements[0] != '-' &&
	}
}*/

int				validation(int size, char **elements)
{
	if (validation_duplicates(size, elements))
		write(1, "Error\n", 6);
	else if (validation_correct_input(size, elements))
		write(1, "Error\n", 6);
	return (0);
}
