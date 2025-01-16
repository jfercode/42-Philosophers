/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:16:52 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/16 12:58:59 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief function to check that all threads are correctly created
/// @param table the table with references
void ft_wait_all_threads(t_table *table)
{
	while (!table->all_threads_ready)
		;
}

/// @brief Function to obtain the curren time since the start of simulation
/// @param table table with references
/// @return a long variable with elapsed_time in ms
long	ft_obtain_current_time(t_table *table)
{
	long			elapsed_time_ms;
	struct timeval 	current;

	gettimeofday(&current, NULL);
	elapsed_time_ms = labs(current.tv_sec
		- table->start_simulator.tv_sec) * 1000;
	elapsed_time_ms += labs(current.tv_usec
		- table->start_simulator.tv_usec) / 1000;
	return (elapsed_time_ms);
}
