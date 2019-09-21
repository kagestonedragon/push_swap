#include "libft.h"
#include "push_swap.h"

static int      validation_duplicates(t_push_swap *p)
{
	t_list		*temporary_1;
	t_list		*temporary_2;
	
	temporary_1 = p->stack_a;
	while (temporary_1)
	{
		temporary_2 = temporary_1;
		while ((temporary_2 = temporary_2->next))
		{
			if (temporary_1->value == temporary_2->value)
				push_swap_log(ERROR_DUPLICATE);
		}
		temporary_1 = temporary_1->next;
	}
    return (0);
}

int      		validation_integer_limits(char *str)
{
	if (ft_strlen(str) >= 10 && str[0] != '-')
		if (ft_strcmp("2147483647", str) < 0)
			push_swap_log(ERROR_BIG);
	if (ft_strlen(str) >= 11 && str[0] == '-')
		if (ft_strcmp("-2147483648", str) < 0)
			push_swap_log(ERROR_BIG);
    return (0);
}

int      		validation_correct_input(char *str)
{
	int 		i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			push_swap_log(ERROR_INPUT);
	}
    return (0);
}

int             validation(t_push_swap *p)
{
    if (!p->size)
    	push_swap_log(ERROR_EMPTY);
    validation_duplicates(p);
    return (0);
}
