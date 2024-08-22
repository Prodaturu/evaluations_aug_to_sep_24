/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:52:05 by abekri            #+#    #+#             */
/*   Updated: 2024/07/11 01:47:57 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ctype.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_each_philosopher_must_eat;
	int				stop_simulation;
	long long		begin_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	done;
	pthread_mutex_t	mutex;
	pthread_t		monitor_philosophers;
}					t_data;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philosopher;

int					initiate_process(t_philosopher **philos, int argc,
						char **argv);
void				*philosopher_routine(void *args);
void				print_status(t_philosopher *philo, char *status);
int					init_simulation(t_philosopher *philos);
void				destroy_simulation(t_philosopher *philos);
long long			current_timestamp(void);
void				upgrade_sleep(long long time, t_data *data);
int					ft_atoi(char *str);
void				free_philosophers(t_philosopher *philosophers);
int					ft_isdigit(int dgt);
void				init_single_philosopher(t_philosopher *philo);
void				*monitor_philosophers(void *args);
int					init_philosophers(t_philosopher **philosophers,
						t_data *data);
int					allocate_data(t_data **data);
int					set_basic_values(t_data *data, int argc, char **argv);
int					set_additional_values(t_data *data, int argc, char **argv);
int					initialize_data_values(t_data *data, int argc, char **argv);
int					initialize_mutexes(t_data *data);

#endif
