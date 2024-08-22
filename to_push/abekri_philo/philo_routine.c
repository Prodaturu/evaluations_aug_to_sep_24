/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:01:52 by abekri            #+#    #+#             */
/*   Updated: 2024/07/10 23:57:27 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_eat(t_philosopher *philo, t_data *data)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&data->mutex);
	philo->last_meal_time = current_timestamp();
	pthread_mutex_unlock(&data->mutex);
	upgrade_sleep(data->time_to_eat, data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&data->mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->mutex);
}

void	*philosopher_routine(void *args)
{
	t_philosopher	*philo;
	t_data			*data;

	philo = (t_philosopher *)args;
	data = philo->data;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->stop_simulation)
		{
			pthread_mutex_unlock(&data->mutex);
			break ;
		}
		pthread_mutex_unlock(&data->mutex);
		print_status(philo, "is thinking");
		philosopher_eat(philo, data);
		print_status(philo, "is sleeping");
		upgrade_sleep(data->time_to_sleep, data);
	}
	return (NULL);
}
