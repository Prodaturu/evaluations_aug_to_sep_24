/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:04:28 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:23:08 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
	{
		printf("Error: failed to malloc data\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	set_basic_values(t_data *data, int argc, char **argv)
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->num_philosophers < 1 || data->num_philosophers > 200)
	{
		printf("Error: num_philosophers must be between 1 and 200\n");
		return (FAILURE);
	}
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
	{
		printf("Error: time_to_die, time_to_eat,"
			"and time_to_sleep must be greater than 0\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	set_additional_values(t_data *data, int argc, char **argv)
{
	if (argc == 6)
	{
		data->num_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (data->num_times_each_philosopher_must_eat <= 0)
		{
			printf("Error: num_times_each_philosopher_must_eat"
				"must be greater than 0 if provided\n");
			return (FAILURE);
		}
	}
	else
	{
		data->num_times_each_philosopher_must_eat = -1;
	}
	data->stop_simulation = 0;
	return (SUCCESS);
}

int	initialize_data_values(t_data *data, int argc, char **argv)
{
	if (set_basic_values(data, argc, argv) == FAILURE)
	{
		return (FAILURE);
	}
	if (set_additional_values(data, argc, argv) == FAILURE)
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

int	initialize_mutexes(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_philosophers);
	if (!data->forks)
	{
		printf("Error: failed to malloc forks\n");
		return (FAILURE);
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->last_eat, NULL);
	pthread_mutex_init(&data->done, NULL);
	pthread_mutex_init(&data->mutex, NULL);
	return (SUCCESS);
}
