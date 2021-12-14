/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_putnbr_d_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 22:12:45 by vseel            ###   ########.fr       */
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
Preprocess functions for d and i
*/
int	ft_pre_putnbr_d_pl_sp(t_flags *str, int num)
{
	int	i;

	i = 0;
	if (num < 0)
		i += ft_putchar('-');
	else if ((str->flags & BIT_3) == BIT_3 || (str->flags & BIT_2) == BIT_2)
	{
		if ((str->flags & BIT_2) == BIT_2)
			i += ft_putchar('+');
		else
			i += ft_putchar(' ');
	}
	return (i);
}

int	ft_pre_putnbr_d_acc(t_flags *str, int num, int numlen)
{
	int	i;

	i = 0;
	if ((str->flags & BIT_6) == BIT_6 && str->acc == 0 && num == 0)
		return (0);
	if (num >= 0)
	{
		if (str->acc != 0 && str->acc > numlen)
			i += ft_putchar_n_times('0', str->acc - numlen);
		i += ft_putnbr_d(num);
	}
	else
	{
		if (str->acc != 0 && str->acc >= numlen)
			i += ft_putchar_n_times('0', str->acc - numlen + 1);
		i += ft_putnbr_d(num);
	}
	return (i);
}

int	ft_pre_putnbr_d_putwidth_pos(t_flags *str, int num, int numlen)
{
	int	i;

	i = 0;
	if ((str->flags & BIT_5) == BIT_5 && !((str->flags & BIT_6) == BIT_6))
	{
		if ((str->flags & BIT_3) == BIT_3 || (str->flags & BIT_2) == BIT_2)
		{
			i += ft_pre_putnbr_d_pl_sp(str, num);
			numlen++;
		}
		i += ft_putchar_n_times('0', str->width - numlen);
	}
	else
	{
		if ((str->flags & BIT_6) == BIT_6 && str->acc == 0 && num == 0)
			numlen = 0;
		if (str->acc < numlen)
			i += ft_putchar_n_times(' ', str->width - numlen);
		else
			i += ft_putchar_n_times(' ', str->width - str->acc);
		i += ft_pre_putnbr_d_pl_sp(str, num);
	}
	return (i);
}

int	ft_pre_putnbr_d_putwidth(t_flags *str, int num, int numlen)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		if ((str->flags & BIT_5) == BIT_5 && !((str->flags & BIT_6) == BIT_6))
		{
			i += ft_pre_putnbr_d_pl_sp(str, num);
			i += ft_putchar_n_times('0', str->width - numlen);
		}
		else
		{
			if (str->acc < numlen)
				i += ft_putchar_n_times(' ', str->width - numlen);
			else
				i += ft_putchar_n_times(' ', str->width - str->acc - 1);
			i += ft_pre_putnbr_d_pl_sp(str, num);
		}
	}
	else
		i += ft_pre_putnbr_d_putwidth_pos(str, num, numlen);
	return (i);
}

int	ft_pre_putnbr_d(t_flags *str, va_list ap)
{
	int			i;
	int			numlen;
	int			num;

	i = 0;
	num = va_arg(ap, int);
	numlen = ft_numlen(num, 'i');
	if (str->width != 0 && str->width >= numlen && str->width > str->acc)
	{
		if ((str->flags & BIT_1) == BIT_1)
		{
			i += ft_pre_putnbr_d_pl_sp(str, num);
			i += ft_pre_putnbr_d_acc(str, num, numlen);
			i += ft_putchar_n_times(' ', str->width - i);
			return (i);
		}
		i += ft_pre_putnbr_d_putwidth(str, num, numlen);
		i += ft_pre_putnbr_d_acc(str, num, numlen);
		return (i);
	}
	i += ft_pre_putnbr_d_pl_sp(str, num);
	i += ft_pre_putnbr_d_acc(str, num, numlen);
	return (i);
}
