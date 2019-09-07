NAME = push_swap

GCC = gcc

GCC_FLAGS = -Wall -Wextra -Werror

AR = ar
AR_FLAGS = rcs

SRC_PATH = sources
OBJ_PATH = objects/
INC_PATH = includes

GCC_INCLUDE = -I $(INC_PATH)

SRC_PATH = sources/
SRC_INITIALIZATION_PATH = sources/initialization/
SRC_OPERATIONS_PATH = sources/operations/
SRC_VALIDATION_PATH = sources/validation/

SRC_FILES = main.c 
SRC_INITIALIZATION_FILES = initialization.c new_list.c get_indexes.c 
SRC_OPERATIONS_FILES = push.c swap.c rotate.c reverse_rotate.c 
SRC_VALIDATION_FILES = validation.c 

OBJ__CORE = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))
OBJ_INITIALIZATION_CORE = $(addprefix $(OBJ_PATH), $(SRC_INITIALIZATION_FILES:.c=.o))
OBJ_OPERATIONS_CORE = $(addprefix $(OBJ_PATH), $(SRC_OPERATIONS_FILES:.c=.o))
OBJ_VALIDATION_CORE = $(addprefix $(OBJ_PATH), $(SRC_VALIDATION_FILES:.c=.o))

OBJECTS = $(OBJ__CORE) $(OBJ_INITIALIZATION_CORE) $(OBJ_OPERATIONS_CORE) $(OBJ_VALIDATION_CORE) 

all: $(NAME)

$(NAME): $(OBJECTS)
		@($(GCC) $(GCC_FLAGS) -o $(NAME) $(OBJECTS))
		@(echo $(NAME) "was created!")

clean:
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "All objects files have been deleted!")

fclean: clean
		@(/bin/rm -f $(NAME))
		@(echo $(NAME) "has been deleted!")

re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(SRC_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_INITIALIZATION_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_OPERATIONS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(SRC_VALIDATION_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) $(GCC_INCLUDE) -c $< -o $@)
		@(echo $< "->" $@)

