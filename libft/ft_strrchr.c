/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:57:44 by keigo             #+#    #+#             */
/*   Updated: 2022/01/18 15:23:11 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*match;
	int		is_match;

	is_match = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			match = (char *)s;
			is_match = 1;
		}
		s++;
	}
	if (is_match)
		return (match);
	else if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
