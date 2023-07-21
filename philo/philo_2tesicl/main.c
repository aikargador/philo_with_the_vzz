/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:06:56 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 00:18:13 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

int	death_reaper(t_philo *dr_phil)
{
	long	prev_val;
	long	curnt_val;
	long	result;

	gettimeofday(&dr_phil->curnt_ime, NULL);
	curnt_val = (dr_phil->curnt_ime.tv_sec * 1000 + \
	dr_phil->curnt_ime.tv_usec / 1000) % dr_phil->table->info.fig;
	prev_val = (dr_phil->reset_ime.tv_sec * 1000 + \
	dr_phil->reset_ime.tv_usec / 1000) % dr_phil->table->info.fig;
	result = curnt_val - prev_val;
	if (result < 0)
		result += dr_phil->table->info.fig;
	if (result > dr_phil->table->info.tt_die)
	{
		time_stamp(dr_phil, RED, 1, DED);
		pthread_mutex_lock(&dr_phil->table->death_control);
		dr_phil->table->death_certificate = 69;
		pthread_mutex_unlock(&dr_phil->table->death_control);
		return (1);
	}
	return (0);
}

int	time_stamp(t_philo *philo, char *clr, int ded, char *msg)
{
	if (look_out_for_the_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->table->printm);
	if (ded)
	{
		if (printer(philo, clr, ded, msg))
			return (1);
	}
	else
	{
		if (printer(philo, clr, ded, msg))
			return (1);
	}
	pthread_mutex_unlock(&philo->table->printm);
	return (0);
}

void	*simulation(void *args)
{
	t_philo			*philo;
	// struct timeval	resetime;
	int				i;

	i = 1;
	philo = (t_philo *)args;
	gettimeofday(&philo->reset_ime, NULL);
	// philo->reset_ime = (resetime.tv_sec * 1000) + (resetime.tv_usec / 1000);
	// pthread_mutex_lock(&philo->table->printm);
	// philo->table->green_light++;
	// pthread_mutex_unlock(&philo->table->printm);
	// while (69)
	// {
	// 	pthread_mutex_lock(&philo->table->printm);
	// 	if (philo->table->green_light != philo->table->info.pp_amt) {
	// 		pthread_mutex_unlock(&philo->table->printm);
	// 		break ;
	// 	}
	// 	pthread_mutex_unlock(&philo->table->printm);
	// }
	// pthread_mutex_lock(&philo->table->printm);
	// printf("%d reset time -> %ld\n", philo->id, ((philo->reset_ime.tv_sec * 1000) + (philo->reset_ime.tv_sec / 1000)) % 10000);
	// pthread_mutex_unlock(&philo->table->printm);
	if (philo->table->info.pp_amt == 1)
	{
		lone_wolf(philo);
		return ((void *)0);
	}
	if (odd_favortism(philo))
		return ((void *)1);
	while (1)
	{
		if (bon_appetit(philo))
			return ((void *)1);
		if (philo->table->info.tpp_meat)
			if (++i == philo->table->info.tpp_meat)
				break ;
	}
	return ((void *)0);
}

void	restaurant_with_limited_utensils(t_able *table)
{
	// struct timeval	initime;
	t_hands			*tmp;
	int				i;

	i = -1;
	tmp = table->hands;
	gettimeofday(&table->init_ime, NULL);
	// table->init_ime = (initime.tv_sec * 1000) + (initime.tv_usec / 1000);
	// printf("init time -> %ld\n", table->init_ime % 10000);
	table->green_light = 0;
	while (++i < table->info.pp_amt)
	{
		table->pps[i].id = i + 1;
		table->pps[i].the_hand = tmp;
		tmp = tmp->next;
		table->pps[i].the_neighbours_hand = tmp;
		table->pps[i].table = table;
		if (table->pps[i].id % 2) {
			pthread_mutex_lock(&table->pps[i].the_hand->cuffs);
			time_stamp(&table->pps[i], GRN, 0, THK);
			time_stamp(&table->pps[i], MAG, 0, FRK);
		}
		pthread_create(&table->pps[i].birth_certificate, NULL, simulation,
			&table->pps[i]);
	}
	i = -1;
	while (++i < table->info.pp_amt)
		pthread_join(table->pps[i].birth_certificate, NULL);
	return ;
}

int	main(int c, char **v)
{
	t_able	table;

	if (!valid_arg(c, v))
		return (1);
	init_info(c, v, &table.info);
	artificial_intelligence(&table.info);
	table.pps = calloc(table.info.pp_amt, sizeof(t_philo));
	if (!table.pps)
		return (1);
	table.hands = cuffs_init(table.info.pp_amt);
	if (!table.hands)
		return (terminate_philos(&table));
	table.death_certificate = 0;
	protection_init(&table);
	restaurant_with_limited_utensils(&table);
	pthread_mutex_destroy(&table.printm);
	pthread_mutex_destroy(&table.death_control);
	ultimate_destructor(table.hands);
	terminate_philos(&table);
	return (0);
}
