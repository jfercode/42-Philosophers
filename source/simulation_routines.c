/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:34:54 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 11:54:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief philosopher take left and right fork to eat
/// @param philo the philosopher  
void	ft_take_forks(t_philo *philo)
{
	struct timeval	current_time;

	if (pthread_mutex_lock(&philo->first_fork->mutex))
	{
		philo->first_fork->in_use = true;
		gettimeofday(&current_time, NULL);
		printf("%ld %d has taken a fork\n",
			current_time.tv_usec - philo->table->start_simulator.tv_usec,
			philo->id);
	}
	if (pthread_mutex_lock(&philo->second_fork->mutex))
	{
		philo->second_fork->in_use = true;
		gettimeofday(&current_time, NULL);
		printf("%ld %d has taken a fork\n",
			current_time.tv_usec - philo->table->start_simulator.tv_usec,
			philo->id);
	}
}

/// @brief philosopher put down left and right fork after eat
/// @param philo the philosopher
void	ft_put_down_forks(t_philo *philo)
{
	struct timeval	current_time;

	if (pthread_mutex_unlock(&philo->first_fork->mutex))
	{
		philo->first_fork->in_use = false;
		gettimeofday(&current_time, NULL);
		printf("%ld %d put down a fork\n",
			current_time.tv_usec - philo->table->start_simulator.tv_usec,
			philo->id);
	}
	if (pthread_mutex_unlock(&philo->second_fork->mutex))
	{
		philo->second_fork->in_use = false;
		gettimeofday(&current_time, NULL);
		printf("%ld %d put down a fork\n",
			current_time.tv_usec - philo->table->start_simulator.tv_usec,
			philo->id);
	}
}

/// @brief philosopher action to eat
/// @param philo the philosopher
void	ft_philo_eats(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld %d is eating\n",
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	philo->last_meal_time = current_time.tv_usec;
	philo->meals_eaten++;
	usleep(philo->table->time_to_eat * 1000);
}

/// @brief philosopher action to sleep
/// @param philo the philosopher
void	ft_philo_sleeps(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld %d is sleeping\n",
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	usleep(philo->table->time_to_sleep * 1000);
}

/// @brief philosopher action to think
/// @param philo the philosopher // TO DO: gestion de la muerte
void	ft_philo_thinks(t_philo *philo)
{
	struct timeval	current_time;
	long			time_until_starvation;
	long			time_to_think;

	gettimeofday(&current_time, NULL);
	time_until_starvation = philo->table->time_to_die
		- (current_time.tv_usec - philo->last_meal_time);
	if (time_until_starvation <= 0)
		philo->table->end_simulator = true;
	time_to_think = time_until_starvation / 2;
	printf("%ld %d is thinking\n",
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	usleep(time_to_think * 1000);
}
