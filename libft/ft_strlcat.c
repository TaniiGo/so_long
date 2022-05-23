/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:40:50 by keigo             #+#    #+#             */
/*   Updated: 2022/01/18 14:51:05 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	dstsize_tmp;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstsize_tmp = dstsize;
	while (*dst != '\0' && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	if (!dstsize)
		return (dstsize_tmp + srclen);
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
