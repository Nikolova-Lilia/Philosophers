#include "philo.h"

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
        //data_init(&container);

        // 3)actual simulation
        //ft_dinner(&container);

        // 4) deallocation ->philos full || 1 philo died
        //ft_clean(&container);
    }
}