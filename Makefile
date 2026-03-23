NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INC_DIR		= include
SRC_DIR		= src
PARSE_DIR	= $(SRC_DIR)/parsing
ERROR_DIR	= $(SRC_DIR)/errors
OPS_DIR		= $(SRC_DIR)/operations
SORT_DIR	= $(SRC_DIR)/sorting
STACK_DIR	= $(SRC_DIR)/stack

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)

SRC			= $(SRC_DIR)/main.c \
			  $(PARSE_DIR)/ps_atoi.c \
			  $(PARSE_DIR)/ps_parse_input.c \
			  $(ERROR_DIR)/ps_error_exit.c \
			  $(OPS_DIR)/ps_op_push.c \
			  $(OPS_DIR)/ps_op_reverse_rotate.c \
			  $(OPS_DIR)/ps_op_rotate.c \
			  $(OPS_DIR)/ps_op_swap.c \
			  $(SORT_DIR)/ps_radix_sort.c \
			  $(SORT_DIR)/ps_small_sort.c \
			  $(STACK_DIR)/ps_stack.c \
			  $(STACK_DIR)/ps_utils.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(INC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re