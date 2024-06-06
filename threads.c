#include "philo.h"

bool ft_thread_start(t_container *container, t_philo *philo) // 👻
{
    int i;
    
    i = 0;
    container->timestamp_one = ft_get_time();
    while (i < container->nbr_philo)
    {
        philo[i].timestamp_last_meal = ft_get_time();
        if (pthread_create(&(philo[i].thread_proocess), NULL, ft_routine, &(philo[i])))
            return (false);
        i++;
    }
    ft_monitor_check(container, philo); //🟡
    ft_finish(container, philo); //🟡
    return (true);
}

void ft_monitor_check(t_container *container,t_philo *philo)
{
    int i;

    while (!(container->all_ate))
    {
        i = -1;
        while (++i < container->nbr_philo && !(ft_get_dead(container)))
        {
            pthread_mutex_lock(&(container->meal_check));
            if (ft_time_difference(philo[i].timestamp_last_meal, ft_get_time()) > (unsigned long long int)container->time_to_die)
            {
                ft_print(container, i, "died");
                ft_set_dead(container, 1);
            }
            pthread_mutex_unlock(&(container->meal_check));
            //usleep(100);
        }
        if (ft_get_dead(container))
            break;
        i = 0;
        pthread_mutex_lock(&container->meal_lock);
        while (container->nbr_meals != -1 && i < container->nbr_philo && philo[i].x_ate >= container->nbr_meals)
            i++;
        pthread_mutex_unlock(&container->meal_lock);
        if (i == container->nbr_philo)
            container->all_ate = 1;
    }
}

void ft_finish(t_container *container, t_philo *philo)
{
    int i;

    i = -1;
    while (++i < container->nbr_philo)
        pthread_join(philo[i].thread_proocess, NULL);
    i = -1;
    while (++i < container->nbr_philo)
        pthread_mutex_destroy(&(container->mutex_forks[i]));
    pthread_mutex_destroy(&(container->writing_lock));
    pthread_mutex_destroy(&(container->meal_check));
    pthread_mutex_destroy(&(container->meal_lock));
    ft_dealloc(philo);
}