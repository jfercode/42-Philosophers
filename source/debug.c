/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:40:10 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/10 10:22:38 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Prints debugging information for the table structure.
 * @param table_to_debug A pointer to the `t_table` structure to be debugged.
 */
void	ft_debug_table(t_table *table_to_debug)
{
	printf(GREEN"\nDebug: philo_nbr: %ld\n", table_to_debug->philo_nbr);
	printf(GREEN"Debug: time_to_die: %ld\n", table_to_debug->time_to_die);
	printf(GREEN"Debug: time_to_eat: %ld\n", table_to_debug->time_to_eat);
	printf(GREEN"Debug: time_to_sleep: %ld\n", table_to_debug->time_to_sleep);
	printf(GREEN"Debug: number_of_times_each_philo_must_eat: %ld\n\n"RST,
		table_to_debug->number_of_times_each_philo_must_eat);
}
