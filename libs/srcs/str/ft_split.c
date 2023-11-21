/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:34:46 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/08 19:39:23 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**allocate_and_fill(char const *s, char c, size_t count)
{
	char	**res;
	size_t	i;
	size_t	len;

	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		res[i] = ft_substr(s, 0, len);
		if (!res[i++])
		{
			free(res);
			return (0);
		}
		s += len;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = count_words(s, c);
	return (allocate_and_fill(s, c, count));
}
