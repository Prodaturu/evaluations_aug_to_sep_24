/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:38:38 by analunga          #+#    #+#             */
/*   Updated: 2024/08/09 19:01:46 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** ft_atoi:
** Converts a string to an integer. Handles leading whitespace,
** optional sign, and digits.
**
** Parameters:
**   - nptr: Pointer to the string to be converted.
**
** Returns:
**   - The integer value of the string. If the string is not a valid integer,
**     the function will return 0.
*/
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr && (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
			|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/*
** ft_strlen:
** Calculates the length of a string.
**
** Parameters:
**   - str: Pointer to the string whose length is to be calculated.
**
** Returns:
**   - The length of the string. If the string is NULL, returns 0.
*/
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
** ft_putnbr:
** Outputs an integer to the standard output.
**
** Parameters:
**   - n: The integer to be printed.
**
** Returns:
**   - None.
*/
void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

/*
** send_char:
** Sends a character to the server process, bit by bit, using signals.
** SIGUSR2 is sent for a '1' bit, and SIGUSR1 is sent for a '0' bit.
**
** Parameters:
**   - pid: The PID of the server process.
**   - c: The character to be sent.
**
** Returns:
**   - None.
*/
void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}
