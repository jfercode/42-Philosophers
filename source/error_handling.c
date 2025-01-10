/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:47:23 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/10 11:19:42 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Prints an error message and terminates the program.
 * @param error_msg A pointer to the null-terminated string 
 * containing the error message to display.
 */
void	ft_error_exit(const char *error_msg)
{
	printf(RED"%s\n", error_msg);
	exit(EXIT_FAILURE);
}

/**
 * @brief Handles parsing errors and cleans up allocated resources.
 * @param table A pointer to the table structure to be cleaned up.
 */
void	ft_error_parsing(t_table *table)
{
	printf(RED"Error: Invalid argv\n"RST);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
	exit(EXIT_FAILURE);
}
