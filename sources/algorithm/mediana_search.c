#include "push_swap.h"

static t_list   *create_temporary_list(t_list *stack)
{
    t_list      *temporary;
    t_list      *list;
    t_list      *_list;

    temporary = stack;
    list = create_list(temporary->value);
    _list = list;
    while ((temporary = temporary->next))
    {
        list->next = new_element(list, temporary->value);
        list = list->next;
    }
    return (_list);
}

static int      *sorting_asc(t_list *stack)
{
    t_list      *temporary_1;
    t_list      *temporary_2;
    int         temporary;

    temporary_1 = stack;
    while (temporary_1->next)
    {
        temporary_2 = temporary_1->next;
        while (temporary_2)
        {
            if (temporary_1->value > temporary_2->value)
            {
                temporary = temporary_1->value;
                temporary_1->value = temporary_2->value;
                temporary_2->value = temporary;
            }
            temporary_2 = temporary_2->next;
        }
        temporary_1 = temporary_1->next;
    }
    return (0);
}

static int      *sorting_desc(t_list *stack)
{
    t_list      *temporary_1;
    t_list      *temporary_2;
    int         temporary;

    temporary_1 = stack;
    while (temporary_1->next)
    {
        temporary_2 = temporary_1->next;
        while (temporary_2)
        {
            if (temporary_1->value < temporary_2->value)
            {
                temporary = temporary_1->value;
                temporary_1->value = temporary_2->value;
                temporary_2->value = temporary;
            }
            temporary_2 = temporary_2->next;
        }
        temporary_1 = temporary_1->next;
    }
    return (0);
}

int             mediana_stack_a(t_push_swap *p, int size)
{
    int         i;
    t_list      *temporary;
    t_list      *_list;
    int         result;
    
    temporary = create_temporary_list(p->stack_a);
    _list = temporary;
    sorting_asc(temporary);
    i = -1;
    while (++i < size / 2)
        temporary = temporary->next;
    result = temporary->value;
    list_free(_list);
    return (result);
}

int             mediana_stack_b(t_push_swap *p, int size)
{
    int         i;
    t_list      *temporary;
    t_list      *_list;
    int         result;
    
    temporary = create_temporary_list(p->stack_b);
    _list = temporary;
    sorting_desc(temporary);
    i = -1;
    while (++i < size / 2)
        temporary = temporary->next;
    result = temporary->value;
    list_free(_list);
    return (result);
}
