/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:43:37 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/25 19:56:01 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file server.c
 * @brief Server program for Minitalk project.
 *
 * This file contains the server code for the Minitalk project.
	The server listens for signals (SIGUSR1 and SIGUSR2) sent by a Minitalk client,
 * and reconstructs the message bit by bit. Once a full character is received,
 * it is printed to the standard output.
 */

#include "../includes/minitalk.h"

/**
 * @brief Gestionnaire de signal pour le serveur.
 *
 * Cette fonction est appelée lorsqu'un signal est reçu par le serveur.
 * Elle reconstruit les caractères à partir des bits envoyés par le client.
 * Après la réception d'un caractère complet,
	celui-ci est imprimé sur la sortie standard.
 * Si un caractère nul est reçu, une notification "Message reçu" est imprimée.
 *
 * @param signum Le numéro du signal reçu (SIGUSR1 ou SIGUSR2).
 * @param sv_info Informations sur le signal, y compris le PID de l'expéditeur.
 * @param context Pointeur vers un contexte,
	non utilisé dans cette fonction (peut être ignoré).
 */
static void	ft_handler(int signum, siginfo_t *info, void *ucontent)
{
	static int				bits = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bits < 0)
		bits = 7;
	if (signum == SIGUSR1)
		c |= (1 << bits);
	bits--;
	if (bits < 0 && c)
	{
		if (c == '\0')
			ft_putstr_fd("\n", STDOUT_FILENO);
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_handle_error("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_handle_error("Failed to send SIGUSR1");
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
	ft_putstr_fd("[SERVER] - PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n[SERVER] - Waiting for message...\n", STDOUT_FILENO);
	ft_config_server();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
