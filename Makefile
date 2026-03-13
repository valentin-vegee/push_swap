NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

SRC =	src/main.c \
		src/parse/parse.c \
		src/parse/parse_utils.c \
		src/parse/stack_parse_utils.c \
		src/parse/ft_split.c \
		src/parse/ft_strcmp.c \
		src/stack/stack_access.c \
		src/stack/stack_analysis.c \
		src/ops/op_swap.c \
		src/ops/op_push.c \
		src/ops/op_rotate.c \
		src/ops/op_revrotate.c

OBJ_DIR = .build
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)/%.o: %.c include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
