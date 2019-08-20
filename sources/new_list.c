#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <stdlib.h>

static t_list   *new_element(t_list *list, int data)
{
    if (!(list->next = (t_list *)malloc(sizeof(t_list))))
        push_swap_log(ERROR_MALLOC);
    list->next->data = data;
    list->next->next = NULL;
    return (list->next);
}

static t_list   *create_list(int data)
{
    t_list      *list;

    if (!(list = (t_list *)malloc(sizeof(t_list))))
        push_swap_log(ERROR_MALLOC);
    list->data = data;
    list->next = NULL;
    return (list);
}

t_list          *new_list(char **argv)
{
    int         i;
    t_list      *list;
    t_list      *_list;

    list = create_stack(ft_atoi(argv[1]));
    _list = list;
    i = 1;
    while (argv[++i])
    {
        list->next = new_element(list, ft_atoi(argv[i]));
        list = list->next;
    }
    return (_list);
}
