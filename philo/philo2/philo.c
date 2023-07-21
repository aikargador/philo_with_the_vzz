#include "pp.h"

int	eat_em_all(t_philo *philo)
{
	t_val	beninging_time;
	t_val	current_time;

	timeStamp(philo, YEL, 0, EAT);
	gettimeofday(&beninging_time, NULL);
	// while (++i <= philo->table->info.tT_EAT)
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		gettimeofday(&current_time, NULL);
		if ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			 - (beninging_time.tv_sec * 1000 + beninging_time.tv_usec / 1000)
					>= philo->table->info.tT_EAT)
						break ;
		// usleep(100);
	}
	return (0);
}

// int	eat_em_all(t_philo *philo)//testr
// {
// 	int	i;

// 	i = 0;
// 	timeStamp(philo, EAT);
// 	while (i <= philo->table->info.tT_EAT)
// 	{
// 		pthread_mutex_lock(&philo->table->printm);
// 		printf("\ne   -  ");
// 		if (death_reaper(philo))
// 			return (1);
// 		usleep(100 * 1000);
// 		i += 100;
// 	}
// 	return (0);
// }

// int	odd_philosophers(t_philo *philo)
// {
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (!philo->the_hand->cuffed)
// 		{
// 			pthread_mutex_lock(&philo->the_hand->cuffs);
// 			philo->the_hand->cuffed = philo->id;
// 			// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuffs);
// 			timeStamp(philo, MAG, 0, FRK);
// 			break ;
// 		}
// 	}
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (!philo->the_neighbours_hand->cuffed)
// 		{
// 			pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 			philo->the_neighbours_hand->cuffed = philo->id;
// 			// pthread_mutex_unlock(&philo->the_hand->chk_cuffs);
// 			timeStamp(philo, MAG, 0, FRK);
// 			break ;
// 		}
// 		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	// timeStamp(philo, "finished eating!\n");
// 	gettimeofday(&philo->initTime, NULL);
// 	philo->the_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	return (0);
// }
int	odd_philosophers(t_philo *philo)
{
	t_val	big_shit;
	t_val	smol_shit;
	int		fuiyoo;

	while (1) {
		fuiyoo = 1;
		gettimeofday(&big_shit, NULL);
		if (philo->the_neighbours_hand->cuffed == philo->id && philo->the_hand->cuffed == philo->id)
			break ;
		while (1)
		{
			gettimeofday(&smol_shit, NULL);
			if (((smol_shit.tv_sec * 1000 + smol_shit.tv_usec / 1000) \
				- (big_shit.tv_sec * 1000 + big_shit.tv_usec / 1000)) % 1000 > 100)
			{
				pthread_mutex_unlock(&philo->the_hand->cuffs);
				fuiyoo = 0;
			}
			if (death_reaper(philo))
				return (1);
			if (!philo->the_hand->cuffed)
			{
				pthread_mutex_lock(&philo->the_hand->cuffs);
				philo->the_hand->cuffed = philo->id;
				// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuffs);
				timeStamp(philo, MAG, 0, FRK);
				break ;
			}
		}
		while (1 && fuiyoo)
		{
			gettimeofday(&smol_shit, NULL);
			if (((smol_shit.tv_sec * 1000 + smol_shit.tv_usec / 1000) \
				- (big_shit.tv_sec * 1000 + big_shit.tv_usec / 1000)) % 1000 > 100)
			{
				pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
				fuiyoo = 0;
			}
			if (death_reaper(philo))
				return (1);
			if (!philo->the_neighbours_hand->cuffed)
			{
				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
				philo->the_neighbours_hand->cuffed = philo->id;
				// pthread_mutex_unlock(&philo->the_hand->chk_cuffs);
				timeStamp(philo, MAG, 0, FRK);
				break ;
			}
		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
		}
	}
	if (eat_em_all(philo))
		return (1);
	// timeStamp(philo, "finished eating!\n");
	gettimeofday(&philo->initTime, NULL);
	philo->the_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	philo->the_neighbours_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (0);
}

