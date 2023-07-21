/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:53:22 by aikram            #+#    #+#             */
/*   Updated: 2023/05/11 22:05:38 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

bool	valid_arg_utl(char *str)
{
	if (!chk_numeric(str))
		return (false);
	if (!str[0])
	{
		write(1, "\e[38;5;202mphilosophers: cricket chirps\e[0m", 43);
		usleep(200000);
		write(1, ".", 1);
		usleep(200000);
		write(1, ".", 1);
		usleep(200000);
		write(1, ".\n", 2);
		return (false);
	}
	return (true);
}

int	look_out_for_the_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_control);
	if (philo->table->death_certificate)
	{
		pthread_mutex_unlock(&philo->table->death_control);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_control);
	return (0);
}

void	artificial_intelligence(t_info *info)
{
	int	n[6];

	n[0] = info->tt_die;
	n[1] = info->tt_eat;
	n[2] = info->tt_sleep;
	n[3] = -1;
	n[5] = 0;
	info->fig = 1;
	while (++n[3] < 3)
	{
		n[4] = 0;
		while (n[n[3]])
		{
			n[n[3]] /= 10;
			n[4]++;
		}
		if (n[5] < n[4])
			n[5] = n[4];
	}
	info->dig = n[5];
	while (n[5])
	{
		info->fig *= 10;
		n[5]--;
	}
}

int	printer(t_philo *philo, char *clr, int ded, char *msg)
{
	gettimeofday(&philo->curnt_ime, NULL);
	if (look_out_for_the_dead(philo))
	{
		pthread_mutex_unlock(&philo->table->printm);
		return (1);
	}
	if (ded)
	{
		// printf("%d init time = %0*ld\n", philo->id, philo->table->info.dig, (philo->reset_ime.tv_sec * 1000 + \
		//  % philo->table->info.fig);
		// printf("%d current time = %0*ld\n", philo->id, philo->table->info.dig, ((philo->curnt_ime.tv_sec * 1000 \
		// 	+ philo->curnt_ime.tv_usec / 1000) % philo->table->info.fig));
		// printf("reset time -> %ld\n", philo->reset_ime % 10000);
		// printf("init time -> %ld\n", philo->table->init_ime % 10000);
		printf("%s%0*ld \e[9m\e[2m%d\e[29m\e[22m %s", clr, \
			philo->table->info.dig, (long)(((philo->curnt_ime.tv_sec * 1000 + philo->curnt_ime.tv_usec / 1000) \
			- (philo->table->init_ime.tv_sec * 1000 + \
			philo->table->init_ime.tv_usec / 1000)) % philo->table->info.fig), philo->id, msg);
	}
	else
	{
		// printf("%d init time = %0*ld\n", philo->id, philo->table->info.dig, (philo->reset_ime.tv_sec * 1000 + philo->reset_ime.tv_usec / 1000) % philo->table->info.fig);
		// printf("%d current time = %0*ld\n", philo->id, philo->table->info.dig, ((philo->curnt_ime.tv_sec * 1000 \
			// + philo->curnt_ime.tv_usec / 1000) % philo->table->info.fig));
		// printf("reset time -> %ld\n", philo->reset_ime % 10000);
		// printf("init time -> %ld\n", philo->table->init_ime % 10000);
		printf("%s%0*ld %d %s", clr, philo->table->info.dig, \
			(long)(((philo->curnt_ime.tv_sec * 1000 + philo->curnt_ime.tv_usec / 1000) \
			- (philo->table->init_ime.tv_sec * 1000 + \
			philo->table->init_ime.tv_usec / 1000)) % philo->table->info.fig), philo->id, msg);
	}
	return (0);
}
