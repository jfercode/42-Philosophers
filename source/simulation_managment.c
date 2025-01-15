/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_managment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:05:02 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 11:54:27 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Create all threads for the philos
/// @param table the table with information to access to data
void	ft_start_simulation(t_table *table)
{
	int	i;

	i = 0;
	gettimeofday(&table->start_simulator, NULL);
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, &ft_philo_routine, &table->philos[i]) != 0)
			ft_error_exit("Error: Failed to create thread\n");
		i++;
	}
}

/// @brief the routine that the philosophers follow to live 
///	take forks -> eat -> put down forks -> sleep -> think
/// @param arg the philosopher link
void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->end_simulator)
	{
		ft_take_forks(philo);
		while (1)
		{
			if (philo->first_fork->in_use == false
				&& philo->second_fork->in_use == false)
			{
				ft_philo_eats(philo);
				break ;
			}
		}
		ft_put_down_forks(philo);
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	printf("End simulation");
	return (NULL);
}
