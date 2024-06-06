#include "philo.h"

int ft_input_check(int argc, char *argv[]) // 👻
{
    long long result_check;
    int i;

    if (ft_argv_check(argc, argv) == false)
        return (false);
    i = 1;
    while (i < argc)
    {
        result_check = ft_atol(argv[i]);
        if (ft_int_check(result_check) == false)
            return (false);
        i++;
    }
    return (true);
}

bool ft_argv_check(int argc, char *argv[]) // 👻
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_digit_check(argv[i]) == false)
        {
            printf("Error. Please enter digits\n");
            return (WRONG_INPUT);
        }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        if (ft_strlen(argv[i]) == false)
        {
            printf("Number too long. Please enter nbr smaller than MAX_INT\n");
            return (WRONG_INPUT);
        }
        i++;
    }
    return (true);
}

bool ft_digit_check(const char *str) // 👻
{
    int flag;

    flag = 0;
    while (*str)
    {
        if (*str >= 48 && *str <= 57)
            str++;
        else if (*str == 45)
        {
            flag++;
            str++;
            if (flag > 1)
                return (false);
        }
        else
            return (false);
    }
    return (true);
}