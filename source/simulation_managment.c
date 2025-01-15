/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_managment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:05:02 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 16:03:56 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Create all threads for the philos
/// @param table the table with information to access to data
void	 ft_start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, &ft_philo_routine, &table->philos[i]) != 0)
			ft_error_exit("Error: Failed to create thread\n");
		i++;
	}
	gettimeofday(&table->start_simulator, NULL);
	pthread_mutex_lock(&table->table_mutex);
	pthread_mutex_unlock(&table->table_mutex);
	table->all_threads_ready = true;
	i = 0;
	while (i < table->philo_nbr)
		pthread_join(table->philos[i].thread, NULL);
	
}

/// @brief the routine that the philosophers follow to live 
///	take forks -> eat -> put down forks -> sleep -> think
/// @param arg the philosopher link
void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;
	struct timeval	current_time;

	philo = (t_philo *)arg;
	ft_wait_all_threads(philo->table);
	while (!philo->full)
	{
		ft_take_forks(philo);
		ft_philo_eats(philo);
		ft_put_down_forks(philo);
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	if (philo->full)
	{
		gettimeofday(&current_time, NULL);
		printf(RST"%ld %d"GREEN" is full, eats %ld times\n"RST,
		current_time.tv_usec - philo->table->start_simulator.tv_usec,
		philo->id, philo->meals_eaten);
	}
	return (NULL);
}