// int	even_philosophers(t_philo *philo)
// {
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (!philo->the_neighbours_hand->cuffed)
// 		{
// 			pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 			philo->the_neighbours_hand->cuffed = philo->id;
// 			// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuffs);
// 			timeStamp(philo, MAG, 0, FRK);
// 			break ;
// 		}
// 		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
// 	}
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (!philo->the_hand->cuffed)
// 		{
// 			pthread_mutex_lock(&philo->the_hand->cuffs);
// 			philo->the_hand->cuffed = philo->id;
// 			// pthread_mutex_unlock(&philo->the_hand->chk_cuffs);
// 			timeStamp(philo, MAG, 0, FRK);
// 			break ;
// 		}
// 		// printf("philo no. %d waiting for fork %d\n", philo, philo->the_hand->hand);
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	// timeStamp(philo, "finished eating!\n");
// 	gettimeofday(&philo->initTime, NULL);
// 	philo->the_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	return (0);
// }
int	even_philosophers(t_philo *philo)
{
	t_val	big_shit;
	t_val	smol_shit;
	int		fuiyoo;

	while (1) {
		fuiyoo = 1;
		gettimeofday(&big_shit, NULL);
		if (philo->the_neighbours_hand->cuffed == philo->id && philo->the_hand->cuffed == philo->id)
			break ;
		while (1)
		{
			gettimeofday(&smol_shit, NULL);
			if (((smol_shit.tv_sec * 1000 + smol_shit.tv_usec / 1000) \
				- (big_shit.tv_sec * 1000 + big_shit.tv_usec / 1000)) % 1000 > 100)
			{
				pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
				fuiyoo = 0;
			}
			if (death_reaper(philo))
				return (1);
			if (!philo->the_neighbours_hand->cuffed)
			{
				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
				philo->the_neighbours_hand->cuffed = philo->id;
				// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuffs);
				timeStamp(philo, MAG, 0, FRK);
				break ;
			}
			// printf("philo no. %d waiting for fork %d\n", philo, philo->the_neighbours_hand->hand);
		}
		while (1 && fuiyoo)
		{
			gettimeofday(&smol_shit, NULL);
			if (((smol_shit.tv_sec * 1000 + smol_shit.tv_usec / 1000) \
				- (big_shit.tv_sec * 1000 + big_shit.tv_usec / 1000)) % 1000 > 100)
			{
				pthread_mutex_unlock(&philo->the_hand->cuffs);
				fuiyoo = 0;
			}
			if (death_reaper(philo))
				return (1);
			if (!philo->the_hand->cuffed)
			{
				pthread_mutex_lock(&philo->the_hand->cuffs);
				philo->the_hand->cuffed = philo->id;
				// pthread_mutex_unlock(&philo->the_hand->chk_cuffs);
				timeStamp(philo, MAG, 0, FRK);
				break ;
			}
			// printf("philo no. %d waiting for fork %d\n", philo, philo->the_hand->hand);
		}
	}
	if (eat_em_all(philo))
		return (1);
	// timeStamp(philo, "finished eating!\n");
	gettimeofday(&philo->initTime, NULL);
	philo->the_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	philo->the_neighbours_hand->cuffed = 0;
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (0);
}

int	think_about_life_with_arms(t_philo *philo)
{
	timeStamp(philo, GRN, 0, THK);
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		// pthread_mutex_lock(&philo->the_hand->chk_cuffs);
		// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuffs);
		if (!philo->the_hand->cuffed && !philo->the_neighbours_hand->cuffed)//chk this, probable data race here
			return (0);
	}
	return (0);
}

// int	ft_dream(t_philo *philo)// first put them to sleep at 1ms
int	dream_about_life_with_arms(t_philo *philo)
{
	t_val	beninging_time;
	t_val	current_time;

	timeStamp(philo, CYN, 0, SLP);
	gettimeofday(&beninging_time, NULL);
	// while (++i <= philo->table->info.tT_sleep)
	while (1)
	{
		if (death_reaper(philo))
			return (1);
		gettimeofday(&current_time, NULL);
		if ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			 - (beninging_time.tv_sec * 1000 + beninging_time.tv_usec / 1000)
					>= philo->table->info.tT_sleep)
						break ;
		// usleep(100);
	}
	return (0);
}
// int	dream_about_life_with_arms(t_philo *philo) //testr
// {
// 	int	i;

// 	i = 0;
// 	timeStamp(philo, SLP);
// 	while (i <= philo->table->info.tT_sleep)
// 	{
// 		pthread_mutex_lock(&philo->table->printm);
// 		printf("\ns   ");
// 		if (death_reaper(philo))
// 			return (1);
// 		usleep(100 * 1000);
// 		i += 100;
// 	}
// 	return (0);
// }
// 310 200 100