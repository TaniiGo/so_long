/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:14:08 by keigo             #+#    #+#             */
/*   Updated: 2022/01/17 20:30:45 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numlen(unsigned int n)
{
	int	numlen;

	if (n == 0)
		return (1);
	numlen = 0;
	while (0 < n)
	{
		numlen++;
		n = n / 10;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	num;
	int				numlen;

	if (n < 0)
		num = -n;
	else
		num = n;
	numlen = get_numlen(num);
	if (n < 0)
		numlen++;
	s = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	s[numlen] = '\0';
	while (0 < num)
	{
		s[--numlen] = num % 10 + '0';
		num = num / 10;
	}
	return (s);
}
