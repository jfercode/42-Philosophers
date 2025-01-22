/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:01:30 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/22 13:15:14 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Checks the state of a philosopher to see if they have died.
/// @param table the table with information reference
/// @param i the index of the philosopher being checked
/// @return true if the philosopher has died, otherwise false
bool	ft_check_philosopher_state(t_table *table, int i)
{
	int	j;

	j = 0;
	if ((ft_obtain_current_time(table) - table->philos[i].last_meal_time
			> table->time_to_die
			|| ft_obtain_current_time(table) > table->time_to_die)
		&& !table->philos[i].is_eating)
	{
		printf(RST"%ld %d"RED" died 😵\n"RST,
			ft_obtain_current_time(table), table->philos[i].id);
		pthread_mutex_lock(&table->table_mutex);
		table->end_simulator = true;
		pthread_mutex_unlock(&table->table_mutex);
		pthread_mutex_unlock(&table->philos[i].first_fork->mutex);
		pthread_mutex_unlock(&table->philos[i].second_fork->mutex);
		return (true);
	}
	return (false);
}

/// @brief Checks if all philos have allready eats and they are full
/// @param table the table with information reference
/// @return true if all philos are full, otherwise false
bool	ft_check_all_philos_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (!table->philos[i].full)
			return (false);
		i++;
	}
	printf(RST"%ld "GREEN"All philosophers are full 🐷🥴🐷\n"RST,
		ft_obtain_current_time(table));
	pthread_mutex_lock(&table->table_mutex);
	table->end_simulator = true;
	pthread_mutex_unlock(&table->table_mutex);
	return (true);
}
