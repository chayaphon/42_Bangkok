NAME = minitalk
NAME_C = client
NAME_S = server
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus
SRC_C = sources/client.c
SRC_S = sources/server.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
SRC_C_BONUS = sources/client_bonus.c
SRC_S_BONUS = sources/server_bonus.c
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)

LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

main: libft $(NAME)
bonus: libft $(NAME_C_BONUS) $(NAME_S_BONUS)

$(NAME): $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_C) -o $@ $(LIB)

$(NAME_S): $(OBJ_S) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_S) -o $@ $(LIB)

$(NAME_C_BONUS) : $(OBJ_C_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_C_BONUS) -o $@ $(LIB)

$(NAME_S_BONUS) : $(OBJ_S_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_S_BONUS) -o $@ $(LIB)

libft:
	@ make -C libft/

clean:
	$(REMOVE) $(OBJ_C) $(OBJ_S) $(OBJ_C_BONUS) $(OBJ_S_BONUS)
	make -C libft/ clean

fclean: clean
	$(REMOVE) $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)
	make -C libft/ fclean

re: fclean main
re_bonus: fclean bonus

.PHONY: libft main bonus clean fclean re re_bonus
