/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:25:21 by aikram            #+#    #+#             */
/*   Updated: 2023/04/09 18:17:09 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

/* indtead of fork i use the philosopher's right hand! so a philosopher sits with his right hand 
 on the able, and when eating he needs his hand as well as his friends hand assissting him to yeat
 the fewd is chicken_biryani! */
 
/*◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died◦*/

/* number_of_philosophers		time_to_die		time_to_eat		time_to_sleep		[number_of_times_each_philosopher_must_eat] */

bool	valid_arg(int c, char **v)
{
	printf("no. of args -> %d\n", c);
	if (c < 5)
		return (ft_putstr_fd("philosophers: min 4 args!\n", 2));
	if (c > 6)
		return (ft_putstr_fd("philosophers: max 5 args!\n", 2));
	v++;
	while (*v)
	{
		if (!chk_numeric(*v))
			return (false);
		v++;
	}
	return (true);
}

void	initInfo(int c, char **v, t_info *info)
{
	info->pp_amt = ft_atopi(v[1]);
	info->tT_DIE = ft_atopi(v[2]);
	info->tT_EAT = ft_atopi(v[3]);
	info->tT_sleep = ft_atopi(v[4]);
	if (c == 6)
		info->tPpMEat = ft_atopi(v[5]);
	else
		info->tPpMEat = 0;
}

void	*fewd(void *arg)
{

}

bool	ppInit(t_tbl *tbl)
{
	t_pps	*tmp;
	int	i;

	i = -1;
	tbl->pps = ft_calloc(tbl->info->pp_amt, sizeof(t_pps *));
	if (!tbl->pps)
		return (false);
	tmp = *tbl->pps;
	while (++i < tbl->info->pp_amt)
	{
		tmp = pthread_create(tmp->pp, NULL, fewd, );
		tmp = tmp->nxt;
	}
	tmp->nxt = *tbl->pps;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_tbl	tbl;

	tbl.info = &info;
	tbl.pps = ft_calloc(1, sizeof(t_pps *));
	if (!valid_arg(argc, argv))
		return (1);
	initInfo(argc, argv, &info);
	if (!ppInit(&tbl))
		return (1);
}