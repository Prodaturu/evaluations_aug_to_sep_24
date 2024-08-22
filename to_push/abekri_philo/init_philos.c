/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:59:53 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:03:04 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	allocate_philosophers(t_philosopher **philosophers, t_data *data)
{
	*philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->num_philosophers);
	if (!*philosophers)
	{
		printf("Error: failed to malloc philosophers\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	initialize_philosophers(t_philosopher *philosophers, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].meals_eaten = 0;
		philosophers[i].data = data;
		philosophers[i].left_fork = &data->forks[i];
		if (i == data->num_philosophers - 1)
		{
			philosophers[i].right_fork = &data->forks[0];
		}
		else
		{
			philosophers[i].right_fork = &data->forks[i + 1];
		}
		i++;
	}
}

int	init_philosophers(t_philosopher **philosophers, t_data *data)
{
	if (allocate_philosophers(philosophers, data) == FAILURE)
		return (FAILURE);
	initialize_philosophers(*philosophers, data);
	return (SUCCESS);
}
