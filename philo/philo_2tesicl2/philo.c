#include "pp.h"

int	time_out(t_val init_time, int time_out)
{
	t_val	current_time;
	long	res;

	res = 0;
	gettimeofday(&current_time, NULL);
	if (!time_out)
		time_out = 50;
	res = ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
		- (init_time.tv_sec * 1000 + init_time.tv_usec / 1000));
	if (res < 0)
		res += 1000;
	if (res >= time_out)
		return (1);
	return (0);
}

int	eat_em_all(t_philo *philo)
{
	t_val	beninging_time;

	timeStamp(philo, YEL, 0, EAT);
	gettimeofday(&beninging_time, NULL);
	while (69)
	{
		if (death_reaper(philo))
			return (1);
		if (time_out(beninging_time, philo->table->info.tT_EAT))
			break ;
	}
	return (0);
}

int	dream_about_life_with_arms(t_philo *philo)
{
	t_val	beninging_time;

	timeStamp(philo, CYN, 0, SLP);
	gettimeofday(&beninging_time, NULL);
	while (69)
	{
		if (death_reaper(philo))
			return (1);
		if (time_out(beninging_time, philo->table->info.tT_EAT))
			break ;
	}
	return (0);
}

int	odd_philosophers(t_philo *philo)
{
	// t_val	iniTime;

	// while (1)
	// {
		// gettimeofday(&iniTime, NULL);
		// if (philo->clr == 2)
		// 	break ;
		if (death_reaper(philo))//
			return (1);
		pthread_mutex_lock(&philo->the_hand->cuffs);
		timeStamp(philo, MAG, 0, FRK);
		// philo->clr = 1;
		// while (1)
		// {
			if (death_reaper(philo)) {
				pthread_mutex_unlock(&philo->the_hand->cuffs);
				return (1);
			}
			// if (time_out(iniTime, 0))//
			// {
			// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
			// 	philo->clr = 0;
			// 	break ;
			// }
			timeStamp(philo, MAG, 0, FRK);
			pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
			// philo->clr = 2;
			// break ;
		// }
	// }
	if (eat_em_all(philo))
		return (1);
	gettimeofday(&philo->init_ime, NULL);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (0);
}

int	even_philosophers(t_philo *philo)
{
	// t_val	iniTime;

	// while (1)
	// {
		// gettimeofday(&iniTime, NULL);
		// if (philo->clr == 2)
		// 	break ;
		if (death_reaper(philo))
			return (1);
		pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
		// philo->clr = 1;
		timeStamp(philo, MAG, 0, FRK);
		// while (1)
		// {
			if (death_reaper(philo)) {
				pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
				return (1);
			}
			// if (time_out(iniTime, 0))//
			// {
				// pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
			// 	philo->clr = 0;
			// 	break ;
			// }
			timeStamp(philo, MAG, 0, FRK);
			pthread_mutex_lock(&philo->the_hand->cuffs);
			// philo->clr = 2;
			// break ;
		// }
	// }
	if (eat_em_all(philo))
		return (1);
	gettimeofday(&philo->init_ime, NULL);
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	return (0);
}

// int	odd_philosophers(t_philo *philo) /// V2
// {
// 	t_val	iniTime;

// 	while (1)
// 	{
// 		gettimeofday(&iniTime, NULL);
// 		if (philo->clr == 2)
// 			break ;
// 		while (1)
// 		{
// 			if (death_reaper(philo))//
// 				return (1);
// 			pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 			if (!philo->the_hand->cuffed)
// 			{
// 				pthread_mutex_lock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = philo->id;
// 				philo->clr = 1;
// 			}
// 			pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 		}
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 			if (time_out(iniTime, 0))//
// 			{
// 				pthread_mutex_unlock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = 0;
// 				philo->clr = 0;
// 			}
// 			pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 			if (death_reaper(philo))
// 				return (1);
// 			pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 			if (!philo->the_neighbours_hand->cuffed)//
// 			{
// 				timeStamp(philo, MAG, 0, FRK);
// 				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = philo->id;
// 				timeStamp(philo, MAG, 0, FRK);
// 				philo->clr = 2;
// 			}
// 			pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 		}
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	gettimeofday(&philo->init_ime, NULL);
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 	philo->the_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 	return (0);
// }

// int	even_philosophers(t_philo *philo)
// {
// 	t_val	iniTime;

// 	while (1)
// 	{
// 		gettimeofday(&iniTime, NULL);
// 		if (philo->clr == 2)
// 			break ;
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			usleep(10);
// 			pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 			if (!philo->the_neighbours_hand->cuffed)//
// 			{
// 				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = philo->id;
// 				philo->clr = 1;
// 			}
// 			pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 		}
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 			if (time_out(iniTime, 0))//
// 			{
// 				pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = 0;
// 				philo->clr = 0;
// 			}
// 			pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 			if (!philo->clr)
// 				break ;
// 			pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 			if (!philo->the_hand->cuffed)//
// 			{
// 				timeStamp(philo, MAG, 0, FRK);
// 				pthread_mutex_lock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = philo->id;
// 				timeStamp(philo, MAG, 0, FRK);
// 				philo->clr = 2;
// 			}
// 			pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 		}
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	gettimeofday(&philo->init_ime, NULL);
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 	philo->the_hand->cuffed = 0;
// 	pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 	return (0);
// }

