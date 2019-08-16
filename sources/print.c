#include "../includes/push_swap.h"
#include <stdio.h>

int     print(t_list *list)
{
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
    return (0);
}
