#include "../includes/errors.h"
#include <unistd.h>
#include <stdio.h>

int	push_swap_log(int e)
{
    if (e == ERROR_DIGITS)
        printf("Error: your input data doesn't correct.");
    else if (e == ERROR_DUPLICATE)
        printf("Error: your input data doesn't correct.");
    else if (e == ERROR_MALLOC)
        printf("Error: malloc() return NULL");
    return (0);
}
