cmake_minimum_required(VERSION 3.14)
project(clion_push_swap C)

set(CMAKE_EXE_LINKER_FLAGS  "-L /Users/emedea/clion_push_swap/libraries -lft -L /Users/emedea/clion_push_swap/libraries -lmlx -framework OpenGL -framework AppKIt")
set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(clion_push_swap
        includes/get_next_line.h
        includes/libft.h
        includes/mlx.h
        includes/push_swap.h
        includes/structures.h
        includes/visualization.h
        sources/algorithm/add_operation.c
        sources/algorithm/algorithm.c
        sources/algorithm/mediana_search.c
        sources/algorithm/optimization.c
        sources/algorithm/primitive_sorting.c
        sources/algorithm/print_operations.c
        sources/algorithm/sorting_stack_a.c
        sources/algorithm/sorting_stack_b.c
        sources/errors/push_swap_log.c
        sources/free/push_swap_free.c
        sources/initialization/initialization.c
        sources/initialization/new_list.c
        sources/initialization/get_elements.c
        sources/operations/push.c
        sources/operations/reverse_rotate.c
        sources/operations/rotate.c
        sources/operations/swap.c
        sources/validation/after_validation.c
        sources/validation/validation.c
        sources/visualization/_drawing.c
        sources/visualization/create_window.c
        sources/visualization/drawing.c
        sources/visualization/utils.c
        sources/main.c sources/initialization/get_elements.c)
