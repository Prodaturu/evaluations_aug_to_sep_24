/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:55:16 by abekri            #+#    #+#             */
/*   Updated: 2024/07/10 23:48:27 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philosophers(t_philosopher *philosophers)
{
	if (philosophers != NULL)
	{
		free(philosophers);
	}
}

void	destroy_simulation(t_philosopher *philos)
{
	t_data	*data;
	int		num_philosophers;
	int		i;

	if (philos == NULL || philos->data == NULL)
		return ;
	data = philos->data;
	num_philosophers = data->num_philosophers;
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->last_eat);
	pthread_mutex_destroy(&data->done);
	pthread_mutex_destroy(&data->mutex);
	free(data->forks);
	free(data);
	free_philosophers(philos);
}
