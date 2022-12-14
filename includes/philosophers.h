#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

# define ERR_ARGNB "Invalid number of arguments"
# define ERR_MALLOC "Malloc Error"
# define ERR_MUTINIT "Mutex init failed"
# define ERR_TIME "gettimeofday failed"

# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_philosopher {
    unsigned int  position;
    unsigned int  left_fork;
    unsigned int  right_fork;
    unsigned int  last_meal;
} t_philosopher;

typedef struct s_data {
    unsigned int  nb_philos;
    unsigned int  time_to_die;
    unsigned int  time_to_eat;
    unsigned int  time_to_sleep;
    unsigned int  nb_meals;
    int time_start;
    int *forks;
    t_philosopher *philos;
    pthread_mutex_t **forks_mutexes;
    pthread_mutex_t *write_mutex;
    pthread_mutex_t *dead_mutex;
} t_data;


int ft_atoui(char *str, unsigned int *n);
int ft_error(char *str);
int init_data(t_data *data, int argc, char **argv);
int init_philosophers(t_data *data);
int init_mutexes(t_data *data);
long int    get_time(void);
pthread_mutex_t *init_mutex(t_data *data);
void free_data(t_data *data);
void free_philos(t_data *data);

#endif