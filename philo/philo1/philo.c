#include "pp.h"

int	eat_em_all(t_philo *philo)
{
	int	i;

	i = 0;
	timeStamp(philo, EAT);
	while (++i >= philo->table->info.tT_EAT)
	{
		if (death_reaper(philo))
			return (1);
		usleep(1 * 1000);
	}
	return (0);
}

int	odd_philosophers(t_philo *philo)
{
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		if (!philo->the_hand->cuffed)
		{
			pthread_mutex_lock(&philo->the_hand->cuffs);
			philo->the_hand->cuffed = 1;
			timeStamp(philo, FRK);
			break ;
		}
	}
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		if (!philo->the_neighbours_hand->cuffed)
		{
			pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
			philo->the_neighbours_hand->cuffed = 1;
			timeStamp(philo, FRK);
			break ;
		}
		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
	}
	eat_em_all(philo);
	gettimeofday(&philo->initTime, NULL);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	philo->the_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	philo->the_neighbours_hand->cuffed = 0;
	return (0);
}

int	even_philosophers(t_philo *philo)
{
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		if (!philo->the_neighbours_hand->cuffed)
		{
			pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
			philo->the_neighbours_hand->cuffed = 1;
			timeStamp(philo, FRK);
			break ;
		}
		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
	}
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		if (!philo->the_hand->cuffed)
		{
			pthread_mutex_lock(&philo->the_hand->cuffs);
			philo->the_hand->cuffed = 1;
			timeStamp(philo, FRK);
			break ;
		}
		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_hand->hand);
	}
	eat_em_all(philo);
	gettimeofday(&philo->initTime, NULL);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	philo->the_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	philo->the_neighbours_hand->cuffed = 0;
	return (0);
}

int	think_about_life_with_arms(t_philo *philo)
{
	timeStamp(philo, THK);
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		if (!philo->the_hand->cuffed && !philo->the_neighbours_hand->cuffed)//chk this, probable data race here
			return (0);
	}
	return (0);
}

// int	ft_dream(t_philo *philo)// first put them to sleep at 1ms
int	dream_about_life_with_arms(t_philo *philo)
{
	int	i;

	i = 0;
	timeStamp(philo, SLP);
	while (++i < philo->table->info.tT_sleep)
	{
		if (death_reaper(philo))
			return (1);
		usleep(1000);
	}
	return (0);
}
// 310 200 100