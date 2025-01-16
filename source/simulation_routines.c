/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:34:54 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/16 14:50:54 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief philosopher take left and right fork to eat
/// @param philo the philosopher  
void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->mutex);
	philo->first_fork->in_use = true;
	pthread_mutex_lock(&philo->table->table_mutex);
	printf(RST"%ld %d"BLUE" takes %d fork\n"RST,
		ft_obtain_current_time(philo->table), philo->id,
		philo->first_fork->fork_id);
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_lock(&philo->second_fork->mutex);
	pthread_mutex_lock(&philo->table->table_mutex);
	philo->second_fork->in_use = true;
	printf(RST"%ld %d"BLUE" takes %d fork\n"RST,
		ft_obtain_current_time(philo->table), philo->id,
		philo->second_fork->fork_id);
	pthread_mutex_unlock(&philo->table->table_mutex);
}

/// @brief philosopher put down left and right fork after eat
/// @param philo the philosopher
void	ft_put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->first_fork->mutex);
	philo->first_fork->in_use = false;
	pthread_mutex_lock(&philo->table->table_mutex);
	printf(RST"%ld %d"BLUE" put down %d fork\n"RST,
		ft_obtain_current_time(philo->table), philo->id,
		philo->first_fork->fork_id);
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_unlock(&philo->second_fork->mutex);
	philo->second_fork->in_use = false;
	printf(RST"%ld %d"BLUE" put down %d fork\n"RST,
		ft_obtain_current_time(philo->table), philo->id,
		philo->second_fork->fork_id);
}

/// @brief philosopher action to eat
/// @param philo the philosopher
void	ft_philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_mutex);
	printf(RST"%ld %d"BLUE" is eating\n"RST,
		ft_obtain_current_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal_time = ft_obtain_current_time(philo->table);
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
	pthread_mutex_lock(&philo->table->table_mutex);
	printf(RST"%ld %d"BLUE" is sleeping\n"RST,
		ft_obtain_current_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->table_mutex);
	usleep(philo->table->time_to_sleep * 1000);
}

/// @brief philosopher action to think
/// @param philo the philosopher // TO DO: gestion de la muerte
void	ft_philo_thinks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_mutex);
	printf(RST"%ld %d"BLUE" is thinking\n"RST,
		ft_obtain_current_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->table_mutex);
}
