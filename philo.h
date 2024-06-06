#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>   //write, usleep
#include <stdio.h>    //printf
#include <stdlib.h>   //malloc, free
#include <pthread.h>  //mutex: init destroy lock unlock
#include <sys/time.h> //gettimeofday
#include <stdbool.h>
#include <limits.h>

#define WRONG_INPUT 1
#define INIT_ERROR 2
#define TIME_ERROR "gettimeofday() FAILURE"
#define THREAD_ERROR 3
#define JOIN_ERROR "ERROR WHILE JOINING THREADS"
#define TAKE_FORK "has taken a fork"
#define SLEEPING "is sleeping"
#define EATING "is eating"
#define THINKING "is thinking"
#define DEAD "is dead"

typedef struct s_container
{
    int nbr_philo;
    long long time_to_die;
    long long time_to_eat;
    long long time_to_sleep;
    int nbr_meals;
    pthread_mutex_t *mutex_forks; //
    unsigned long long int timestamp_one; // nachaloto na programata
    pthread_mutex_t writing_lock;                    // mutex za printa
    pthread_mutex_t meal_check;               //shte se griji da spre za da otchete hranene
    int all_dead;                           // flag za print na umrelia
    int all_ate;                           //shows if everyone is done eating
    pthread_mutex_t meal_lock;
} t_container;

typedef struct s_philo
{
    int philo_id;                     // nomera na philo, za da vidq koi podred qde. Osnovno vajen za printa
    int left_fork;       // lqvata vilica kluchalka
    int right_fork;      // dqsna vilica kluchalka
    int busy_eating;                  // flag za monitora da sledi dali philo qde v momenta i da ne go ubie dokato qde, da go propusne na check
    pthread_t thread_proocess;        // processite philo v deistvie, te sa nishkite
    unsigned long long int timestamp_last_meal;  // vreteto otcheteno sled kato philo e ql
    int meals_count;                  // sledi broq hraneniq dali e postignat
    t_container *container;           // vruzka s datata v konteinera
    bool finished_eating;
    //dobaveni
    int x_ate; //meals_count
} t_philo;

int ft_input_check(int argc, char *argv[]);
bool ft_argv_check(int argc, char *argv[]);
bool ft_digit_check(const char *str);
bool ft_strlen(const char *str);
bool ft_int_check(long long nbr);
long long ft_atol(const char *str);
void ft_print_instructions(void);
int ft_error_instuctions();
bool ft_init(t_container *container, t_philo **philo,int argc, char **argv);
bool ft_init_container(t_container *container, int argc, char **argv);
bool ft_alloc(t_container *container, t_philo **philo);
int ft_dealloc(t_philo *philo);
bool ft_init_forks(t_container *container, t_philo *philo);
bool ft_init_philo(t_container *container, t_philo *philo);
unsigned long long int ft_get_time(void);
bool ft_thread_start(t_container *container, t_philo *philo);
void *ft_routine(void *void_philo);
void ft_eat(t_philo *philo);
void ft_smart_sleep(unsigned long long int time, t_container *container);
unsigned long long int ft_time_difference(unsigned long long int past, unsigned long long int pres);
void ft_print(t_container *container, int philo_id, char *str);
void ft_monitor_check(t_container *container,t_philo *philo);
void ft_finish(t_container *container, t_philo *philo);
void ft_set_dead(t_container *container, int value);
int ft_get_dead(t_container *container);

#endif