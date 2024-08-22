/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:54:45 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:09:50 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_errors(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT_FAILURE);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	setup_simulation(t_philosopher **philosopher, int argc, char **argv)
{
	if (check_errors(argc, argv) == EXIT_FAILURE)
	{
		printf("Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	if (initiate_process(philosopher, argc, argv) == FAILURE)
	{
		printf("Failed to initiate processes\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philosopher	*philosopher;

	philosopher = NULL;
	if (setup_simulation(&philosopher, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philosopher->data->num_philosophers == 1)
	{
		init_single_philosopher(&philosopher[0]);
	}
	else
	{
		if (init_simulation(philosopher) == FAILURE)
		{
			printf("Failed to start simulation\n");
			destroy_simulation(philosopher);
			return (FAILURE);
		}
		destroy_simulation(philosopher);
	}
	return (SUCCESS);
}
