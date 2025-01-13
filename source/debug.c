/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:40:10 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/13 14:59:43 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Prints debugging information for the table structure.
 * @param table_to_debug A pointer to the `t_table` structure to be debugged.
 */
void	ft_debug_table(t_table *table)
{
	int	i;

	i = 0;
	printf(GREEN"\nDebug: philo_nbr: %ld\n", table->philo_nbr);
	printf(GREEN"Debug: time_to_die: %ld\n", table->time_to_die);
	printf(GREEN"Debug: time_to_eat: %ld\n", table->time_to_eat);
	printf(GREEN"Debug: time_to_sleep: %ld\n", table->time_to_sleep);
	printf(GREEN"Debug: number_of_times_each_philo_must_eat: %ld\n\n"RST,
		table->number_of_times_each_philo_must_eat);
	while (i < table->philo_nbr)
	{
		printf("\n/-----------------/\n");
		ft_debug_fork(&table->forks[i]);
		ft_debug_philo(&table->philos[i]);
		i++;
	}
	
}

/// @brief Prints debugging information for the fork
/// @param fork a pointer to the 't_fork' struct to be debugged.
void	ft_debug_fork(t_fork *fork)
{
	if (!fork)
	{
		printf(RED"Error: fork is NULL.\n"RST);
		return ;
	}
	printf(GREEN"\nDebug: Fork address:"RST" %p\n", fork);
	printf(GREEN"Debug: Fork ID:"RST" %d\n", fork->fork_id);
	if (fork->in_use)
		printf(GREEN"Debug: Fork in use\n"RST);
	else
		printf(GREEN"Debug: Fork unused\n"RST);
	if (pthread_mutex_trylock(&fork->mutex) == 0)
	{
		printf(GREEN"Debug: Mutex is unlocked (accesible)\n"RST);
		pthread_mutex_unlock(&fork->mutex);
	}
	else
		printf(RED"Debug: Mutex is locked (in use)\n"RST);
}

/// @brief Prints debugging information for the philo
/// @param philo a pointer to the 't_philo' struct to be debugged.
void	ft_debug_philo(t_philo *philo)
{
	printf(GREEN"\nDebug: Philosopher ID:"RST" %d\n", philo->id);
	printf(GREEN"Debug: Meals Eaten:"RST" %ld\n", philo->meals_eaten);
	if (philo->full)
		printf(GREEN"Debug: Is Full:"RST" true\n");
	else
		printf(GREEN"Debug: Is Full: "RED"false\n"RST);
	printf(GREEN"Debug: Last Meal Time:"RST" %ld\n", philo->last_meal_time);
	if (philo->left_fork)
		printf(GREEN"Debug: Left Fork id:"RST" %d \n", philo->left_fork->fork_id);
	if (philo->right_fork->fork_id)
		printf(GREEN"Debug: Right Fork id:"RST" %d\n", philo->right_fork->fork_id);
	printf(GREEN"Debug: Thread ID:"RST" %lu\n", philo->thread);
	if (philo->table)
		printf(GREEN"Debug: Has link to table\n"RST);
	else
		printf(RED"Debug: Table is NULL.\n"RST);
}