// int	time_out(t_val init_time, int time_out)
// {
// 	t_val	current_time;
// 	long	res;

// 	res = 0;
// 	gettimeofday(&current_time, NULL);
// 	if (!time_out)
// 		time_out = 50;
// 	res = ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
// 		- (init_time.tv_sec * 1000 + init_time.tv_usec / 1000));
// 	if (res < 0)
// 		res += 1000;
// 	if (res >= time_out)
// 		return (1);
// 	return (0);
// }

// int	eat_em_all(t_philo *philo)
// {
// 	t_val	beninging_time;

// 	timeStamp(philo, YEL, 0, EAT);
// 	gettimeofday(&beninging_time, NULL);
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (time_out(beninging_time, philo->table->info.tT_EAT))
// 			break ;
// 	}
// 	return (0);
// }

// // int	think_about_life_with_arms(t_philo *philo) // V VATEVER
// // {
// // 	timeStamp(philo, GRN, 0, THK);
// // 	// while (1)
// // 	// {
// // 	// 	if (death_reaper(philo))
// // 	// 		return (1);
// // 	// 	// pthread_mutex_lock(&philo->the_hand->chk_cuffs);
// // 	// 	// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuffs);
// // 	// 	if (!philo->the_hand->cuffed && !philo->the_neighbours_hand->cuffed)//chk this, probable data race here
// // 	// 		return (0);
// // 	// }
// // 	return (0);
// // }

// int	dream_about_life_with_arms(t_philo *philo)
// {
// 	t_val	beninging_time;

// 	timeStamp(philo, CYN, 0, SLP);
// 	gettimeofday(&beninging_time, NULL);
// 	while (1)
// 	{
// 		if (death_reaper(philo))
// 			return (1);
// 		if (time_out(beninging_time, philo->table->info.tT_EAT))
// 			break ;
// 	}
// 	return (0);
// }

// int	odd_philosophers(t_philo *philo)
// {
// 	t_val	iniTime;

// 	while (1)
// 	{
// 		gettimeofday(&iniTime, NULL);
// 		if (philo->the_neighbours_hand->cuffed == philo->id && philo->the_hand->cuffed == philo->id)
// 			break ;
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			// pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 			if (!philo->the_hand->cuffed)
// 			{
// 				pthread_mutex_lock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = philo->id;
// 				// pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 				timeStamp(philo, MAG, 0, FRK);
// 				break ;
// 			}
// 		}
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			if (time_out(iniTime, 0))
// 			{
// 				pthread_mutex_unlock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = 0;
// 				break ;
// 			}
// 			if (death_reaper(philo))
// 				return (1);
// 			// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 			if (!philo->the_neighbours_hand->cuffed)
// 			{
// 				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = philo->id;
// 				// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 				timeStamp(philo, MAG, 0, FRK);
// 				break ;
// 			}
// 		}
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	// timeStamp(philo, "finished eating!\n");
// 	gettimeofday(&philo->init_ime, NULL);
// 	// pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	philo->the_hand->cuffed = 0;
// 	// pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 	// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 	return (0);
// }

// int	even_philosophers(t_philo *philo)
// {
// 	t_val	iniTime;

// 	while (1)
// 	{
// 		gettimeofday(&iniTime, NULL);
// 		if (philo->the_neighbours_hand->cuffed == philo->id && philo->the_hand->cuffed == philo->id)
// 			break ;
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			usleep(10);
// 			if (!philo->the_neighbours_hand->cuffed)
// 			{
// 				// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 				pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = philo->id;
// 				// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 				timeStamp(philo, MAG, 0, FRK);
// 				break ;
// 			}
// 		}
// 		while (1)
// 		{
// 			if (death_reaper(philo))
// 				return (1);
// 			if (time_out(iniTime, 0))
// 			{
// 				pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 				philo->the_neighbours_hand->cuffed = 0;
// 				break ;
// 			}
// 			if (!philo->the_hand->cuffed)
// 			{
// 				// pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 				pthread_mutex_lock(&philo->the_hand->cuffs);
// 				philo->the_hand->cuffed = philo->id;
// 				// pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 				// pthread_mutex_unlock(&philo->the_hand->chk_cuffs);
// 				timeStamp(philo, MAG, 0, FRK);
// 				break ;
// 			}
// 		}
// 	}
// 	if (eat_em_all(philo))
// 		return (1);
// 	gettimeofday(&philo->init_ime, NULL);
// 	// pthread_mutex_lock(&philo->the_neighbours_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
// 	philo->the_neighbours_hand->cuffed = 0;
// 	// pthread_mutex_unlock(&philo->the_neighbours_hand->chk_cuff);
// 	// pthread_mutex_lock(&philo->the_hand->chk_cuff);
// 	pthread_mutex_unlock(&philo->the_hand->cuffs);
// 	philo->the_hand->cuffed = 0;
// 	// pthread_mutex_unlock(&philo->the_hand->chk_cuff);
// 	return (0);
// }
