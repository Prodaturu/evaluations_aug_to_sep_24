/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:44:14 by abekri            #+#    #+#             */
/*   Updated: 2024/07/10 23:09:48 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*single_philosopher_routine(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	print_status(philo, "is thinking");
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	usleep(philo->data->time_to_die * 1000 + 1000);
	pthread_mutex_unlock(philo->left_fork);
	print_status(philo, "died");
	return (NULL);
}

void	init_single_philosopher(t_philosopher *philo)
{
	philo->data->begin_time = current_timestamp();
	philo->last_meal_time = current_timestamp();
	if (pthread_create(&philo->thread, NULL, single_philosopher_routine,
			philo) != 0)
	{
		printf("Error: failed to create philosopher thread\n");
		return ;
	}
	pthread_join(philo->thread, NULL);
	destroy_simulation(philo);
}
