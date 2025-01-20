/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_managment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:05:02 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/20 16:39:51 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Create all threads for the philos
/// @param table the table with information to access to data
void	 ft_start_simulation(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->table_mutex);
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
	table->all_threads_ready = true;
	i = 0;
	while (++i < table->philo_nbr)
	 	pthread_join(table->philos[i].thread, NULL);
	pthread_join(table->monitor_thread, NULL);
	pthread_mutex_unlock(&table->table_mutex);
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
	while (!philo->table->end_simulator && !philo->full)
	{
		ft_take_forks(philo);
		ft_philo_eats(philo);
		ft_put_down_forks(philo);
		if (philo->full)
			break;
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	if (philo->full)
	{
		gettimeofday(&current_time, NULL);
		printf(RST"%ld %d"GREEN" is full 😋, eats %ld times\n"RST,
		ft_obtain_current_time(philo->table),
			philo->id, philo->meals_eaten);
	}
	return (NULL);
}

/// @brief Checks the state of a philosopher to see if they have died.
/// @param table the table with information reference
/// @param i the index of the philosopher being checked
/// @return true if the philosopher has died, otherwise false
static bool	ft_check_philosopher_state(t_table *table, int i)
{
	int j;

	j = 0;
	if (ft_obtain_current_time(table) - table->philos[i].last_meal_time > table->time_to_die
		|| ft_obtain_current_time(table) > table->time_to_die)
	{
		printf(RST"%ld %d"RED" died 😵\n"RST,
			ft_obtain_current_time(table), table->philos[i].id);
		pthread_mutex_destroy(&table->philos[i].mutex);
		while (j < table->philo_nbr)
			pthread_detach(table->philos[j++].thread);
		table->end_simulator = true;
		return (true);
    }
    return (false);
}

/// @brief Monitor thread that checks for died philosophers
/// @param arg the table with information reference
void	*ft_monitor_thread(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	ft_wait_all_threads(table);
	while (1)
	{
		if (table->end_simulator)
			break ;
		i = 0;
		while (i < table->philo_nbr)
		{
			if (ft_check_philosopher_state(table, i))
				break ;
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
