/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:37:47 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/11 08:25:22 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_lint(long long n)
{
	unsigned int	count;
	long long		temp;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == INT_MIN)
			temp = -(long long)INT_MIN;
		else
			temp = -n;
	}
	else
		temp = n;
	while (temp)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

static void	ft_calc(char *res, long long num, unsigned int length, int sign)
{
	while (num)
	{
		res[length + sign - 1] = (num % 10) + '0';
		num /= 10;
		length--;
	}
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	length;
	int				sign;
	long long		num;

	num = n;
	length = ft_lint(num);
	sign = (n < 0);
	res = (char *)malloc(sizeof(char) * (length + sign + 1));
	if (!res)
		return (NULL);
	if (sign)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	res[length + sign] = '\0';
	ft_calc(res, num, length, sign);
	return (res);
}
