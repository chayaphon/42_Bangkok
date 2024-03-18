NAME = push_swap
SRCS = main.c push_swap.c operation_parse.c operation_rotate_reverse.c operation_rotate.c operation_swap.c utils_general.c utils_sort.c
PRE_SRCS = $(addprefix _push_swap/sources/,$(SRCS))
OBJ = $(PRE_SRCS:.c=.o)
HEADER = _push_swap/includes/push_swap.h

NAME_BONUS = checker
SRCS_BONUS = main.c checker.c utils.c
PRE_SRCS_BONUS = $(addprefix checker/sources/,$(SRCS_BONUS))
OBJ_BONUS = $(PRE_SRCS_BONUS:.c=.o)

LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
REMOVE = rm -f

main: libft $(NAME)
bonus : libft $(NAME_BONUS)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

$(OBJ): %o: %c $(HEADER)
	$(CC) $(CFLAGS) -I_push_swap/includes -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ $(LIB)

$(OBJ_BONUS): %o: %c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C libft/

clean:
	$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@make -C libft/ clean

fclean: clean
	$(REMOVE) $(NAME) $(NAME_BONUS)
	@make -C libft/ fclean

re: fclean main
re_bonus: fclean bonus

.PHONY: libft main clean fclean re re_bonus
