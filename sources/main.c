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
    t_list  *list;

    list = create_stack(argv);
    list = flag_ra(list);
    print(list);
	return (0);
}
