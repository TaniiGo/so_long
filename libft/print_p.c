/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:36:50 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/01 20:34:47 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen_p(unsigned long int n)
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

static void	putnbr_p(unsigned long int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		putnbr_p(n / 16);
	write(1, base + (n % 16), 1);
}

int	print_p(va_list arg)
{
	unsigned long int	n;

	n = va_arg(arg, unsigned long int);
	ft_putstr_fd("0x", 1);
	putnbr_p(n);
	return (getlen_p(n) + 2);
}
