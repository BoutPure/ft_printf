/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_putstr_putchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/07 21:26:18 by vseel            ###   ########.fr       */
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
Preprocess functions for s
*/
int	ft_pre_putstr_acc(t_flags *str, char *s, int strlen)
{
	if (!s)
		return (0);
	if ((str->flags & BIT_6) == BIT_6 && str->acc < strlen)
		return (write(1, s, str->acc));
	return (write(1, s, strlen));
}

int	ft_pre_putstr(t_flags *str, char *s)
{
	int	strlen;
	int	i;

	if (!s)
		s = "(null)";
	strlen = ft_strlen_s(s, 0);
	i = 0;
	if (str->width != 0 && (str->width > strlen
			|| ((str->flags & BIT_6) == BIT_6 && str->width > str->acc)))
	{
		if ((str->flags & BIT_1) == BIT_1)
		{
			i += ft_pre_putstr_acc(str, s, strlen);
			i += ft_putchar_n_times(' ', str->width - i);
			return (i);
		}
		if ((str->flags & BIT_6) == BIT_6 && str->acc < strlen)
			i += ft_putchar_n_times(' ', str->width - str->acc);
		else
			i += ft_putchar_n_times(' ', str->width - strlen);
		i += ft_pre_putstr_acc(str, s, strlen);
		return (i);
	}
	i += ft_pre_putstr_acc(str, s, strlen);
	return (i);
}

/*
Preprocess functions for c
*/
int	ft_pre_putchar(t_flags *str, char c)
{
	int					i;

	i = 0;
	if (str->width != 0 && str->width > 1)
	{
		if ((str->flags & BIT_1) == BIT_1)
		{
			i += ft_putchar(c);
			i += ft_putchar_n_times(' ', str->width - 1);
			return (i);
		}
		if ((str->flags & BIT_5) == BIT_5)
			i += ft_putchar_n_times('0', str->width - 1);
		else
			i += ft_putchar_n_times(' ', str->width - 1);
		i += ft_putchar(c);
		return (i);
	}
	i += ft_putchar(c);
	return (i);
}
