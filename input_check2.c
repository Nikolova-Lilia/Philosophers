#include "philo.h"

bool ft_strlen(const char *str) // 👻
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    if (i > 10)
        return (false);

    return (true);
}

bool ft_int_check(long long nbr) // 👻
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

long long ft_atol(const char *str) // 👻
{
    long long result;
    int sign;

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
