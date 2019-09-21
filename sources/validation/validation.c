#include "../includes/libft.h"
#include "../includes/push_swap.h"

static int      validation_duplicates(int size, char **elements)
{
    int         i;
    int         j;
    int         temporary;

    i = -1;
    while (++i < size)
    {
        temporary = ft_atoi(elements[i]);
        j = i;
        while (++j < size)
            if (temporary == ft_atoi(elements[j]))
                push_swap_log(ERROR_DUPLICATE);
    }
    return (0);
}

static int      validation_integer_limits(int size, char **elements)
{
    int         i;

    i = 0;
    while (++i < size)
    {
        if (ft_strlen(elements[i]) >= 10 && elements[i][0] != '-')
            if (ft_strcmp("2147483647", elements[i]) < 0)
                push_swap_log(ERROR_BIG);
        if (ft_strlen(elements[i]) >= 11 && elements[i][0] == '-')
            if (ft_strcmp("-2147483648", elements[i]) < 0)
                push_swap_log(ERROR_BIG);
    }
    return (0);
}

static int      validation_correct_input(int size, char **elements)
{
    int         i;
    int         j;

    i = -1;
    while (++i < size)
    {
        j = -1;
        while (elements[i][++j])
        {
            if (elements[i][j] == '-' || elements[i][j] == '+')
                j++;
            if (!(elements[i][j] >= '0' && elements[i][j] <= '9'))
                push_swap_log(ERROR_INPUT);    
        }
    }
    return (0);
}

int             validation(int size, char **elements)
{
    if (!size)
        push_swap_log(ERROR_EMPTY);
    validation_integer_limits(size, elements);
    validation_duplicates(size, elements);
    validation_correct_input(size, elements);
    return (0);
}
