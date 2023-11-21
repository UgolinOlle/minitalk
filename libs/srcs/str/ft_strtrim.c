/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:43:27 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/11 11:39:53 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

int	ft_find_char(char str, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s;
	size_t	e;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] && ft_find_char(s1[s], set))
		s++;
	e = ft_strlen(s1);
	while (e > s && ft_find_char(s1[e - 1], set))
		e--;
	res = (char *)malloc(sizeof(char) * (e - s + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s < e)
		res[i++] = s1[s++];
	res[i] = '\0';
	return (res);
}
