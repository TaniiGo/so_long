/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:22:18 by keigo             #+#    #+#             */
/*   Updated: 2022/01/17 12:06:38 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	size_t	i;

	if (!haystack)
		ft_memset(NULL, 1, 1);
	needlelen = ft_strlen(needle);
	if (!needlelen)
		return ((char *)haystack);
	i = 0;
	while (i + needlelen <= len && *(haystack + i))
	{
		if (!ft_strncmp(haystack + i, needle, needlelen))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
