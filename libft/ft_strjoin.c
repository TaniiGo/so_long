/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:58:19 by keigo             #+#    #+#             */
/*   Updated: 2022/01/18 14:36:46 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*new;
	char	*n;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new)
		return (NULL);
	n = new;
	while (*s1)
		*n++ = *s1++;
	while (*s2)
		*n++ = *s2++;
	*n = '\0';
	return (new);
}
