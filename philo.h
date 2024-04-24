#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>     //write, usleep
#include <stdio.h>      //printf
#include <stdlib.h>     //malloc, free
#include <pthread.h>    //mutex: init destroy lock unlock
                        //threads: create join detach
#include <sys/time.h>   //gettimeofday
#include <stdbool.h>
#include <limits.h>

# define WRONG_INPUT 1
/*input: 
    ./philo 5 600 200 200 6

    *5  is the number of philos
    600 is the time a philo has before dying
    200 is time to eat
    200 is time to sleep
    6   numbers of meals to have before compliting the simulation
*/

/*  structures:
                I will have 2 main arrays of structs: 
                There will be one struct for a philosophers & one for the forks.

                Fork is tehnocally a mutex, so the second struct is going to be a
                stcuct of mutexes
*/

//for the container
typedef struct s_container t_container;

//simplifying the name to make it more readible
typedef pthread_mutex_t t_mutex;

//struct - Fork
typedef struct s_fork
{
    t_mutex fork;
    int fork_id;
}   t_fork;

//struct - Philo
typedef struct s_philo
{
    int id;
    long meals_eaten;       //numbers meals eaten counter
    bool done_eating;       //flag to track the eating
    long last_meal_time;    //time passed from last meal - is to be able to check if it's going to die
    t_fork *left_fork;
    t_fork *right_fork;
    pthread_t thread_id;    //a philo is a thread
    t_container *container;
}   t_philo;

//struct container for input data
/*input: 
    ./philo 5 600 200 200 6

    *5  is the number of philos
    600 is the time a philo has before dying
    200 is time to eat
    200 is time to sleep
    6   numbers of meals to have before compliting the simulation
*/
struct s_container
{
    long philo_nbr;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long nbr_total_meals;
    long start_simulation;
    bool end_similation; //flag for dead philo or end simulation
    t_fork *forks;  //array for forks
    t_philo *philos;    //array for philos
};

void    ft_print_instructions(void);
bool    ft_parse_input(t_container *container, int argc, char *argv[]);


#endif