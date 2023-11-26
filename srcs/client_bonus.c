/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:40:26 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/11/26 18:55:37 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Checks the program arguments.
 *
 * Verifies that the client program is launched with the correct arguments.
 * In case of error, displays a message and terminates the program.
 *
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 */
static void	ft_args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("[CLIENT] - Error: wrong format.\n", STDOUT_FILENO);
		ft_putstr_fd("[CLIENT] - Example: ./client <PID> <MESSAGE>",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_handle_error("[CLIENT] - Error: PID is wrong.");
		i++;
	}
	if (*argv[2] == 0)
		ft_handle_error("[CLIENT] - Error:  Message cannot be empty");
}

/**
 * @brief Sends the bits of a message to the server.
 *
 * Sends each character of the message as bits to the server,
 * using SIGUSR1 (for bit 1) and SIGUSR2 (for bit 0) signals.
 *
 * @param pid PID of the server process.
 * @param content Message to send.
 */
static void	ft_send_bits(pid_t sv_pid, char *content)
{
	unsigned char	c;
	int				bits;

	while (*content)
	{
		c = *content;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(100);
			c <<= 1;
		}
		content++;
	}
}

/**
 * @brief Signal handler for the client.
 *
 * Handles the signals received by the client, notably SIGUSR2,
 * indicating that the message has been successfully sent.
 *
 * @param signum Signal number received.
 */
static void	ft_handler(int signum, siginfo_t *sv_info, void *context)
{
	(void)sv_info;
	(void)context;
	if (signum == SIGUSR2)
		ft_putstr_fd("[CLIENT] - Character as been successfully sent.\n",
			STDOUT_FILENO);
}

/**
 * @brief Configures the client for signal handling.
 *
 * Sets up signal handling for the client,
 * defining the actions to take for SIGUSR1 and SIGUSR2.
 */
static void	ft_config_client(void)
{
	struct sigaction	sa_client;

	sa_client.sa_sigaction = &ft_handler;
	sa_client.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_client.sa_mask);
	if (sigaction(SIGUSR1, &sa_client, NULL) < 0)
		ft_handle_error("[CLIENT] - Error: SIGUSR1 asn't been set.");
	else if (sigaction(SIGUSR2, &sa_client, NULL) < 0)
		ft_handle_error("[CLIENT] - Error: SIGUSR2 asn't been set.");
}

/**
 * @brief Main function of the client program.
 *
 * Initializes the client, checks the arguments, sends a message to the server,
 * and indefinitely waits for the reception of signals.
 *
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return Always returns EXIT_SUCCESS.
 */
int	main(int argc, char **argv)
{
	pid_t	pid;

	ft_args_check(argc, argv);
	pid = ft_atoi(argv[1]);
	ft_putstr_fd("[CLIENT] - PID:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_config_client();
	ft_send_bits(pid, argv[2]);
	ft_send_bits(pid, "\n");
	return (EXIT_SUCCESS);
}
