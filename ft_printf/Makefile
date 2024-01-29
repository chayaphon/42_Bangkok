NAME = libftprintf.a 

SOURCES = ft_printf.c ft_print_c.c ft_print_s.c ft_print_d.c \
			ft_print_p.c ft_print_u.c ft_print_x.c ft_base.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

CC = cc
CCFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

all: $(NAME)

$(NAME): $(HEADER)
	cc $(CCFLAGS) -c $(SOURCES)
	ar rcs $(NAME) $(OBJECTS)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re

