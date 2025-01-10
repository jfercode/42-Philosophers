/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:35:09 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/09 14:55:30 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
		ft_parse_argument(argc, argv, table);
	}
	return (0);
}
