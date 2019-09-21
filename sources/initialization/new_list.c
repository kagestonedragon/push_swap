#include "../../includes/push_swap.h"
#include "../../includes/libft.h"
#include <stdlib.h>

t_list              *new_element(t_list *list, int value)
{
    if (!(list->next = (t_list *)malloc(sizeof(t_list))))
        push_swap_log(ERROR_MALLOC);
    list->next->value = value;
    list->next->next = NULL;
    return (list->next);
}

t_list              *create_list(int value)
{
    t_list          *list;

    if (!(list = (t_list *)malloc(sizeof(t_list))))
        push_swap_log(ERROR_MALLOC);
    list->value = value;
    list->next = NULL;
    return (list);
}

t_list              *new_list(char **elements)
{
    int             i;
    t_list          *list;
    t_list          *_list;

    if (!elements[0])
        return (NULL);
    list = create_list(atoi(elements[0]));
    _list = list;
    i = 0;
    while (elements[++i])
    {
        list->next = new_element(list, ft_atoi(elements[i]));
        list = list->next;
    }
    return (_list);
}
