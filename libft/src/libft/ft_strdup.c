/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:47:47 by keigo             #+#    #+#             */
/*   Updated: 2022/01/18 15:53:52 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	char	*n;

	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	n = new;
	while (*str)
		*n++ = *str++;
	*n = '\0';
	return (new);
}
