/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:43:37 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/21 16:01:01 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_server_config(struct sigaction *s_server)
{
	if (sigaction(SIGUSR1, s_server, NULL) < 0)
	{
		ft_putstr_fd("[SERVER] - Error: SIGUSR1 asn't been set.",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (sigaction(SIGUSR2, s_server, NULL) < 0)
	{
		ft_putstr_fd("[SERVER] - Error: SIGUSR2 asn't been set.",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	ft_handler(int signum)
{
	static int	bits;
	static char	message;

	bits = 0;
	message = 0;
	if (signum == SIGUSR1)
		message |= 1 << (((sizeof(int) * 8) - 1) - bits);
	else if (signum == SIGUSR2)
		message |= 1 << (((sizeof(char) * 8) - 1) - bits);
	bits++;
	if (bits == 0)
	{
		if (message == '\0')
			ft_putstr_fd("Message received", STDOUT_FILENO);
		else
			ft_putstr_fd(&message, STDOUT_FILENO);
		bits = 0;
		message = 0;
	}
}

int	main(void)
{
	struct sigaction	s_server;

	ft_putstr_fd("[SERVER] - PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	s_server.sa_handler = &ft_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESETHAND;
	ft_server_config(&s_server);
	while (1)
		pause();
	return (0);
}
