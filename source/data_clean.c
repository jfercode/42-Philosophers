/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:03:01 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/20 12:34:43 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Cleaning data function
/// @param table the table where the data is stored
// TO DO  -> Destroy all mutex at end of simulation and try to detach al threads
void	ft_clean_data(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
	{
		while (i < table->philo_nbr)
		{
			pthread_mutex_destroy(&table->forks[i].mutex);
			pthread_mutex_destroy(&table->philos[i].mutex);
			i++;
		}
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	if (table)
		free(table);
}
