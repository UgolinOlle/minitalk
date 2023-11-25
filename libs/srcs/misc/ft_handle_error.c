/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:00:08 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/25 14:03:47 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_errors(char *content)
{
	ft_putstr_fd(content, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
