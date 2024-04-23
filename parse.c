#include "philo.h"

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

}
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
static long    ft_atol(const char *str)
{
	long	result;

    str = ft_check_argv(str);
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
    if (ft_argv_check(argc, argv) == false)
        return(false);

    container->philo_nbr = ft_atol(argv[1]);
}