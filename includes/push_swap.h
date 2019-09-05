/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:25:21 by emedea            #+#    #+#             */
/*   Updated: 2019/09/05 16:35:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum{
	false,
	true
}		t_bool;

typedef struct		s_list{
	int				value;
	int				index;
	t_bool			keep;
	struct s_list	*next;
}					t_list;

typedef struct		s_push_swap{
	t_list			*stack_a;
	t_list			*stack_b;
}					t_push_swap;

/* VALIDATION */
int					validation(int size, char **elements);

/* INITIALIZATION */
t_push_swap			*initialization(int size, char **elements);
t_list				*new_list(char **elements);

#endif
