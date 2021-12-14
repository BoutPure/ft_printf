/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_ptr_charntimes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:04:01 by vseel             #+#    #+#             */
/*   Updated: 2021/11/06 16:15:01 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_n_times(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
		i += ft_putchar(c);
	return (i);
}

int	ft_putnbr_d(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr_s("2147483648", 0));
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr_d(n / 10);
		i += ft_putnbr_d(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbr_u(int n)
{
	int	i;

	i = 0;
	if ((unsigned int)n > 9)
	{
		i += ft_putnbr_u((unsigned int)n / 10);
		i += ft_putnbr_u((unsigned int)n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putptr(unsigned long int n)
{
	const char		*xlow = "0123456789abcdef";
	int				i;

	i = 0;
	if (n > 15)
	{
		i += ft_putptr(n / 16);
		i += ft_putptr(n % 16);
	}
	else
		i += ft_putchar(xlow[n]);
	return (i);
}

int	ft_putnbr_x(int n, char x)
{
	const char		*xhi = "0123456789ABCDEF";
	const char		*xlow = "0123456789abcdef";
	int				i;

	i = 0;
	if ((unsigned int)n > 15)
	{
		i += ft_putnbr_x((unsigned int)n / 16, x);
		i += ft_putnbr_x((unsigned int)n % 16, x);
	}
	else if (x == 'X')
		i += ft_putchar(xhi[n]);
	else
		i += ft_putchar(xlow[n]);
	return (i);
}
