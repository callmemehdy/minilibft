
#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->death_flag)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return ;
	}
	printf("%ld %d %s\n", get_timestamp() - philo->table->start_sim \
		, philo->id, status);
	if (status && status[0] == 'd')
		philo->table->death_flag++;
	pthread_mutex_unlock(&philo->table->print_mutex);
}

long	get_timestamp(void)
{
	struct timeval	time;
	long			store;

	gettimeofday(&time, NULL);
	store = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (store);
}

void	is_sleep(long wait_time, t_table *data)
{
	long	starting_time;
	long	time_passed;

	starting_time = get_timestamp();
	time_passed = get_timestamp() + wait_time;
	while (time_passed > starting_time && !data->death_flag)
	{
		usleep(100);
		starting_time = get_timestamp();
	}
}

void	simulation_end(t_table *table)
{
	table->end_sim = true;
}
