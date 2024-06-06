#include "philo.h"

void ft_set_dead(t_container *container, int value)
{
    pthread_mutex_lock(&container->meal_lock);
    container->all_dead = value;
    pthread_mutex_unlock(&container->meal_lock);
}

int ft_get_dead(t_container *container)
{
    int value;
    
    pthread_mutex_lock(&container->meal_lock);
    value = container->all_dead;
    pthread_mutex_unlock(&container->meal_lock);
    return (value);
}