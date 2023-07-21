/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poopy1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:52:55 by aikram            #+#    #+#             */
/*   Updated: 2023/03/26 15:57:57 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//literally poopy0 + gettimeofday bruh, bruh bruh bruh bruh
// its poopy and froopy lessssss gooooooooooooooooo!!!!
// like its literally poopy and froopy, poooooopyyy froooooooopyyy!!


#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>// gettimeofday
#include <unistd.h> // u
#include <stdlib.h>
#include <limits.h>

int undies = 0;

typedef struct	s_pp {
	int				id;
	int				*forky;
	pthread_t		tid;
	pthread_mutex_t	*mutes;
	struct timeval	poopy;
	struct timeval	froopy;
}	t_pp;

typedef struct	s_ea {
	t_pp	*pps;
}	t_ea;

void	*thrawd(void *agu) {
	int		i;
	t_pp	*sloopy = (t_pp *)agu;

	i = 0;
	// printf("id no. -> %d\n", sloopy->id);
	gettimeofday(&sloopy->poopy, NULL);
	if (pthread_mutex_lock(&sloopy->mutes[i]))
	{
		usleep(100000);
		printf("thrawd no. %d, sleepy poopy %ld\n", sloopy->id, (long)sloopy->poopy.tv_usec / 1000);
	}
	if (sloopy->id)
		i = -1;
	pthread_mutex_lock(&sloopy->mutes[i + 1]);
	{
		usleep(100000);
		printf("thrawd no. %d, sleepy poopy %ld\n", sloopy->id, (long)sloopy->poopy.tv_usec / 1000);
	}
	// printf("just poopy %ld\n", (long)sloopy->poopy.tv_sec);
	printf("thrawd no. %d, milli poopy %ld\n", sloopy->id, (long)sloopy->poopy.tv_usec / 1000);
	// printf("micro poopy %ld\n", (long)sloopy->poopy.tv_usec);
	usleep(100000);
	gettimeofday(&sloopy->froopy, NULL);
	// printf("just froopy %ld\n", (long)sloopy->froopy.tv_sec);
	printf("thrawd no. %d, milli froopy %ld\n", sloopy->id, (long)sloopy->froopy.tv_usec / 1000);
	// printf("micro froopy %ld\n", (long)sloopy->froopy.tv_usec);
	// sleep(1);
	// for (int i = 0; i < 100000000; i++)
	// 	undies++;
	// long	not_long = (sloopy->froopy.tv_sec - sloopy->poopy.tv_sec) * 1000
	// 	+ (sloopy->froopy.tv_usec - sloopy->poopy.tv_usec) / 1000;
	// printf("finished sleepy peepy %ld\n", not_long);
	pthread_mutex_unlock(&sloopy->mutes[i]);
	pthread_mutex_unlock(&sloopy->mutes[i + 1]);
	return NULL;
}

int	main(int c, char **v) {
	t_ea			tea;
	pthread_mutex_t	*morty;
	
	tea.pps = calloc(2, sizeof(t_pp));
	morty = calloc(2, sizeof(pthread_mutex_t));
	for (int i = 0; i < 2; i++) {
		tea.pps[i].id = i;
		tea.pps[i].forky = &i;
		pthread_mutex_init(&morty[i], NULL);
	} for (int i = 0; i < 2; i++) {
		tea.pps[i].mutes = morty;
		pthread_create(&tea.pps[i].tid, NULL, thrawd, &tea.pps[i]);
	} for (int i = 0; i < 2; i++)
		pthread_join(tea.pps[i].tid, NULL);
	for (int i = 0; i < 2; i++)
		pthread_mutex_destroy(&morty[i]);
	// printf("undies -> %d\n", undies);
}