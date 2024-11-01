/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:25:41 by iazoubi           #+#    #+#             */
/*   Updated: 2024/11/01 16:41:43 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dining_cycle(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&philo->l_fork->fork);
	print_status(philo, "has taken a fork");
	if (table->ph_nbr == 1)
	{
		is_sleep(table->time_die, table);
		pthread_mutex_unlock(&philo->l_fork->fork);
		return (NULL);
	}
	pthread_mutex_lock(&philo->r_fork->fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	philo->last_meal = get_timestamp();
	philo->meals_counter++;
	if (table->max_meals != -1 && philo->meals_counter == table->max_meals)
	{
		philo->full++;
		is_sleep(table->time_eat, table);
		pthread_mutex_unlock(&philo->l_fork->fork);
		pthread_mutex_unlock(&philo->r_fork->fork);
		return (1);
	}
	is_sleep(table->time_eat, table);
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
	print_status(philo, "is sleeping");
	is_sleep(table->time_sleep, table);
	print_status(philo, "is thinking");
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (philo->id % 2)
	{
		print_status(philo, "is thinking");
		is_sleep(30, table);
	}
	while (1)
	{
		if (table->end_sim)
			break ;
		if (dining_cycle(philo, table))
			break ;
		if (table->ph_nbr == 1)
			break ;
	}
	return (NULL);
}

int	death_checker(t_table *table, int ph_index)
{
	if (table->end_sim || table->philos[ph_index].full)
		return (true);
	if ((get_timestamp() - table->philos[ph_index].last_meal) \
	> table->time_die)
	{
		table->end_sim = true;
		print_status(&table->philos[ph_index], "died");
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;

	auto int i, full_count;
	table = (t_table *)arg;
	while (1)
	{
		(1) && (full_count = 0), (i = 0);
		while (i < table->ph_nbr)
		{
			if (death_checker(table, i))
				return (NULL);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

int	start_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor;
	int			index;

	i = 0;
	table->end_sim = false;
	table->start_sim = get_timestamp();
	while (i < table->ph_nbr)
	{
		table->philos[i].table = table;
		table->philos[i].last_meal = table->start_sim;
		if (pthread_create(&table->philos[i].tid, NULL, \
			routine, &table->philos[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
		return (-1);
	index = -1;
	while (++index < table->ph_nbr)
		if (pthread_join(table->philos[index].tid, NULL) != 0)
			return (-1);
	if (pthread_join(monitor, NULL) != 0)
		return (-1);
	return (0);
}
