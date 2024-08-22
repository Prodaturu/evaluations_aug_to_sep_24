/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:02:53 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:20:19 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philosophers(t_philosopher *philos, t_data *data)
{
	int	i;
	int	finished_eating;

	i = -1;
	finished_eating = 0;
	while (++i < data->num_philosophers)
	{
		if (current_timestamp() - philos[i].last_meal_time > data->time_to_die)
		{
			print_status(&philos[i], "died");
			data->stop_simulation = 1;
			return (EXIT_FAILURE);
		}
		if (data->num_times_each_philosopher_must_eat != -1
			&& philos[i].meals_eaten
			>= data->num_times_each_philosopher_must_eat)
		{
			finished_eating++;
		}
	}
	if (finished_eating == data->num_philosophers)
		data->stop_simulation = 1;
	return (EXIT_SUCCESS);
}

void	*monitor_philosophers(void *args)
{
	t_philosopher	*philos;
	t_data			*data;

	philos = (t_philosopher *)args;
	data = philos->data;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->stop_simulation)
		{
			pthread_mutex_unlock(&data->mutex);
			break ;
		}
		if (check_philosophers(philos, data) != EXIT_SUCCESS)
		{
			pthread_mutex_unlock(&data->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mutex);
	}
	return (NULL);
}
