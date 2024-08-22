/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:44:54 by abekri            #+#    #+#             */
/*   Updated: 2024/07/10 23:06:13 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	mult;
	int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

long long	current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long int)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philosopher *philo, char *status)
{
	t_data		*data;
	long long	timestamp;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	timestamp = current_timestamp() - data->begin_time;
	if (!data->stop_simulation)
		printf("%lld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&data->print_mutex);
}

void	upgrade_sleep(long long time, t_data *data)
{
	long long	begin_time;

	begin_time = current_timestamp();
	while (current_timestamp() - begin_time < time)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->stop_simulation)
		{
			pthread_mutex_unlock(&data->mutex);
			break ;
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(500);
	}
}

int	ft_isdigit(int dgt)
{
	if ((dgt >= '0' && dgt <= '9'))
		return (1);
	return (0);
}
