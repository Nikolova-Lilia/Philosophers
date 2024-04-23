#include "philo.h"

void ft_print_instructions(void)
{
    printf("Number of arguments doesn't match what's needed.\n");
    printf("Please enter: <nbr of philos> <time to die> <time to eat>");
    printf(" <time to sleep> <nbr of times philos must eat(optional)>\n");
    printf("Example: ./philo 5 800 200 200 5\n");
    printf("Example: ./philo 5 800 200 200\n");
}