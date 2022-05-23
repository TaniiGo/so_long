/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:09:29 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/01 20:45:02 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit_number(int n)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		num = -n;
		count++;
	}
	else
		num = n;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_di(va_list arg)
{
	int	n;
	int	digits;

	n = va_arg(arg, int);
	digits = get_digit_number(n);
	ft_putnbr_fd(n, 1);
	return (digits);
}
