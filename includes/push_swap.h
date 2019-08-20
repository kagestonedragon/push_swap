/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:30:44 by emedea            #+#    #+#             */
/*   Updated: 2019/08/20 18:40:08 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_list{
	int		        data;
	struct s_list	*next;
}			        t_list;

/*
 * Operations
 */
void				swap(t_list *list);
void				rotate(t_list *list);

/*
 * Validation
 */
int			        validation_number(char **argv);
int			        validation_duplicate(char **argv);

/*
 * List
 */
t_list				*new_list(char **argv);
void				delete(t_list *list);
void				delete_all(t_list *list);

/*
 * Errors
 */
int              	push_swap_log(int e);
int                 print(t_list *list);

/*
 * Misc
*/
int                 ft_atoi(char *str);

#endif
