#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static t_element	*add_element(t_element *new, char *str)
{
	new = (t_element *)malloc(sizeof(t_element));
	new->value = str;
	new->next = NULL;
	return (new);
}

static t_element	*add_elements(char *elements, t_element *list, t_element **_list)
{
	int			j;
	char 		**split_elements;
	
	j = -1;
	split_elements = ft_strsplit(elements, ' ');
	while (split_elements[++j])
	{
		validation_integer_limits(split_elements[j]);
		validation_correct_input(split_elements[j]);
		if (list)
		{
			list->next = add_element(list->next, split_elements[j]);
			list = list->next;
			continue;
		}
		list = add_element(list, split_elements[j]);
		*_list = list;
	}
	free(split_elements);
	return (list);
}

t_element			*collect_elements(char **elements)
{
	int 			i;
	t_element		*list;
	t_element		*_list;
	
	i = -1;
	list = NULL;
	_list = NULL;
	while (elements[++i])
		list = add_elements(elements[i], list, &_list);
	return (_list);
}