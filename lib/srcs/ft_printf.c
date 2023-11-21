/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:37 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/10/04 14:46:20 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_args_parser(char *c, va_list *args)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*c == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(*args, void *)) + 2);
	}
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*c == 'u')
		return (ft_put_unnbr(va_arg(*args, unsigned int)));
	else if (*c == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (*c == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (*c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			res += ft_args_parser((char *)string, &args);
		}
		else
			res += ft_putchar(*string);
		string++;
	}
	va_end(args);
	return (res);
}

int	main(void)
{
	ft_printf("%d\n", "12");
	printf("%d\n", 12);
	return (0);
}
