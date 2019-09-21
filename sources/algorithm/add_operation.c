#include "push_swap.h"

int			do_operation(t_push_swap *p, int operation)
{
	if (operation == OP_PUSH_A)
		push_a(p);
	else if (operation == OP_PUSH_B)
		push_b(p);
	else if (operation == OP_R_ROTATE_A)
		reverse_rotate_a(p);
	else if (operation == OP_R_ROTATE_B)
		reverse_rotate_b(p);
	else if (operation == OP_R_ROTATE)
		reverse_rotate(p);
	else if (operation == OP_ROTATE_A)
		rotate_a(p);
	else if (operation == OP_ROTATE_B)
		rotate_b(p);
	else if (operation == OP_ROTATE)
		rotate(p);
	else if (operation == OP_SWAP_A)
		swap_a(p);
	else if (operation == OP_SWAP_B)
		swap_b(p);
	else if (operation == OP_SWAP)
		swap(p);
	return (0);
}

int         add_operation(t_push_swap *p, int operation)
{
	t_list  *temporary;

	if (p->operations)
	{
		temporary = p->operations;
		while (temporary->next)
			temporary = temporary->next;
		temporary->next = new_element(temporary, operation);
	}
	else
		p->operations = create_list(operation);
	do_operation(p, operation);
	return (0);
}
