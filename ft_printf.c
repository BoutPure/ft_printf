/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:12:09 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 16:21:14 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_specifier_symbol(char *fmt, t_flags *str, va_list ap)
{
	va_list		aq;

	va_copy(aq, ap);
	if (*fmt == '%')
		str->symbcount += ft_pre_putchar(str, '%');
	if (*fmt == 'c')
		str->symbcount += ft_pre_putchar(str, va_arg(ap, int));
	if (*fmt == 's')
		str->symbcount += ft_pre_putstr(str, va_arg(ap, char *));
	if (*fmt == 'p')
		str->symbcount += ft_pre_putptr(str, ap);
	if (*fmt == 'd' || *fmt == 'i')
		str->symbcount += ft_pre_putnbr_d(str, ap);
	if (*fmt == 'u')
		str->symbcount += ft_pre_putnbr_u(str, ap);
	if (*fmt == 'x' || *fmt == 'X')
		str->symbcount += ft_pre_putnbr_x(str, ap, *fmt);
	fmt++;
	return (fmt);
}

char	*ft_parse_width_and_accuracy(char *fmt, t_flags *str, va_list ap)
{
	str->width = 0;
	str->acc = 0;
	while (*fmt && *fmt >= '0' && *fmt <= '9')
		str->width = (str->width * 10) + (*fmt++ - '0');
	if (*fmt == '.')
	{
		str->flags = str->flags | BIT_6;
		fmt++;
	}
	while (*fmt && *fmt >= '0' && *fmt <= '9')
		str->acc = (str->acc * 10) + (*fmt++ - '0');
	fmt = ft_check_specifier_symbol(fmt, str, ap);
	return (fmt);
}

char	*ft_parse_flags(char *fmt, t_flags	*str, va_list ap)
{
	str->flags = 0;
	fmt++;
	while (*fmt && (*fmt == '-'
			|| *fmt == '+' || *fmt == ' '
			|| *fmt == '#' || *fmt == '0'))
	{
		if (*fmt == '-')
			str->flags = str->flags | BIT_1;
		if (*fmt == '+')
			str->flags = str->flags | BIT_2;
		if (*fmt == ' ')
			str->flags = str->flags | BIT_3;
		if (*fmt == '#')
			str->flags = str->flags | BIT_4;
		if (*fmt == '0')
			str->flags = str->flags | BIT_5;
		fmt++;
	}
	fmt = ft_parse_width_and_accuracy(fmt, str, ap);
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	t_flags	*str;

	if (!fmt)
		return (0);
	i = 0;
	str = malloc(sizeof(t_flags));
	if (!str)
		return (0);
	str->symbcount = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = ft_parse_flags((char *)fmt, str, ap);
		str->symbcount += ft_strlen_s((char *)fmt, '%');
		fmt += ft_putstr_s((char *)fmt, '%');
	}
	va_end(ap);
	free (str);
	return (str->symbcount);
}
