/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:23:05 by aikram            #+#    #+#             */
/*   Updated: 2023/03/23 16:36:39 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_H
# define PP_H

#include <unistd.h>//idk
#include <stdio.h>//printf
#include <string.h>// idk
#include <stdlib.h>// malloc free exit success and failiure
#include <pthread.h>// anything related to threads
#include <stdbool.h>// bool
#include <limits.h>// intmax
#include <sys/time.h>// usleep

typedef struct s_info
{
	int	pp_amt;
	int	tT_DIE;
	int	tT_EAT;
	int	tT_sleep;
	int	tPpMEat;
	
} t_info;

typedef struct s_pps
{
	pthread_t		pp;
	int				right_hand;
	pthread_mutex_t	hand_cuffs;
	struct s_pps*	nxt;
}	t_pps;

typedef struct	s_tbl
{
	t_pps			**pps;
	t_info			*info;
	int				*right_hand;
	pthread_mutex_t	*hand_cuffs;
	int				chicken_biryani;

}	t_tbl;


int		ft_atopi(const char *str);
void	*chicken_biryani(t_philo *pho);
void	create_philos(t_philo *pho, t_info *vals);
void	fill_struct(int c, char *v[], t_info *vals);

/* utils */
bool	chk_numeric(char *str);
bool	ft_putstr_fd(char *s, int fd);
bool	ret_putstr_fd(char *s, char *inc, int fd, bool free);

void	*ft_calloc(size_t count, size_t size);


#endif