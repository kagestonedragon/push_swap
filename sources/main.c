/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:15:07 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:33:10 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int                 test_print(t_push_swap *p)
{
    t_list          *list;
    t_list          *list_2;

    list = p->stack_a;
    printf("STACK A:\n");
    while (list)
    {
        printf("value = %d, index = %d, keep = %d\n", list->value, list->index, list->keep);
        list = list->next;
    }
    printf("STACK B:\n");
    list_2 = p->stack_b;
    while (list_2)
    {
        printf("value = %d, index = %d, keep = %d\n", list_2->value, list_2->index, list_2->keep);
        list_2 = list_2->next;
    }
    printf("\n");
    return (0);
}
/*
int					main(int size, char **elements)
{
	t_push_swap		*p;

	p = initialization(size - 1, &elements[1]);
    test_print(p);
    reverse_rotate_a(p);
    test_print(p);
	return (0);
}*/
