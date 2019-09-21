#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct              	s_image{
    void                    	*image;
    char                    	*data;
    int                    		bpp;
    int                    		size_line;
    int                     	endian;
}                          		t_image;

typedef struct					s_window{
	void 						*mlx;
	void 						*win;
	t_image 					image;
	int 						operation;
	int 						size;
}								t_window;

typedef struct                  s_list{
    int                         value;
    struct s_list               *next;
}                               t_list;

typedef struct 					s_element{
	char						*value;
	struct s_element			*next;
}								t_element;

typedef struct                  s_push_swap{
    t_list                      *stack_a;
    t_list                      *stack_b;
    t_list                      *operations;
    t_list                      *flags;
    t_window                    *w;
    t_element					*elem;
    int                         max_value;
    int                         size;
    int                         size_a;
    int                         size_b;
}                               t_push_swap;

#endif 
