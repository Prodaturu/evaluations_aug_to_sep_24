/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:36:08 by analunga          #+#    #+#             */
/*   Updated: 2024/08/09 18:46:20 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** handle_signal:
** Handles the signals received from the client, building a character bit by bit
** from the received signals. Once 8 bits are received, it outputs the character.
**
** Parameters:
**   - sig: the signal number received (either SIGUSR1 or SIGUSR2).
*/
void	handle_signal(int sig)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;

	if (sig == SIGUSR1)
		current_char |= (0 << bit_count);
	else if (sig == SIGUSR2)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

/*
** main:
** Main function of the server program. It sets up signal handling and
** waits for messages from the client.
**
** Returns:
**   - 0 on successful execution.
*/
int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "Server PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
