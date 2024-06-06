#include "philo.h"

int main(int argc, char **argv)
{
    t_container container;
    t_philo *philo;

    if (argc > 6 || argc < 5) // proverka za broq
        return(ft_error_instuctions());
    if (ft_input_check(argc, argv) == false) // proverka za dali e vqrno vuvedenoto
        return(ft_error_instuctions());
    if (ft_init(&container, &philo, argc, argv) == false) // zapisvane na dannite v konteinera
        return (WRONG_INPUT);
    if (ft_thread_start(&container, philo) == false)
    {
        printf("Error creating threads\n");
        return (THREAD_ERROR);
    }
    return (0);
}