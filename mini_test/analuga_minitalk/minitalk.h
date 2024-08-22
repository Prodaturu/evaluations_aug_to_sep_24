/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:02:04 by analunga          #+#    #+#             */
/*   Updated: 2024/06/07 00:52:27 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <stddef.h>
# include <stdbool.h>
# include <sys/time.h>

void	send_char(pid_t pid, char c);
void	ft_putnbr(int n);
void	handle_signal(int sig);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
void	handle_signal_bonus(int sig, siginfo_t *info, void *context);
void	handle_ack(int sig);
void	handle_timeout(int sig);
void	send_char(pid_t pid, char c);

#endif