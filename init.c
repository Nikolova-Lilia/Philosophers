#include "philo.h"

bool ft_init(t_container *container, t_philo **philo, int argc, char **argv) // 👻
{
    if (ft_init_container(container, argc, argv) == false)
        return (false);
    if (ft_alloc(container, philo) == false)
        return (false);
    if (ft_init_forks(container, *philo) == false)
        return (false);
    if (ft_init_philo(container, *philo) == false)
        return (false);
    return (true);
}

bool ft_init_container(t_container *container, int argc, char **argv) // 👻
{
    container->all_dead = 0;
    container->all_ate = 0;
    container->nbr_philo = (int)ft_atol(argv[1]);
    container->time_to_die = ft_atol(argv[2]);
    container->time_to_eat = ft_atol(argv[3]);
    container->time_to_sleep = ft_atol(argv[4]);
    if (argc == 6)
        container->nbr_meals = ft_atol(argv[5]);
    else
        container->nbr_meals = -1;
    if (container->nbr_philo < 2 || container->time_to_die == 0 || container->time_to_eat == 0 || container->time_to_sleep == 0 ||
        container->nbr_meals == 0)
    {
        printf("Invalid input values.\n");
        return (false);
    }
    return (true);
}
// updated
bool ft_init_forks(t_container *container, t_philo *philo) // 👻
{
    int i;

    i = container->nbr_philo;
    while (--i >= 0)
    { //&philo[i].mutex_lock_forks
        if (pthread_mutex_init(&container->mutex_forks[i], NULL))
        {
            printf("Error when initializing mutex\n");
            ft_dealloc(philo);
            return (false);
        }
    }
    if (ft_mutex_handle(container, philo) == false)
        return (false);
    return (true);
}
// new added
bool ft_mutex_handle(t_container *container, t_philo *philo)
{
    if (pthread_mutex_init(&container->writing_lock, NULL))
    {
        printf("Error when initializing mutex\n");
        ft_dealloc(philo);
        return (false);
    }
    if (pthread_mutex_init(&container->meal_check, NULL))
    {
        printf("Error when initializing mutex\n");
        ft_dealloc(philo);
        return (false);
    }
    if (pthread_mutex_init(&container->meal_lock, NULL))
    {
        printf("Error when initializing mutex\n");
        ft_dealloc(philo);
        return (false);
    }
    return (true);
}
bool ft_init_philo(t_container *container, t_philo *philo) // 👻
{
    int i;

    i = container->nbr_philo;
    while (--i >= 0)
    {
        philo[i].philo_id = i;
        philo[i].x_ate = 0; // da razbera
        philo[i].left_fork = i;
        philo[i].right_fork = (i + 1) % container->nbr_philo;
        philo[i].timestamp_last_meal = 0; // da razbera
        philo[i].container = container;
    }
    return (true);
}
