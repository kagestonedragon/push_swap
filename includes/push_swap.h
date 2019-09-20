#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_DUPLICATE        100
# define ERROR_INPUT            110
# define ERROR_MALLOC           120

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

typedef struct                  s_list{
    int                         value;
    struct s_list               *next;
}                               t_list;

typedef struct                  s_push_swap{
    t_list                      *stack_a;
    t_list                      *stack_b;
    t_list                      *operations;
    int                         size;
    int                         size_a;
    int                         size_b;
}                               t_push_swap;

int                             debug_a(t_push_swap *p);
int                             debug_b(t_push_swap *p);

/*
** INITIAlIZAION
*/
t_push_swap                     *initialization(int size, char **elements);
t_list                          *new_list(char **elements);
t_list                          *create_list(int value);
t_list                          *new_element(t_list *list, int value);

/*
** ALGORIHTM
*/
int                             optimization(t_push_swap *p, int f, int x);
int                             print_total(t_push_swap *p);
int                             print_operations(t_push_swap *p);
int                             primitive_sorting(t_push_swap *p);
int                             algorithm(t_push_swap *p);
int                             mediana_stack_a(t_push_swap *p, int size);
int                             mediana_stack_b(t_push_swap *p, int size);
int                             add_operation(t_push_swap *p, int operation);
int                             step_one(t_push_swap *p, int size, int i);
int                             step_two(t_push_swap *p, int size, int i);

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

/*
** ERROR HANDLES
*/
int                             push_swap_log(int error);
#endif
