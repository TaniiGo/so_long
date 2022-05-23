/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keigo <keigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:32:51 by keigo             #+#    #+#             */
/*   Updated: 2022/01/24 20:18:57 by keigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_of_strs(char const *s, char c)
{
	size_t	n_strs;
	size_t	i;

	n_strs = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			n_strs++;
		i++;
	}
	return (n_strs);
}

static void	*free_strs(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**split(char **strs, const char *s, char c, size_t n_strs)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < n_strs)
	{
		len = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			len++;
			j++;
		}
		strs[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!strs[i])
			return (free_strs(strs, i));
		ft_strlcpy(strs[i], &s[j - len], len + 1);
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	n_strs;

	if (!s)
		return (NULL);
	n_strs = get_num_of_strs(s, c);
	strs = (char **)malloc(sizeof(char *) * (n_strs + 1));
	if (!strs)
		return (NULL);
	strs = split(strs, s, c, n_strs);
	if (strs == NULL)
		return (NULL);
	strs[n_strs] = NULL;
	return (strs);
}
