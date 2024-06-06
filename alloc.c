#include "philo.h"

bool ft_alloc(t_container *container, t_philo **philo) // 👻
{
    *philo = malloc(sizeof(t_philo) * container->nbr_philo);
    if (!philo)
    {
        printf("Error while allocating philosophers\n");
        return (false);
    }
    container->mutex_forks = malloc(sizeof(pthread_mutex_t) * container->nbr_philo);
    if (!container->mutex_forks)
    {
        printf("Error while allocating forks\n");
        return (false);
    }
    return (true);
}

int ft_dealloc(t_philo *philo) // 👻
{
    void *forks_clean;
    void *data_clean;

    forks_clean = (void*)philo->container->mutex_forks;
    data_clean = (void *)philo;
    free(forks_clean);
    free(data_clean);
    return (0);
}