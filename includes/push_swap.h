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
	int				n;
	struct s_list	*next;
}					t_list;

int					validation_number(char **argv);
int					validation_duplicate(char **argv);

#endif
