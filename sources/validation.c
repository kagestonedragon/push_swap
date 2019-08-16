/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:34:23 by emedea            #+#    #+#             */
/*   Updated: 2019/08/15 16:51:07 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

int		validation_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (ERROR_DIGITS);
	}
	return (0);
}

int		validation_duplicate(char **argv)
{
	int	i;
	int	j;
    int first_number;
    int second_number;

	i = 0;
	while (argv[++i])
	{
        first_number = ft_atoi(argv[i]);
        j = i;
		while (argv[++j])
		{
            second_number = ft_atoi(argv[j]);
            if (first_number == second_number)
                return (ERROR_DUPLICATE);
		}
	}
	return (0);
}
