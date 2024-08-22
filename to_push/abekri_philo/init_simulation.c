/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:04:35 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:10:22 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philosophers)
	{
		philos[i].last_meal_time = current_timestamp();
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine,
				&philos[i]) != 0)
		{
			printf("Error creating philosopher thread\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_create(&philos->data->monitor_philosophers, NULL,
			monitor_philosophers, philos) != 0)
	{
		printf("Error creating monitor thread\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	join_threads(t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philosophers)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			printf("Error joining philosopher thread\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_join(philos->data->monitor_philosophers, NULL) != 0)
	{
		printf("Error joining monitor thread\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simulation(t_philosopher *philos)
{
	philos->data->begin_time = current_timestamp();
	if (create_threads(philos) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (join_threads(philos) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
