NAME = libft.a
SOURCES = ft_atoi.c ft_isdigit.c ft_print_cs.c ft_print_du.c ft_print_xp.c ft_printf.c ft_strlen.c ft_split.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
			
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
