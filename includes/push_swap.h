/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:30:44 by emedea            #+#    #+#             */
/*   Updated: 2019/08/15 16:40:47 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_list{
	int		        data;
	struct s_list	*next;
}			        t_list;

int			        validation_number(char **argv);
int			        validation_duplicate(char **argv);

int                 push_swap_log(int e);
int                 print(t_list *list);
t_list              *create_stack(char **argv);
t_list              *flag_sa(t_list *list_a);
t_list              *flag_ra(t_list *list_a);

/*
 * Misc
*/
int                 ft_atoi(char *str);

#endif
