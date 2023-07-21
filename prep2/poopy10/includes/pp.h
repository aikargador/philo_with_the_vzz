/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:23:05 by aikram            #+#    #+#             */
/*   Updated: 2023/04/28 18:15:55 by aikram           ###   ########.fr       */
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
#include <errno.h>
#include <sys/time.h>

typedef struct s_info
{
	int	pp_amt;
	int	tT_DIE;
	int	tT_EAT;
	int	tT_sleep;
	int	tPpMEat;
	
} t_info;

// typedef struct s_pps
// {
// 	pthread_t		pp;
// 	int				right_hand;
// 	pthread_mutex_t	hand_cuffs;
// 	struct s_pps*	nxt;
// }	t_pps;

// typedef struct	s_tbl
// {
// 	t_pps			**pps;
// 	t_info			*info;
// 	int				*right_hand;
// 	pthread_mutex_t	*hand_cuffs;
// 	int				chicken_biryani;

// }	t_tbl;

typedef struct	s_hands {
	int				hand; //fork /// deprecated!
	int				cuffed;
	pthread_mutex_t	cuffs;
	struct s_hands	*next;
}	t_hands;

typedef struct	s_pp {
	t_info			*info;// make it point to s_ea as a whole!
	int				id;
	int				*forky;
	pthread_t		tid;
	t_hands			*the_hand;
	t_hands			*the_neighbours_hand;
	struct timeval	poopy;
	struct timeval	froopy;
}	t_pp;

typedef struct	s_ea {
	t_hands	**gig_hands; // fix this -> make it single!
	t_info	*info;
	t_pp	*pps;
}	t_ea;

bool	valid_arg(int c, char **v);
void	initInfo(int c, char **v, t_info *info);

t_hands	**cuffs_init(int amt_of_prosthetic_arms);
t_hands	*chk_if_fits(int i, t_hands *hands);
void	free_em_shits(t_hands **poopy);// to destroy em mutexexs
void	find_hands(t_pp *pps, t_ea *tea);

int		ft_atopi(const char *str);
// void	*chicken_biryani(t_philo *pho);
// void	create_philos(t_philo *pho, t_info *vals);
void	fill_struct(int c, char *v[], t_info *vals);

/* utils */
bool	chk_numeric(char *str);
bool	ft_putstr_fd(char *s, int fd);
bool	ret_putstr_fd(char *s, char *inc, int fd, bool free);

void	*ft_calloc(size_t count, size_t size);


#endif