/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:35:09 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 16:06:21 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/// @brief Initialize the data for running philosophers
/// @param argc argument count
/// @param argv the arguments array
/// @param table the table with information to store data
static void	ft_data_initialization(char **argv, t_table *table)
{
	t_philo	*philos;
	t_fork	*forks;

	table->philos = NULL;
	table->forks = NULL;
	ft_parse_argument(argv, table);
	forks = ft_create_forks(table);
	table->forks = forks;
	philos = ft_create_philos(table);
	table->philos = philos;
	table->all_threads_ready = false;
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		ft_error_exit("Error: Wrong input given\n" RST
			"Expected: ./philosophers number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]");
	else
	{
		table = malloc(sizeof(t_table));
		if (!table)
			ft_error_exit("Error: failed to malloc for table\n");
		ft_data_initialization(argv, table);
		ft_start_simulation(table);
		ft_clean_data(table);
	}
	return (0);
}
