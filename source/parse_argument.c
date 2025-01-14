/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:52:16 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/14 11:39:39 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static bool	ft_is_valid_argument(const char *argv)
{
	int	i;

	i = 0;
	while (ft_isspace(argv[i]))
		i++;
	if (argv[i] == '+' || ft_isdigit(argv[i]))
		i++;
	else
		return (false);
	if (argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	ft_initialice_table_with_parse_argv(long parsed_argv,
			t_table *table, int idx)
{
	if (idx == 1)
		table->philo_nbr = parsed_argv;
	else if (idx == 2)
		table->time_to_die = parsed_argv;
	else if (idx == 3)
		table->time_to_eat = parsed_argv;
	else if (idx == 4)
		table->time_to_sleep = parsed_argv;
	else if (idx == 5)
		table->number_of_times_each_philo_must_eat = parsed_argv;
}

/**
 @brief Parses the command-line arguments, validates them,
 * and initializes a table structure.
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 * @param table A pointer to the table structure to be initialized.
 */
void	ft_parse_argument(char **argv, t_table *table)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_valid_argument(argv[i]))
			ft_error_parsing(table);
		else
			ft_initialice_table_with_parse_argv(ft_atol(argv[i]), table, i);
		i++;
	}
	if (table->philo_nbr < 2 || table->time_to_eat <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0
		|| table->philo_nbr >= 250)
		ft_error_parsing(table);
}
