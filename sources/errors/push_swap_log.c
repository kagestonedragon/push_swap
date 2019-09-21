#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int         push_swap_log(int error)
{
    if (error == ERROR_DUPLICATE || error == ERROR_BIG)
        write(1, "Error\n", 6);
    else if (error == ERROR_INPUT)
        write(1, "Error\n", 6);
    else if (error == ERROR_MALLOC)
        write(1, "Not enough memory\n", 18);
    else if (error == ERROR_EMPTY)
        write(1, "\n", 1);
    exit(0);
    return (0);
}
