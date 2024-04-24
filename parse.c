#include "philo.h"

static bool ft_digit_check(const char *str)
{
    int flag;

    flag = 0;
    while(*str)
    {
        if (*str >= 48 && *str <= 57)
            str++;
        else if(*str == 45)
        {
            flag++;
            str++;
            if (flag > 1)
                return (false);
        }
        else
            return(false);
    }
    return (true);
}

static bool ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    if (i > 10)
        return(false);

    return(true);
}

static bool ft_argv_check(int argc, char *argv[])
{
    int i;

    i = 1;
    while(i <= argc)
    {
        if (ft_digit_check(argv[i]) == false)
        {
            printf("Error. Please enter digits\n");
            return(WRONG_INPUT);
        }
        i++;
    }
    i = 1;
    while (i <= argc)
    {
        if (ft_strlen(argv[i]) == false)
        {
            printf("Number too long. Please enter nbr smaller than MAX_INT\n");
            return(WRONG_INPUT);
        }
        i++;
    }
    return (true);
}

static bool ft_int_check(int nbr)
{
    if (nbr > INT_MAX)
        return (false);
    if (nbr < 0)
        return (false);
    return (true);
}

static long    ft_atol(const char *str)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

/*
    Step1: Checking input & converting to int

    name    nbr_philo   time_to_die    time_to_eat    time_to_sleep  nbr_meals
    ./philo     5           800             200             200         [5]
    argv[0]   argv[1]    argv[2]          argv[3]         argv[4]      argv[5]

    *checking if they are digits
    *checking if they are less than INT_MAX
    *checking if they are positive nbrs
*/

bool    ft_parse_input(t_container *container, int argc, char *argv[])
{
    int result_check;
    int i;

    if (ft_argv_check(argc, argv) == false)
        return(false);
    i = 1;
    while (i <= argc)
    {
        result_check = ft_atol(argv[i]);
        if (ft_int_check(result_check) == false)
            return (false);
        i++;
    }
    container->philo_nbr = ft_atol(argv[1]);
    container->time_to_die = ft_atol(argv[2]);
    container->time_to_eat = ft_atol(argv[3]);
    container->time_to_sleep = ft_atol(argv[4]);
    if (argc == 6)
        container->nbr_total_meals = ft_atol(argv[5]);
    return (true);
}