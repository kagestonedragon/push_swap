#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int      *get_sorted_array(int *array, int size)
{
    int         i;
    int         j;
    int         temporary;

    i = -1;
    while (++i < size)
    {
        j = i;
        while (++j < size)
        {
            if (array[i] > array[j])
            {
                temporary = array[i];
                array[i] = array[j];
                array[j] = temporary;
            }
        }
    } 
    return (array);
}

int             *get_array(t_push_swap *p)
{
    int         i;
    int         *result;
    t_list      *list;

    if (!(result = (int *)malloc(sizeof(int) * p->size)))
        write(1, "Error\n", 6);
    list = p->stack_a;
    i = -1;
    while (++i < p->size)
    {
        result[i] = list->value;
        list = list->next;
    }
    return (result);
}

static int      get_keep_info(t_push_swap *p)
{
    int         i;
    t_list      *list;

    i = 0;
    list = p->stack_a;
    while (list)
    {
        if (list->index == i)
        {
            list->keep = true;
            i += 1;
        }
        else
            list->keep = false;
        list = list->next;
    }
    return (0);
}

int             *get_indexes(t_push_swap *p)
{
    int         i;
    int         *array;
    t_list      *list;

    array = get_sorted_array(get_array(p), p->size);
    list = p->stack_a;
    while (list)
    {
        i = -1;
        while (++i < p->size)
        {
            if (array[i] == list->value)
                list->index = i;
        }
        list = list->next;
    }
    get_keep_info(p);
    free(array);
    return (0);
}
