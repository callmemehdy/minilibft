
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

# define PERR "Invalid input! \nUsage: ./philo \
[PHILOS] [TTDIE] [TTEAT] [TTSLP] [MEALS]\n"

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_table
{
	_Atomic long	ph_nbr;
	_Atomic long	time_die;
	_Atomic long	time_eat;
	_Atomic long	time_sleep;
	_Atomic long	max_meals;
	_Atomic long	start_sim;
	_Atomic bool	end_sim;
	_Atomic bool	death_flag;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	pthread_t			tid;
	_Atomic int			id;
	_Atomic long		meals_counter;
	_Atomic bool		full;
	_Atomic int			full_count;	
	_Atomic long		last_meal;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_table				*table;
}	t_philo;

void	ft_putstr_fd(char *str, int fd);
void	g_error(const char *err);
int		parsing(t_table *table, char **argv);
long	ft_atoi(const char *str);
int		init_table(t_table *table);
int		init_philos(t_table *table);
long	get_timestamp(void);
int		init_forks(t_table *table);
void	print_status(t_philo *philo, char *status);
void	*routine(void *arg);
int		start_simulation(t_table *table);
void	*moni(void *arg);
void	is_sleep(long wait_time, t_table *table);
bool	dining_cycle(t_philo *philo, t_table *table);
int		death_checker(t_table *table, int ph_index);
void	print_status(t_philo *philo, char *status);
bool	ph_exitst(t_table *table, int i);
void	simulation_end(t_table *table);
bool	one_philo(t_table *table);
#endif