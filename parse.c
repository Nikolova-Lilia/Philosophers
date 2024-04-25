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
    while(i < argc)
    {
        if (ft_digit_check(argv[i]) == false)
        {
            printf("Error. Please enter digits\n");
            return(WRONG_INPUT);
        }
        i++;
    }
    i = 1;
    while (i < argc)
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

static bool ft_int_check(long long nbr)
{
    if (nbr > INT_MAX)
    {
        printf("Number too long. Please enter nbr smaller than MAX_INT\n");
        return (false);
    }
    if (nbr < 0)
    {
        printf("Error. Negative numbers not allowed.\n");
        return (false);
    }
    return (true);
}

static long long    ft_atol(const char *str)
{
	long long	result;
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

                        micro secnds   micro secnds   micro secnds
    name    nbr_philo   time_to_die    time_to_eat    time_to_sleep  nbr_meals
    ./philo     5           800             200             200         [5]
    argv[0]   argv[1]    argv[2]          argv[3]         argv[4]      argv[5]

    *checking if they are digits
    *checking if they are less than INT_MAX
    *checking if they are positive nbrs

    *last step will be to convert timestamps - currently everything is 
    in mili seconds, usleep() needs macro seconds
    example:    1micro s = 1e3 macro s
                2.5 micro s = 2.5 * 1e3(macro s) = 2500 macro s 
*/

bool    ft_parse_input(t_container *container, int argc, char *argv[])
{
    long long result_check;
    int i;

    if (ft_argv_check(argc, argv) == false)
        return(false);
    i = 1;
    while (i < argc)
    {
        result_check = ft_atol(argv[i]);
        if (ft_int_check(result_check) == false)
            return (false);
        i++;
    }
    container->philo_nbr = ft_atol(argv[1]);
    if (container->philo_nbr == 0)
    {
        printf("Simularotion doesn't start with zero philosophers.\n");
        return(false);
    }
    container->time_to_die = ft_atol(argv[2]) * 1e3;
    container->time_to_eat = ft_atol(argv[3]) * 1e3;
    container->time_to_sleep = ft_atol(argv[4]) * 1e3;
    if (container->time_to_die < 60000 || container->time_to_eat < 60000 || container->time_to_sleep < 60000)
    {
        printf("Timestemps must be major than 60 ms\n");
        return (false);
    }
    if (argc == 6)
        container->nbr_total_meals = ft_atol(argv[5]);
    else
        container->nbr_total_meals = -1; //Why?
    return (true);
}