
#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	g_error(const char *err)
{
	printf("%s\n", err);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		return (g_error("error : not a valid option"), -2);
	if (str[i] == '+')
		return (g_error("error : not a valid option"), -2);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (g_error("error : not a valid option"), -2);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > INT_MAX)
			return (g_error("error surpassed INT MAX"), -2);
		i++;
	}
	if (str[i] != '\0')
		return (g_error("error : not a valid option"), -2);
	return (result);
}

int	parsing(t_table *table, char **argv)
{
	table->ph_nbr = ft_atoi(argv[1]);
	if (!table->ph_nbr || table->ph_nbr == -2 || table->ph_nbr > 200)
		return (-1);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->max_meals = ft_atoi(argv[5]);
	else
		table->max_meals = -1;
	if (!table->max_meals)
		return (-1);
	if (table->time_die < 60 || table->time_eat < 60 || \
		table->time_sleep < 60 || table->max_meals == -2)
		return (-1);
	return (0);
}
