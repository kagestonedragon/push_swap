#include "../includes/push_swap.h"
#include <stdio.h>

static int	empty(t_list *list)
{
	if (!list)
		return (1);
	return (0);
}

void		swap(t_list *list)
{
	int		temporary;

	temporary = list->data;
	list->data = list->next->data;
	list->next->data = temporary;
}

void		rotate(t_list *list)
{
	while (list->next)
	{
		swap(list);
		list = list->next;
	}
}

void		push(t_list *input, t_list *output)
{

}
