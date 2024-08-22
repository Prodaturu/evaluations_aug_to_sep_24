/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:33:32 by yowoo             #+#    #+#             */
/*   Updated: 2024/08/01 19:35:25 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_round		round;
	t_philo		*philo;
	int			i;
	pthread_t	mon_thread;

	philo = 0;
    if (is_inpt_ok(argc, argv))
	{	
		init_struct(&round, argc, argv);
		philo = (t_philo *)malloc(sizeof(t_philo) * round.n_philo);
		init_philos(&philo, &round);
	}
	else
		return (-1);
	i = 0;
	while (i < round.n_philo)
	{
		if ((gettimeofday(&(philo[i].last_eat), NULL) != 0) || ((pthread_create(&(philo[i].thread), NULL, thread_routine, (void *)&(philo[i])) != 0)))
			return (clean(round.n_philo, philo, round, i));
		i++;
	}
	if (pthread_create(&mon_thread, NULL, monitor_death_eat, (void *)(philo)) != 0)
		return (clean(round.n_philo, philo, round, round.n_philo));
	i = -1;
	while (++i< round.n_philo)
		pthread_join(philo[i].thread, NULL);
	pthread_join(mon_thread, NULL);
	if(round.is_error)
		printf("\nError Occured 1: %d\n", round.is_error);
	clean(round.n_philo, philo, round, -1);
	return (0);
}
