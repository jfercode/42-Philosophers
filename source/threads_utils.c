/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:16:52 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/15 15:08:01 by jaferna2         ###   ########.fr       */
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