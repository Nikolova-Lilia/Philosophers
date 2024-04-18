#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

int ft_check_argc(char *str)
{
    while(*str)
    {
        if (!((*str >= 48 && *str <= 57) || *str == 45))
            return (1);
        str++;
    }
    return (0);
}
int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '\0')
		return (0);
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}
int main(int argc, char *argv[])
{
    if (argc > 6 || argc < 6)
    {
        printf("Number of arguments doesn't match what's needed.\n");
        printf("Please enter: <nbr of philos> <time to die> <time to eat>");
        printf(" <time to sleep> <nbr of times philos must eat>\n");
        return (1);
    }
    int i;
    i = 1;
    while (i <= argc-1)
    {
        if (ft_check_argc(argv[i]) == 1)
        {
            printf("Error. Please enter digits\n");
            exit(1);
        }
        i++;
    }
    int nbr_ph = ft_atoi(argv[1]);
    if (nbr_ph < 0)
    {
        printf("Error. Number must be positive\n");
        exit(1);
    }
    int times_ph_die = ft_atoi(argv[2]);
    if (times_ph_die < 0)
    {
        printf("Error. Number must be positive\n");
        exit(1);
    }
    int times_ph_eat = ft_atoi(argv[3]);
    if (times_ph_eat < 0)
    {
        printf("Error. Number must be positive\n");
        exit(1);
    }
    int time_ph_sleep = ft_atoi(argv[4]);
    if (time_ph_sleep < 0)
    {
        printf("Error. Number must be positive\n");
        exit(1);
    }
    int nbr_times_ph_eat = ft_atoi(argv[5]);


}