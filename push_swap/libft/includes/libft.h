/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:09:47 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:09:50 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	void			*index;
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
int		ft_print_c(const int c);
int		ft_print_s(const char *s);
int		ft_print_d(const int d);
int		ft_print_u(const unsigned int u);
int		ft_print_p(const size_t p);
int		ft_print_x(const unsigned int x, const char c);
int		ft_base(char *result, size_t n, const char *base);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_lstsize(t_list *lst);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memset(void *b, int c, size_t len);
t_list	*ft_lstnew(void *index, void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
