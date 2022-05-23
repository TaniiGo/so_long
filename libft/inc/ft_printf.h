/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:48:11 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/23 16:44:44 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	parse_converting_specifier(const char format, va_list arg);
int	print_c(va_list arg);
int	print_s(va_list arg);
int	print_di(va_list arg);
int	print_p(va_list arg);
int	print_x(va_list arg, char c);
int	print_u(va_list arg);

#endif