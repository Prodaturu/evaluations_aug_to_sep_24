/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:45:45 by mmansuri          #+#    #+#             */
/*   Updated: 2024/07/17 21:07:53 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i1;

	i1 = 0;
	while (s[i1] != '\0')
	{
		write(fd, &s[i1], sizeof(char));
		i1++;
	}
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i1;

	i1 = 0;
	while (s[i1] != '\0')
	{
		write(fd, &s[i1], sizeof(char));
		i1++;
	}
}

void	ft_error(void)
{
	perror(RED "Error");
	exit(1);
}
