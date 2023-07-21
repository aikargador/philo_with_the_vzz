/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:23:05 by aikram            #+#    #+#             */
/*   Updated: 2023/05/04 20:01:10 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_H
# define PP_H

# include <unistd.h>//idk
# include <stdio.h>//printf
# include <string.h>// idk
# include <stdlib.h>// malloc free exit success and failiure
# include <pthread.h>// anything related to threads
# include <stdbool.h>// bool
# include <limits.h>// intmax
# include <errno.h>
# include <sys/time.h>

# define FRK "has taken a fork\n"
# define EAT "is eating\n"
# define SLP "is sleeping\n"
# define THK "is thinking\n"
# define DED "died\n"


typedef struct	s_able t_able;

typedef struct s_info
{
	int	pp_amt;
	int	tT_DIE;
	int	tT_EAT;
	int	tT_sleep;
	int	tPpMEat;
	
} t_info;

typedef struct	s_hands {
	int				hand; //fork /// deprecated!
	int				cuffed;
	pthread_mutex_t	cuffs;
	struct s_hands	*next;
}	t_hands;

typedef struct	s_philo {
	int				id;
	pthread_t		tid;
	// t_info			*info;// make it point to s_ea as a whole!
	t_able			*table;
	t_hands			*the_hand;
	t_hands			*the_neighbours_hand;
	// int				*forky;
	struct timeval	initTime;
	struct timeval	curntTime;
}	t_philo;

struct	s_able {
	// t_hands	**gig_hands; // fix this -> make it single!
	t_hands	*hands; // fix this -> make it single!
	t_info	info;
	t_philo	*pps;
	pthread_mutex_t	printm;
};

/* main.c */
int		death_reaper(t_philo *drPhil);
void	timeStamp(t_philo *philo, char *msg);

/* philo.c */
int		eat_em_all(t_philo *philo);
int		odd_philosophers(t_philo *philo);
int		even_philosophers(t_philo *philo);
int		dream_about_life_with_arms(t_philo *philo);
int		think_about_life_with_arms(t_philo *philo);

/* uts0.c */
void	ft_cautious_free(void **pointer);
void	ft_very_cautious_free(void ***pointer);
bool	chk_numeric(char *str);
bool	valid_arg(int c, char **v);
void	initInfo(int c, char **v, t_info *info);

/* uts1.c */
bool	ret_putstr_fd(char *s, char *inc, int fd, bool free);
bool	ft_putstr_fd(char *s, int fd);
int		ft_atopi(const char *str);
void	ft_lstadd_back(t_hands **lst, t_hands *new);
t_hands	*ft_lstlast(t_hands *lst);

/* cuffs_ltd.c */
t_hands	*cuffs_manufacturer(void);
t_hands	*cuffs_init(int amt_of_prosthetic_arms);

/* dish_washer.c */
void	ultimate_destructor(t_hands *hands);
void	*mission_failed_retreat(t_hands *hands, int l);

/* temporary */
void	pre_testr(t_hands *hands, int amt);
void	testr(t_philo *philo);

// bool	valid_arg(int c, char **v);
// void	initInfo(int c, char **v, t_info *info);

// t_hands	**cuffs_init(int amt_of_prosthetic_arms);
// t_hands	*chk_if_fits(int i, t_hands *hands);
// void	free_em_shits(t_hands **poopy);// to destroy em mutexexs
// // void	find_hands(t_pp *pps, t_ea *tea);

// int		ft_atopi(const char *str);
// // void	*chicken_biryani(t_philo *pho);
// // void	create_philos(t_philo *pho, t_info *vals);
// void	fill_struct(int c, char *v[], t_info *vals);

// /* utils */
// bool	chk_numeric(char *str);
// bool	ft_putstr_fd(char *s, int fd);
// bool	ret_putstr_fd(char *s, char *inc, int fd, bool free);

// void	*ft_calloc(size_t count, size_t size);


#endif