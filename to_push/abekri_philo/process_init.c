/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:19:16 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:09:14 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_data **data, int argc, char **argv)
{
	if (allocate_data(data) == FAILURE)
		return (FAILURE);
	if (initialize_data_values(*data, argc, argv) == FAILURE)
	{
		free(*data);
		return (FAILURE);
	}
	if (initialize_mutexes(*data) == FAILURE)
	{
		free((*data)->forks);
		free(*data);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	initiate_process(t_philosopher **philos, int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (init_data(&data, argc, argv) == FAILURE)
	{
		return (FAILURE);
	}
	if (init_philosophers(philos, data) == FAILURE)
	{
		free(data->forks);
		free(data);
		return (FAILURE);
	}
	return (SUCCESS);
}
