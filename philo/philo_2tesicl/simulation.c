/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:00:37 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 01:17:23 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

int	bon_appetit(t_philo *philo)
{
	if (death_reaper(philo))
		return (1);
	if (look_out_for_the_dead(philo))
		return (1);
	if (time_stamp(philo, GRN, 0, THK))
		return (1);
	if (philo->id % 2)
	{
		if (odd_philosophers(philo))
			return (1);
	}
	else
	{
		if (even_philosophers(philo))
			return (1);
	}
	if (dream_about_life_with_arms(philo))
		return (1);
	return (0);
}

int	first_run(t_philo *philo)
{
	t_val	current_time;
	if (look_out_for_the_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
		return (free_hands(philo));
	if (eat_em_all(philo))
		return (free_hands(philo));
	gettimeofday(&philo->reset_ime, NULL);
	gettimeofday(&current_time, NULL);
	printf("%d curnt time at %ld\n", philo->id, (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) % 1000);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (0);
}

int	odd_favortism(t_philo *philo)
{
	t_val	current_time;
	if (death_reaper(philo))
		return (1);
	if (look_out_for_the_dead(philo))
		return (1);
	if (philo->id % 2)
	{
		if (first_run(philo))
			return (1);
	}
	else
	{
		if (time_stamp(philo, GRN, 0, THK))
			return (1);
		if (even_philosophers(philo))
			return (1);
	}
	// printf("%d init time at %ld\n", philo->id, (philo->table->init_ime.tv_sec * 1000 + philo->table->init_ime.tv_usec / 1000) % 1000);
	// printf("%d reset time at %ld\n", philo->id, (philo->reset_ime.tv_sec * 1000 + philo->reset_ime.tv_usec / 1000) % 1000);
	long	res;

	gettimeofday(&current_time, NULL);
	printf("%d curnt time at %ld\n", philo->id, (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) % 1000);
	res = ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			- (philo->table->init_ime.tv_sec * 1000 + philo->table->init_ime.tv_usec / 1000));
	printf("m pp %d, res => %ld\n", philo->id, res);
	if (dream_about_life_with_arms(philo))
		return (1);
	return (0);
}

int	lone_wolf(t_philo *philo)
{
	if (death_reaper(philo))
		return (0);
	if (time_stamp(philo, GRN, 0, THK))
		return (0);
	pthread_mutex_lock(&philo->the_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
	{
		pthread_mutex_unlock(&philo->the_hand->cuffs);
		return (0);
	}
	while (69)
		if (death_reaper(philo))
			return (0);
	return (0);
}
