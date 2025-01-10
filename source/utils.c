/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:24 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/10 11:15:09 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/**
 * @brief Checks if a character is a whitespace character.
 * @param c The character to check.
 * @return `true` if the character is a whitespace character, otherwise `false`.
 */
bool	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}
/**
 * @brief Checks if a string contains only numeric characters.
 * @param str A pointer to the null-terminated string to check.
 * @return `true` if the string contains only numeric characters, 
 * otherwise `false`.
 */
bool	ft_isdigit(const char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

/**
 * @brief Converts a string to a long integer.
 * @param nptr A pointer to the null-terminated string to convert.
 * @return The resulting long integer representation of the string.
 */
long	ft_atol(const char *nptr)
{
	int			i;
	int			s;
	long		n;

	i = 0;
	n = 0;
	s = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * s);
}
