/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:12:20 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/01 20:45:21 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	putnbr_u(unsigned int n)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
		putnbr_u(n / 10);
	write(1, base + (n % 10), 1);
}

int	print_u(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	putnbr_u(n);
	return (getlen_u(n));
}
