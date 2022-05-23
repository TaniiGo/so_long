/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:10:14 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/10 18:12:19 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_converting_specifier(const char format, va_list arg)
{
	char	percent;

	percent = '%';
	if (format == 'c')
		return (print_c(arg));
	else if (format == 's')
		return (print_s(arg));
	else if (format == 'd' || format == 'i')
		return (print_di(arg));
	else if (format == 'p')
		return (print_p(arg));
	else if (format == 'x')
		return (print_x(arg, 'x'));
	else if (format == 'X')
		return (print_x(arg, 'X'));
	else if (format == 'u')
		return (print_u(arg));
	else if (format == '%')
		return (write(1, &percent, 1));
	return (0);
}
