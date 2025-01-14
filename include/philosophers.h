/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:30:33 by jaferna2          #+#    #+#             */
/*   Updated: 2025/01/14 10:11:58 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"

typedef struct s_table	t_table;

typedef struct s_fork
{
	int				fork_id;
	bool			in_use;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_eaten;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	t_table		*table;
}				t_philo;

struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philo_must_eat;
	long	start_simulator;
	bool	end_simulator;
	t_fork	*forks;
	t_philo	*philos;
};

void	ft_debug_fork(t_fork *fork);
void	ft_clean_data(t_table *table);
void	ft_debug_philo(t_philo *philo);
void	ft_error_parsing(t_table *table);
void	ft_error_exit(const char *error_msg);
void	ft_debug_table(t_table *table_to_debug);
void	ft_parse_argument(char **argv, t_table *table);

long	ft_atol(const char *nptr);

bool	ft_isspace(const char c);
bool	ft_isdigit(const char c);

t_fork	*ft_create_forks(t_table *table);
t_philo	*ft_create_philos(t_table *table);

#endif	/* PHILOSOPHERS_H */
