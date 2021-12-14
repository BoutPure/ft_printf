/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_str_numlens.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 17:28:55 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_s(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

int	ft_numlen(long long int num, char base)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0 && base != 'x')
	{
		num /= 10;
		i++;
	}
	while (num != 0 && base == 'x')
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	ft_numlen_u_x(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_s(char *s, char c)
{
	if (s)
		return (write(1, s, ft_strlen_s(s, c)));
	return (0);
}
