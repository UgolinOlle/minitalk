/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:55:34 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/11 15:21:40 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!(res))
		return (NULL);
	ft_memmove(res, s1, i);
	res[i] = '\0';
	return (res);
}
