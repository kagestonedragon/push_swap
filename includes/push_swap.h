#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_DUPLICATE        100
# define ERROR_INPUT            110
# define ERROR_MALLOC           120
# define ERROR_EMPTY            130
# define ERROR_BIG              140

# define OP_PUSH_A              250
# define OP_PUSH_B              251
# define OP_R_ROTATE_A          252
# define OP_R_ROTATE_B          253
# define OP_R_ROTATE            254
# define OP_ROTATE_A            255
# define OP_ROTATE_B            256
# define OP_ROTATE              257
# define OP_SWAP_A              258
# define OP_SWAP_B              259
# define OP_SWAP                260

# define FLAG_VISUALIZATION     400

# define ABS(x) ((x) > 0 ? (x) : (-x))
# include "structures.h"

# include "visualization.h"


/*
** VISUALIZATION
*/
t_window                        *create_window(void);
int                             visualization_loop(t_push_swap *p);
int                             draw_stack_a(t_push_swap *p);
int                             draw_stack_b(t_push_swap *p);
int                             draw_background(t_push_swap *p);
int                             pixel_put(t_window *w, int x, int y, int color);
int                             draw_stacks(t_push_swap *p);

/*
** INITIAlIZAION
*/
t_push_swap                     *initialization(int size, char **elements);
t_list                          *new_list(char **elements);
t_list                          *create_list(int value);
t_list                          *new_element(t_list *list, int value);
int                             push_swap_free(t_push_swap *p);
int                             list_free(t_list *list);
int                             create_visual_stack_a(t_push_swap *p, char **elements);
int                             do_operation(t_push_swap *p, int operation);

/*
** ALGORIHTM
*/
int                             is_sorted(t_push_swap *p);
int                             optimization(t_push_swap *p);
int                             print_operations(t_push_swap *p);
int                             sorting_a(t_push_swap *p, int size);
int                             sorting_b(t_push_swap *p, int size);
int                             primitive_sorting(t_push_swap *p);
int                             primitive_sorting_a(t_push_swap *p);
int                             primitive_sorting_b(t_push_swap *p);
int                             algorithm(t_push_swap *p);
int                             mediana_stack_a(t_push_swap *p, int size);
int                             mediana_stack_b(t_push_swap *p, int size);
int                             add_operation(t_push_swap *p, int operation);

/*
** OPERATIONS
*/
int                             push_b(t_push_swap *p);
int                             push_a(t_push_swap *p);
int                             reverse_rotate_a(t_push_swap *p);
int                             reverse_rotate_b(t_push_swap *p);
int                             reverse_rotate(t_push_swap *p);
int                             rotate_a(t_push_swap *p);
int                             rotate_b(t_push_swap *p);
int                             rotate(t_push_swap *p);
int                             swap_a(t_push_swap *p);
int                             swap_b(t_push_swap *p);
int                             swap(t_push_swap *p);

/*
** VALIDATION
*/
int                             validation(int size, char **elements);
int                             after_validation(t_push_swap *p, int elements, int argc, char **argv);
t_list                          *get_flags(int argc, char **argv);

/*
** ERROR HANDLES
*/
int                             push_swap_log(int error);
#endif
