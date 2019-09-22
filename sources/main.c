/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:50:04 by emedea            #+#    #+#             */
/*   Updated: 2019/09/22 16:50:14 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_push_swap	*p;

	if (argc == 1)
		return (0);
	p = initialization(&argv[1]);
	validation(p);
	after_validation(p);
	push_swap_free(p);
	return (0);
}
