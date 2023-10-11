/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:11:34 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/11 09:29:26 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**dest;

	if (str == NULL)
		return (NULL);
	dest = (char **) ft_calloc(count_words(str, c) + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
			dest[k++] = ft_strndup(str + j, i - j);
	}
	dest[k] = NULL;
	return (dest);
}
