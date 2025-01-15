/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:34:54 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 15:48:23 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief philosopher take left and right fork to eat
/// @param philo the philosopher  
void	ft_take_forks(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(&philo->first_fork->mutex);
	philo->first_fork->in_use = true;
	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" has taken a fork\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	pthread_mutex_lock(&philo->second_fork->mutex);
	philo->second_fork->in_use = true;
	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" has taken a fork\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
}

/// @brief philosopher put down left and right fork after eat
/// @param philo the philosopher
void	ft_put_down_forks(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_unlock(&philo->first_fork->mutex);
	philo->first_fork->in_use = false;
	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" put down a fork\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	pthread_mutex_unlock(&philo->second_fork->mutex);
	philo->second_fork->in_use = false;
	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" put down a fork\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
}

/// @brief philosopher action to eat
/// @param philo the philosopher
void	ft_philo_eats(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" is eating\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal_time = current_time.tv_usec;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex);
	usleep(philo->table->time_to_eat * 1000);
	if (philo->meals_eaten 
		== philo->table->number_of_times_each_philo_must_eat)
		philo->full = true;
}

/// @brief philosopher action to sleep
/// @param philo the philosopher
void	ft_philo_sleeps(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" is sleeping\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
	usleep(philo->table->time_to_sleep * 1000);
}

/// @brief philosopher action to think
/// @param philo the philosopher // TO DO: gestion de la muerte
void	ft_philo_thinks(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf(RST"%ld %d"BLUE" is thinking\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id);
}
