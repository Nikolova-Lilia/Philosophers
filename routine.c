#include "philo.h"

void ft_eat(t_philo *philo)
{
    if (philo->philo_id % 2 == 0)
    {
        pthread_mutex_lock(&(philo->container->mutex_forks[philo->left_fork]));
        ft_print(philo->container, philo->philo_id, "has taken a fork");
        pthread_mutex_lock(&(philo->container->mutex_forks[philo->right_fork]));
        ft_print(philo->container, philo->philo_id, "has taken a fork");
    }
    else if (philo->philo_id % 2 != 0)
    {
        pthread_mutex_lock(&(philo->container->mutex_forks[philo->right_fork]));
        ft_print(philo->container, philo->philo_id, "has taken a fork");
        pthread_mutex_lock(&(philo->container->mutex_forks[philo->left_fork]));
        ft_print(philo->container, philo->philo_id, "has taken a fork");
    }
    pthread_mutex_lock(&(philo->container->meal_check));
    ft_print(philo->container, philo->philo_id, "is eating");
    philo->timestamp_last_meal = ft_get_time();
    pthread_mutex_unlock(&(philo->container->meal_check));
    ft_smart_sleep(philo->container->time_to_eat, philo->container);
    pthread_mutex_lock(&philo->container->meal_lock);
    (philo->x_ate)++;
    pthread_mutex_unlock(&philo->container->meal_lock);
    pthread_mutex_unlock(&(philo->container->mutex_forks[philo->left_fork]));
    pthread_mutex_unlock(&(philo->container->mutex_forks[philo->right_fork]));
}

void ft_smart_sleep(unsigned long long int time, t_container *container)
{
    unsigned long long int i;

    i = ft_get_time();
    while (!(ft_get_dead(container)))
    {
        if (ft_time_difference(i, ft_get_time()) >= time)
            break;
        usleep(50);
    }
}

void *ft_routine(void *void_philo)
{
    int i;
    t_philo *philo;

    i = 0;
    philo = (t_philo *)void_philo;
    if (philo->philo_id % 2 == 0)
        usleep(philo->container->time_to_eat / 2);
    while (!(ft_get_dead(philo->container)))
    {
        ft_eat(philo);
        if (philo->x_ate == philo->container->nbr_meals)
            break;
        ft_print(philo->container, philo->philo_id, "is sleeping");
        ft_smart_sleep(philo->container->time_to_sleep, philo->container);
        ft_print(philo->container, philo->philo_id, "is thinking");
        i++;
    }
    return (NULL);
}