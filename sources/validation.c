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
				return (400);
	}
	return (0);
}

int		validation_duplicate(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{

		}
	}
	return (0);
}
