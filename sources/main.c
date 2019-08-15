/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:32:40 by emedea            #+#    #+#             */
/*   Updated: 2019/08/15 16:41:54 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

int			main(int argc, char **argv)
{
	printf("n = %d, d = %d\n", validation_number(argv), validation_duplicate(argv));
	return (0);
}
