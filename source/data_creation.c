/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:59:25 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/16 12:02:26 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	ft_assign_forks_to_philo(t_philo *philo, int id)
{
	int	philo_count;

	philo_count = philo->table->philo_nbr;
	if (id == 0)
	{	
		philo->first_fork = &philo->table->forks[0];
		philo->second_fork = &philo->table->forks[(philo_count - 1)];
		return ;
	}	
	philo_count = philo->table->philo_nbr;
	philo->first_fork = &philo->table->forks[id];
	philo->second_fork = &philo->table->forks[(id + 1)
		% philo_count];
	if (philo->id % 2)
	{
		philo->second_fork = &philo->table->forks[id];
		philo->first_fork = &philo->table->forks[(id + 1)
			% philo_count];
	}
}

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
		forks[i].fork_id = i;
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
	i = 0;
	while (i < table->philo_nbr)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].full = false;
		philos[i].table = table;
		pthread_mutex_init(&philos[i].mutex, NULL);
		ft_assign_forks_to_philo(&philos[i], i);
		i++;
	}
	return (philos);
}
