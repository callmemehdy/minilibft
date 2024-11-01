
#include "philo.h"

void	cclean(t_table *table)
{
	int		i;

	i = -1;
	if (!table)
		return ;
	if (table->forks)
	{
		while (++i < table->ph_nbr)
			pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->print_mutex);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	table = (t_table){0};
	if (ac == 5 || ac == 6)
	{
		if (parsing(&table, av))
			return (cclean(&table), ft_putstr_fd(PERR, 2), 1);
		if (init_table(&table))
			return (cclean(&table), 1);
		if (init_forks(&table))
			return (cclean(&table), 1);
		if (init_philos (&table))
			return (cclean(&table), 1);
		if (start_simulation(&table))
			return (cclean(&table), 1);
		cclean(&table);
		free(table.philos);
		free(table.forks);
	}
	else
		g_error("error: not a valid nb of arguments");
	return (0);
}
