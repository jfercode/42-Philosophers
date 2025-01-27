/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:16:52 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:02 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief function to check that all threads are correctly created
/// @param table the table with references
void	ft_wait_all_threads(t_table *table)
{
	pthread_mutex_lock(&table->start_mutex);
	while (!table->all_threads_ready)
		;
	gettimeofday(&table->start_simulator, NULL);
	pthread_mutex_unlock(&table->start_mutex);
}

/// @brief Function to obtain the curren time since the start of simulation
/// @param table table with references
/// @return a long variable with elapsed_time in ms
long	ft_obtain_current_time(t_table *table)
{
	struct timeval		current;
	long long			elapsed_time_ms;

	gettimeofday(&current, NULL);
	elapsed_time_ms = (current.tv_sec
			- table->start_simulator.tv_sec) * 1000;
	elapsed_time_ms += (current.tv_usec
			- table->start_simulator.tv_usec) / 1000;
	return (elapsed_time_ms);
}

/// @brief Function safe of deadlock mutex for printf normal logs
/// @param table the table with references
/// @param philo philo that executes the action
/// @param action the action executed by the philo
void	ft_safe_log(t_table *table, t_philo *philo,
				const char *action)
{
	long	current_time;

	pthread_mutex_lock(&table->print_mutex);
	if (!table->end_simulator)
	{
		current_time = ft_obtain_current_time(table);
		printf(RST"%ld %d"BLUE"%s\n"RST, current_time, philo->id, action);
	}
	pthread_mutex_unlock(&table->print_mutex);
}

/// @brief	Function safe of deadlock mutex for printf logs with forks
/// @param table the table with references
/// @param philo philo that executes the action with the fork
/// @param action the action executed by the philo
/// @param fork_id the fork used by the philo
void	ft_safe_fork_log(t_table *table, t_philo *philo,
				const char *action, int fork_id)
{
	long	current_time;

	pthread_mutex_lock(&table->print_mutex);
	if (!table->end_simulator)
	{
		current_time = ft_obtain_current_time(table);
		printf(RST"%ld %d"BLUE"%s %d fork\n"RST,
			current_time, philo->id, action, fork_id);
	}
	pthread_mutex_unlock(&table->print_mutex);
}
