/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poopy0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:52:55 by aikram            #+#    #+#             */
/*   Updated: 2023/03/26 15:21:59 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// successfully generated a working poopy
// race condition eliminated and result is literally chef's kiss!
// used two thrawds in this case!
// next part blanning to print some of the gettimeofday shit, where we will be using froopy and poopy

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
	// struct timeval	poopy;
	// struct timeval	froopy;
}	t_pp;

typedef struct	s_ea {
	t_pp	*pps;
}	t_ea;

void	*thrawd(void *agu) {
	int		i;
	t_pp	*sloopy = (t_pp *)agu;

	i = 0;
	pthread_mutex_lock(&sloopy->mutes[i]);
	pthread_mutex_lock(&sloopy->mutes[i + 1]);
	printf("id no. -> %d\n", sloopy->id);
	// usleep(10000);
	// sleep(1);
	for (int i = 0; i < 100000000; i++)
		undies++;
	printf("finished sleepy peepy\n");
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
	printf("undies -> %d\n", undies);
}


// PATH=$PATH:/Applications/Visual Studio Code.app/Contents/Resources/app/bin