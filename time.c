#include "philo.h"

unsigned long long int ft_get_time(void) // 👻
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((unsigned long long int)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

unsigned long long int ft_time_difference(unsigned long long int past, unsigned long long int pres)
{
    return (pres - past);
}