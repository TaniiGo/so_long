/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:48:41 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/01 20:47:35 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen_x(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	putnbr_x(unsigned int n, char c)
{
	char	*base_x;
	char	*base_large_x;

	base_x = "0123456789abcdef";
	base_large_x = "0123456789ABCDEF";
	if (n >= 16)
	{
		putnbr_x(n / 16, c);
	}
	if (c == 'x')
		write(1, base_x + (n % 16), 1);
	else
		write(1, base_large_x + (n % 16), 1);
}

int	print_x(va_list arg, char c)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	putnbr_x(n, c);
	return (getlen_x(n));
}
