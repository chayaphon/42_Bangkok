NAME = libft.a
SOURCES = ft_atoi.c ft_print_cs.c ft_print_du.c ft_print_xp.c ft_printf.c ft_strlen.c
PREFIXED_SOURCES = $(addprefix sources/,$(SOURCES))
OBJECTS = $(PREFIXED_SOURCES:.c=.o)
HEADER = includes/libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): sources/%.o: sources/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
