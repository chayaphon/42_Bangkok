NAME = libft.a
LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_strlen.c ft_split.c ft_strncmp.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c
PRINTF_SRCS = ft_print_cs.c ft_print_du.c ft_print_xp.c ft_printf.c
GNL_SRCS = get_next_line_utils.c get_next_line.c
LIBFT_SRCS_P = $(addprefix sources/,$(LIBFT_SRCS))
PRINTF_SRCS_P = $(addprefix sources/,$(PRINTF_SRCS))
GNL_SRCS_P = $(addprefix sources/,$(GNL_SRCS))
OBJ_LIBFT = $(LIBFT_SRCS_P:.c=.o)
OBJ_PRINTF = $(PRINTF_SRCS_P:.c=.o)
OBJ_GNL = $(GNL_SRCS_P:.c=.o)
HEADER_LIBFT = includes/libft.h
HEADER_PRINTF = includes/ft_printf.h
HEADER_GNL = includes/get_next_line.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
	ar rcs $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)

$(OBJ_LIBFT): %.o: %.c $(HEADER_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_PRINTF): %.o: %.c $(HEADER_PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_GNL): %.o: %.c $(HEADER_GNL)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
