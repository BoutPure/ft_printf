/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 16:06:53 by vseel            ###   ########.fr       */
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
Preprocess functions for p 
*/
int	ft_pre_putptr_zr_acc(t_flags *str, void *num, int numlen)
{
	int	i;

	i = 0;
	if (str->acc != 0 && str->acc > numlen)
		i += ft_putchar_n_times('0', str->acc - numlen);
	i += ft_putptr((unsigned long int)num);
	return (i);
}

int	ft_pre_putptr_putwidth(t_flags *str, int numlen)
{
	int	i;

	i = 0;
	if ((str->flags & BIT_5) == BIT_5 && !((str->flags & BIT_6) == BIT_6))
	{
		i += ft_putstr_s("0x", 0);
		i += ft_putchar_n_times('0', str->width - numlen - 2);
	}
	else
	{
		if (str->acc < numlen)
			i += ft_putchar_n_times(' ', str->width - numlen - 2);
		else
			i += ft_putchar_n_times(' ', str->width - str->acc - 2);
		i += ft_putstr_s("0x", 0);
	}
	return (i);
}

int	ft_pre_putptr(t_flags *str, va_list ap)
{
	int					i;
	int					numlen;
	void				*num;

	i = 0;
	num = va_arg(ap, void *);
	numlen = ft_numlen((long long int) num, 'x');
	if (str->width != 0 && str->width > numlen && str->width > str->acc)
	{
		if ((str->flags & BIT_1) == BIT_1)
		{
			i += ft_putstr_s("0x", 0);
			i += ft_pre_putptr_zr_acc(str, num, numlen);
			i += ft_putchar_n_times(' ', str->width - i);
			return (i);
		}
		i += ft_pre_putptr_putwidth(str, numlen);
		i += ft_pre_putptr_zr_acc(str, num, numlen);
		return (i);
	}
	i += ft_putstr_s("0x", 0);
	i += ft_pre_putptr_zr_acc(str, num, numlen);
	return (i);
}
