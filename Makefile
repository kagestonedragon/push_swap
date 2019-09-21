########################################################
#@@@-------------GENERATED BY AUTO_MAKE-------------@@@#
#@@                                                  @@#
#@    https://github.com/kagestonedragon/auto_make    @#
########################################################

NAME = push_swap

GCC = gcc

GCC_FLAGS = -Wall -Wextra -Werror

OBJ_PATH = objects/

INCLUDES_INCLUDE = includes/

SOURCES_PATH = sources/
SOURCES_ALGORITHM_PATH = sources/algorithm/
SOURCES_ERRORS_PATH = sources/errors/
SOURCES_FREE_PATH = sources/free/
SOURCES_INITIALIZATION_PATH = sources/initialization/
SOURCES_OPERATIONS_PATH = sources/operations/
SOURCES_VALIDATION_PATH = sources/validation/
SOURCES_VISUALIZATION_PATH = sources/visualization/

SOURCES_FILES = \
		main.c 
SOURCES_ALGORITHM_FILES = \
		add_operation.c \
		algorithm.c \
		mediana_search.c \
		optimization.c \
		primitive_sorting.c \
		print_operations.c \
		sorting_stack_a.c \
		sorting_stack_b.c 
SOURCES_ERRORS_FILES = \
		push_swap_log.c 
SOURCES_FREE_FILES = \
		push_swap_free.c 
SOURCES_INITIALIZATION_FILES = \
		get_elements.c \
		initialization.c \
		new_list.c 
SOURCES_OPERATIONS_FILES = \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c 
SOURCES_VALIDATION_FILES = \
		after_validation.c \
		validation.c 
SOURCES_VISUALIZATION_FILES = \
		_drawing.c \
		create_window.c \
		drawing.c \
		utils.c 

OBJ_CHECKER_CORE = $(addprefix $(OBJ_PATH), $(CHECKER_FILES:.c=.o)
OBJ_SOURCES_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_FILES:.c=.o))
OBJ_SOURCES_ALGORITHM_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_ALGORITHM_FILES:.c=.o))
OBJ_SOURCES_ERRORS_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_ERRORS_FILES:.c=.o))
OBJ_SOURCES_FREE_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_FREE_FILES:.c=.o))
OBJ_SOURCES_INITIALIZATION_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_INITIALIZATION_FILES:.c=.o))
OBJ_SOURCES_OPERATIONS_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_OPERATIONS_FILES:.c=.o))
OBJ_SOURCES_VALIDATION_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_VALIDATION_FILES:.c=.o))
OBJ_SOURCES_VISUALIZATION_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_VISUALIZATION_FILES:.c=.o))

OBJECTS = $(OBJ_SOURCES_CORE) $(OBJ_SOURCES_ALGORITHM_CORE) $(OBJ_SOURCES_ERRORS_CORE) $(OBJ_SOURCES_FREE_CORE) $(OBJ_SOURCES_INITIALIZATION_CORE) $(OBJ_SOURCES_OPERATIONS_CORE) $(OBJ_SOURCES_VALIDATION_CORE) $(OBJ_SOURCES_VISUALIZATION_CORE)

all: $(NAME)

$(NAME): $(OBJECTS)
		@(make -C checker_sources)
		@($(GCC) $(GCC_FLAGS) $(OBJECTS) -o $(NAME) -L libraries -lft -L libraries -lmlx -framework OpenGL -framework AppKIt)
		@(echo "[0;92m"$(NAME) "was created![0;0m")

clean:
		@(/bin/rm -rf checker_sources/$(OBJ_PATH))
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "[0;91mAll object files have been deleted![0;0m")

fclean: clean
		@(/bin/rm -f checker)
		@(/bin/rm -f $(NAME))
		@(echo "[0;91m"$(NAME) "has been deleted![0;0m")

re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(SOURCES_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_ALGORITHM_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_ERRORS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_FREE_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_INITIALIZATION_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_OPERATIONS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_VALIDATION_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")

objects/%.o: $(SOURCES_VISUALIZATION_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")
