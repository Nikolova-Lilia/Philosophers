#include "philo.h"

void ft_print_instructions(void) // 👻
{
    printf("Arguments doesn't match what's needed.\n");
    printf("Please enter: <nbr of philos> <time to die> <time to eat>");
    printf(" <time to sleep> <nbr of times philos must eat(optional)>\n");
    printf("All numbers must be positive values\n");
    printf("Example: ./philo 5 800 200 200 5\n");
    printf("Example: ./philo 5 800 200 200\n");
}

int ft_error_instuctions() // 👻
{
    ft_print_instructions();
    return (WRONG_INPUT);
}

void ft_print(t_container *container, int philo_id, char *str)
{
    pthread_mutex_lock(&(container->writing_lock));
    if (!(ft_get_dead(container)))
    {
        printf("%llu ", ft_get_time() - container->timestamp_one);
        printf("%d ", philo_id + 1);
        printf("%s\n", str);
    }
    pthread_mutex_unlock(&(container->writing_lock));
    return ;
}