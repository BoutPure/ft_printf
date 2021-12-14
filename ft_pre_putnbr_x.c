/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_putnbr_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 22:12:52 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// BIT_1 = '-'
// BIT_2 = '+'
// BIT_3 = ' '
// BIT_4 = '#'
// BIT_5 = '0'
// BIT_6 = '.'

/*
Preprocess functions for x and X
*/
int	ft_pre_putnbr_x_put_0x(t_flags *str, char x)
{
	int	i;

	i = 0;
	if ((str->flags & BIT_4) == BIT_4 && x == 'x')
		i += ft_putstr_s("0x", 0);
	if ((str->flags & BIT_4) == BIT_4 && x == 'X')
		i += ft_putstr_s("0X", 0);
	return (i);
}

int	ft_pre_putnbr_x_zr_acc(t_flags *str, int num, int numlen, char x)
{
	int	i;

	i = 0;
	if ((str->flags & BIT_6) == BIT_6 && str->acc == 0 && num == 0)
		return (0);
	if (num >= 0 && (str->flags & BIT_5) == BIT_5 && str->acc == 0)
		i += ft_putnbr_x(num, x);
	else if ((str->flags & BIT_5) == BIT_5 && str->acc == 0)
		i += ft_putnbr_x(num, x);
	else
	{
		if (str->acc != 0 && str->acc > numlen)
			i += ft_putchar_n_times('0', str->acc - numlen);
		i += ft_putnbr_x(num, x);
	}
	return (i);
}

int	ft_pre_putnbr_x_putwidth(t_flags *str, int num, int numlen, char x)
{
	int	i;
	int	zerox;

	i = 0;
	zerox = 0;
	if ((str->flags & BIT_4) == BIT_4)
		zerox = 2;
	if ((str->flags & BIT_5) == BIT_5 && !((str->flags & BIT_6) == BIT_6))
	{
		i += ft_pre_putnbr_x_put_0x(str, x);
		i += ft_putchar_n_times('0', str->width - numlen - zerox);
	}
	else
	{
		if ((str->flags & BIT_6) == BIT_6 && str->acc == 0 && num == 0)
			numlen = 0;
		if (str->acc < numlen)
			i += ft_putchar_n_times(' ', str->width - numlen - zerox);
		else
			i += ft_putchar_n_times(' ', str->width - str->acc - zerox);
		i += ft_pre_putnbr_x_put_0x(str, x);
	}
	return (i);
}

int	ft_pre_putnbr_x(t_flags *str, va_list ap, char x)
{
	int			i;
	int			numlen;
	int			num;

	i = 0;
	num = va_arg(ap, int);
	if (num == 0)
		str->flags &= ~BIT_4;
	numlen = ft_numlen_u_x((unsigned int) num);
	if (str->width != 0 && str->width >= numlen && str->width > str->acc)
	{
		if ((str->flags & BIT_1) == BIT_1)
		{
			i += ft_pre_putnbr_x_put_0x(str, x);
			i += ft_pre_putnbr_x_zr_acc(str, num, numlen, x);
			i += ft_putchar_n_times(' ', str->width - i);
			return (i);
		}
		i += ft_pre_putnbr_x_putwidth(str, num, numlen, x);
		i += ft_pre_putnbr_x_zr_acc(str, num, numlen, x);
		return (i);
	}
	i += ft_pre_putnbr_x_put_0x(str, x);
	i += ft_pre_putnbr_x_zr_acc(str, num, numlen, x);
	return (i);
}
