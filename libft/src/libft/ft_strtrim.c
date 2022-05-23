/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:15:05 by keigo             #+#    #+#             */
/*   Updated: 2022/01/18 15:28:14 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_newlen(char const *s, char const *set)
{
	size_t	len;

	len = 0;
	while (isinset(*s, set))
		s++;
	while (*s)
	{
		s++;
		len++;
	}
	s--;
	if (len)
	{
		while (isinset(*s, set))
		{
			s--;
			len--;
		}
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	newlen;
	char	*new;

	if (!s1)
		return (NULL);
	newlen = get_newlen(s1, set);
	new = (char *)malloc(sizeof(char) * newlen + 1);
	if (!new)
		return (NULL);
	while (isinset(*s1, set))
		s1++;
	ft_strlcpy(new, s1, newlen + 1);
	return (new);
}
