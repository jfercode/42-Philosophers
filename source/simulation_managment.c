/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_managment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:05:02 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/22 13:16:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Create all threads for the philos
/// @param table the table with information to access to data
void	ft_start_simulation(t_table *table)
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
	if (pthread_create(&table->monitor_thread,
			NULL, &ft_monitor_thread, table) != 0)
		ft_error_exit("Error: Failed to create thread\n");
	pthread_mutex_lock(&table->table_mutex);
	table->all_threads_ready = true;
	pthread_mutex_unlock(&table->table_mutex);
	i = 0;
	while (i < table->philo_nbr)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(table->monitor_thread, NULL);
}

/// @brief the routine that the philosophers follow to live 
///	take forks -> eat -> put down forks -> sleep -> think
/// @param arg the philosopher link
void	*ft_philo_routine(void *arg)
{
	t_philo			*philo;
	struct timeval	current_time;

	philo = (t_philo *)arg;
	ft_wait_all_threads(philo->table);
	while (!philo->table->end_simulator)
	{
		ft_take_forks(philo);
		ft_philo_eats(philo);
		ft_put_down_forks(philo);
		if (philo->full)
			break ;
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	if (philo->full && !philo->table->end_simulator)
	{
		gettimeofday(&current_time, NULL);
		printf(RST"%ld %d"GREEN" is full 😋, eats %ld times\n"RST,
			ft_obtain_current_time(philo->table),
			philo->id, philo->meals_eaten);
	}
	return (NULL);
}

/// @brief Monitor thread that checks for died philosophers
/// @param arg the table with information reference
void	*ft_monitor_thread(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	ft_wait_all_threads(table);
	while (!table->end_simulator)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			if (ft_check_philosopher_state(table, i)
				|| ft_check_all_philos_full(table))
			{
				table->end_simulator = true;
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
