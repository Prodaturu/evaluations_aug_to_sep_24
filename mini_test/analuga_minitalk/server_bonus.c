/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:53:47 by analunga          #+#    #+#             */
/*   Updated: 2024/08/10 05:51:43 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** handle_signal_bonus:
** Handles the signals received from the client, building a character bit
** by bit from the received signals. Once 8 bits are received, it outputs
** the character and sends an acknowledgment signal back to the client.
**
** Parameters:
**   - sig: the signal number received (either SIGUSR1 or SIGUSR2).
**   - info: a pointer to a siginfo_t structure containing signal-related
**           information.
**   - context: a pointer to context information (unused in this function).
*/
void	handle_signal_bonus(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;

	(void)context;
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
		kill(info->si_pid, SIGUSR1);
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
	sa.sa_sigaction = handle_signal_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
