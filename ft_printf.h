/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:02 by vseel             #+#    #+#             */
/*   Updated: 2021/11/05 18:58:03 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# define BIT_1 0x01
# define BIT_2 0x02
# define BIT_3 0x04
# define BIT_4 0x08
# define BIT_5 0x10
# define BIT_6 0x20

typedef struct s_struct
{
	char			flags;
	int				width;
	int				acc;
	int				symbcount;
}	t_flags;

int		ft_printf(const char *fmt, ...);

char	*ft_parse_flags(char *fmt, t_flags *str, va_list ap);
char	*ft_parse_width_and_accuracy(char *fmt, t_flags *str, va_list ap);
char	*ft_check_specifier_symbol(char *fmt, t_flags *str, va_list ap);

int		ft_putchar(char c);
int		ft_putchar_n_times(char c, int n);
int		ft_putstr_s(char *s, char c);
int		ft_putptr(unsigned long int n);
int		ft_putnbr_d(int n);
int		ft_putnbr_u(int n);
int		ft_putnbr_x(int n, char x);

int		ft_pre_putnbr_d(t_flags *str, va_list ap);
int		ft_pre_putnbr_u(t_flags *str, va_list ap);
int		ft_pre_putnbr_x(t_flags *str, va_list ap, char x);
int		ft_pre_putptr(t_flags *str, va_list ap);
int		ft_pre_putstr(t_flags *str, char *s);
int		ft_pre_putchar(t_flags *str, char c);

int		ft_strlen_s(const char *s, char c);
int		ft_numlen(long long int num, char base);
int		ft_numlen_u_x(unsigned int num);

#endif /*FT_PRINTF_H*/