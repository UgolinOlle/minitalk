/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:28:49 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/09/24 22:03:46 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// -- External library
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

// -- Main function
int	ft_printf(const char *string, ...);

// -- String
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putptr(void *ptr);

// -- Integer
int	ft_put_unnbr(unsigned int nbr);
int	ft_putnbr(int nbr);
int	ft_puthexa(unsigned int nbr, char *base);

#endif
