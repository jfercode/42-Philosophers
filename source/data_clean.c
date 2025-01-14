/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:03:01 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/14 10:16:04 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Cleaning data function
/// @param table the table where the data is stored
void	ft_clean_data(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
	{
		while (i < table->philo_nbr)
		{
			pthread_mutex_destroy(&table->forks[i].mutex);
			i++;
		}
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
	if (table)
		free(table);
}
