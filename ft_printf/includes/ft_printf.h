/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:40:04 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/02 19:47:51 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_c(const int c);
int	ft_print_s(const char *s);
int	ft_print_d(const int d);
int	ft_print_u(const unsigned int u);
int	ft_print_p(const size_t p);
int	ft_print_x(const unsigned int x, const char c);
int	ft_base(char *result, size_t n, const char *base);
int	ft_strlen(const char *s);

#endif