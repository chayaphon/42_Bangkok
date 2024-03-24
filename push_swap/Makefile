NAME = push_swap
SRCS = main.c push_swap.c operation_parse.c operation_rotate_reverse.c operation_rotate.c operation_swap.c utils_general.c utils_sort.c utils_chunk.c 
PRE_SRCS = $(addprefix sources/push_swap/,$(SRCS))
OBJ = $(PRE_SRCS:.c=.o)
HEADER = includes/push_swap.h

NAME_BONUS = checker
SRCS_BONUS = main_bonus.c input_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS_ORI = operation_parse.c operation_rotate_reverse.c operation_rotate.c operation_swap.c utils_general.c utils_sort.c
PRE_SRCS_BONUS = $(addprefix sources/checker/,$(SRCS_BONUS))
PRE_SRCS_BONUS_ORI = $(addprefix sources/push_swap/,$(SRCS_BONUS_ORI))

OBJ_BONUS = $(PRE_SRCS_BONUS:.c=.o)
OBJ_BONUS_ORI = $(PRE_SRCS_BONUS_ORI:.c=.o)
HEADER_BONUS = includes/checker_bonus.h

LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
REMOVE = rm -f

main: libft $(NAME)
bonus : libft $(NAME_BONUS)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

$(OBJ): %o: %c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS_ORI) $(OBJ_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS_ORI) $(OBJ_BONUS) -o $@ $(LIB)

$(OBJ_BONUS): %o: %c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_BONUS_ORI): %o: %c $(HEADER)
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
