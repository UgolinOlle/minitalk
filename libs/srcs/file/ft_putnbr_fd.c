/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:49:15 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/11 09:09:37 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		res;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		res = nb + '0';
		write(fd, &res, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		res = nb % 10 + '0';
		write(fd, &res, 1);
	}
}
