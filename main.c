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
    t_container container;

    if (argc > 6 || argc < 5)
    {
        ft_print_instructions();
        return (WRONG_INPUT);
    }
    else
    {
        // 1)errors checking, is the input correct?!
        //filling container data
        if (ft_parse_input(&container, argc, argv) == false)
            return(WRONG_INPUT);

        // 2)mallocing philos & forks
        data_init(&container);

        // 3)actual simulation
        ft_dinner(&container);

        // 4) deallocation ->philos full || 1 philo died
        ft_clean(&container);
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