/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:40:10 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/13 13:14:51 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Prints debugging information for the table structure.
 * @param table_to_debug A pointer to the `t_table` structure to be debugged.
 */
void	ft_debug_table(t_table *table)
{
	printf(GREEN"\nDebug: philo_nbr: %ld\n", table->philo_nbr);
	printf(GREEN"Debug: time_to_die: %ld\n", table->time_to_die);
	printf(GREEN"Debug: time_to_eat: %ld\n", table->time_to_eat);
	printf(GREEN"Debug: time_to_sleep: %ld\n", table->time_to_sleep);
	printf(GREEN"Debug: number_of_times_each_philo_must_eat: %ld\n\n"RST,
		table->number_of_times_each_philo_must_eat);
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
	printf(GREEN"\nDebug: Fork address: %p\n"RST, fork);
	printf(GREEN"Debug: Fork ID: %d\n"RST, fork->fork_id);
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
	printf(GREEN"\nDebug: Philosopher ID: %d\n"RST, philo->id);
	printf(GREEN"Debug: Meals Eaten: %ld\n"RST, philo->meals_eaten);
	if (philo->full)
		printf(GREEN"Debug: Is Full: true\n"RST);
	else
		printf(GREEN"Debug: Is Full: "RED"false\n"RST);
	printf(GREEN"Debug: Last Meal Time: %ld\n"RST, philo->last_meal_time);
	if (philo->left_fork)
		printf(GREEN"Debug: Left Fork id: %d \n"RST, philo->left_fork->fork_id);
	if (philo->right_fork)
		printf(GREEN"Debug: Right Fork id: %d\n"RST, philo->right_fork->fork_id);
	printf(GREEN"Debug: Thread ID: %lu\n"RST, philo->thread);
	if (philo->table)
		printf(GREEN"Debug: Has link to table\n"RST);
	else
		printf(RED"Debug: Table is NULL.\n"RST);
}
