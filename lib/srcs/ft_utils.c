/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:38:35 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/24 22:05:27 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"), 6);
	i = 0;
	while (s[i])
	{
		write(1, &s[i++], 1);
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	pointer;
	int				res;

	pointer = (unsigned long)ptr;
	res = 0;
	if (pointer > 15)
		res += ft_putptr((void *)(pointer / 16));
	res += ft_putchar("0123456789abcdef"[pointer % 16]);
	return (res);
}

int	ft_putnbr(int nbr)
{
	char	*ret;
	int		tmp;

	tmp = 0;
	ret = ft_itoa(nbr);
	tmp += ft_putstr(ret);
	free(ret);
	return (tmp);
}

int	ft_put_unnbr(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr < 10)
		return (ft_putchar(nbr + '0'));
	if (nbr > 9)
	{
		res += ft_put_unnbr(nbr / 10);
		res += ft_putchar(nbr % 10 + 48);
	}
	return (res);
}

int	ft_puthexa(unsigned int nbr, char *base)
{
	int		res;
	int		i;
	char	tmp[8];

	res = 0;
	i = 0;
	while (nbr != 0 || i == 0)
	{
		tmp[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i)
		res += ft_putchar(tmp[--i]);
	return (res);
}
