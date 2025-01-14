/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:59:25 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/14 11:40:32 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Simple creation an initialization a fork
/// @param table the table with require information
/// @param id the id of the created fork
/// @return return a fork with the id given 
t_fork	*ft_create_forks(t_table *table)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!forks)
		ft_error_exit("Error: Failed to malloc for forks\n");
	i = 0;
	while (i < table->philo_nbr)
	{
		forks[i].fork_id = i + 1;
		forks[i].in_use = false;
		pthread_mutex_init(&forks[i].mutex, NULL);
		i++;
	}
	return (forks);
}

/// @brief Simple creation an initialization a philo
/// @param table the table with require information
/// @return returns a philo with simple information and the id given
t_philo	*ft_create_philos(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!philos)
		ft_error_exit("Error: Failed to malloc for philo\n");
	i = table->philo_nbr;
	while (--i >= 0)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].full = false;
		if (table->forks)
		{
			philos[i].left_fork = &table->forks[i];
			philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		}
		philos[i].table = table;
	}
	return (philos);
}
