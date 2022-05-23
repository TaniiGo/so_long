/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:55:54 by keitanig          #+#    #+#             */
/*   Updated: 2022/04/12 18:56:14 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddc(char *str, char c)
{
	char	*new;
	size_t	i;

	if (!str)
		return (ft_straddc_first(c));
	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i] != '\0')
		new[i] = str[i];
	free(str);
	new[i] = c;
	new[++i] = '\0';
	return (new);
}
