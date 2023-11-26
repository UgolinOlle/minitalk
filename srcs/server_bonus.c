/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:43:37 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/26 18:47:10 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Signal handler for the server.
 *
 * This function is called when a signal is received by the server.
 * It reconstructs characters from the bits sent by the client.
 * After receiving a complete character, it is printed to the standard output.
 * If a null character is received,
	a "Message received" notification is printed.
 *
 * @param signum The signal number received (SIGUSR1 or SIGUSR2).
 * @param sv_info Information about the signal, including the sender's PID.
 * @param context Pointer to a context,
	not used in this function (can be ignored).
 */
static void	ft_handler(int signum, siginfo_t *info, void *ucontent)
{
	static int	bits;
	static int	c;

	(void)ucontent;
	if (signum == SIGUSR1)
		c += 1 << (7 - bits);
	bits++;
	if (bits == 8 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_handle_error("[SERVER] - Error: cannot send to SIGUSR2.");
		c = 0;
		bits = 0;
	}
}

/**
 * @brief Configures the server to handle signals.
 *
 * Sets up the signal handling for SIGUSR1 and SIGUSR2 using sigaction.
 * In case of failure, prints an error message and exits.
 */
static void	ft_config_server(void)
{
	struct sigaction	sa_server;

	sa_server.sa_sigaction = &ft_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	if (sigaction(SIGUSR1, &sa_server, NULL) < 0)
		ft_handle_error("[SERVER] - Error: SIGUSR1 asn't been set.");
	else if (sigaction(SIGUSR2, &sa_server, NULL) < 0)
		ft_handle_error("[SERVER] - Error: SIGUSR2 asn't been set.");
}

/**
 * @brief Main function of the server program.
 *
 * Initializes the server, displays its PID, and waits for signals.
 * Upon receiving signals, processes them to reconstruct and print messages.
 *
 * @return Always returns EXIT_SUCCESS.
 */
int	main(void)
{
	ft_putstr_fd("\033[92m[SERVER] - PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n\033[0m\033[90m[SERVER] - Waiting for message...\033[0m\n",
		STDOUT_FILENO);
	ft_config_server();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
