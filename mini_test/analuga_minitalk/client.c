/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:56:04 by analunga          #+#    #+#             */
/*   Updated: 2024/08/09 18:43:32 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** handle_ack:
** Handles the acknowledgment signal from the server. This function is
** intentionally empty, serving only to pause the client until the signal
** is received.
**
** Parameters:
**   - sig: the signal number (unused in this function).
*/
void	handle_ack(int sig)
{
	(void)sig;
}

/*
** main:
** Main function of the client program. It sends a message to the
** server process specified by its PID.
**
** Parameters:
**   - argc: the number of command-line arguments.
**   - argv: an array of strings representing the command-line arguments.
**           argv[1] should contain the server PID.
**           argv[2] should contain the message to send.
**
** Returns:
**   - 0 on successful execution.
**   - 1 if incorrect number of arguments are provided.
*/
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	size_t	i;

	if (argc != 3)
	{
		write(2, "Usage: ./client [server_pid] [message]\n", 40);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, handle_ack);
	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	return (0);
}
