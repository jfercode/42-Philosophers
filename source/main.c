/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:35:09 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/14 12:45:29 by jaferna2         ###   ########.fr       */
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
}

/// @brief Create all threads for the philos
/// @param table the table with information to access to data
static void	ft_start_simulation(t_table *table)
{
	int	i;

	i = 0;
	gettimeofday(&table->start_simulator, NULL);
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, &ft_philo_routine, &table->philos[i]) != 0)
			ft_error_exit("Error: Failed to create thread\n");
		i++;
	}
}

/// @brief the routine that the philosophers follow to live 
///	take forks -> eat -> put down forks -> sleep -> think
/// @param arg the philosopher link
void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->end_simulator)
	{
		ft_take_forks(philo);
		ft_philo_eats(philo);
		ft_put_down_forks(philo);
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
	}
	return (NULL);
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
		ft_debug_table(table);
		ft_clean_data(table);
	}
	return (0);
}
