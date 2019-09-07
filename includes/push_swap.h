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
    int             size;
    int             keeps_a;
}					t_push_swap;

int                 test_print(t_push_swap *p);

/* VALIDATION */
int					validation(int size, char **elements);

/* INITIALIZATION */
t_push_swap			*initialization(int size, char **elements);
t_list				*new_list(char **elements);
int                 *get_array(t_push_swap *p);
int                 *get_indexes(t_push_swap *p);

/* OPERATIONS */
int                 is_empty_stack_a(t_push_swap *p);
int                 is_empty_stack_b(t_push_swap *p);
int                 swap_a(t_push_swap *p);
int                 swap_b(t_push_swap *p);
int                 swap(t_push_swap *p);
int                 push_a(t_push_swap *p);
int                 push_b(t_push_swap *p);
int                 rotate_a(t_push_swap *p);
int                 rotate_b(t_push_swap *p);
int                 rotate(t_push_swap *p);
int                 reverse_rotate_a(t_push_swap *p);
int                 reverse_rotate_b(t_push_swap *p);
int                 reverse_rotate(t_push_swap *p);

#endif
