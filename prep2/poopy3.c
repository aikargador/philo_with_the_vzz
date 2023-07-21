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
int ppz = 4;

typedef struct	s_hands {
	int				hand;
	pthread_mutex_t	cuffs;
	struct s_hands	*next;
}	t_hands;

typedef struct	s_pp {
	int				id;
	int				*forky;
	pthread_t		tid;
	pthread_mutex_t	*potty;
	t_hands	**gig_hands;
	struct timeval	poopy;
	struct timeval	froopy;
}	t_pp;

typedef struct	s_ea {
	t_pp	*pps;
}	t_ea;

t_hands	**cuffs_init(int amt_of_prosthetic_arms);
t_hands	*chk_if_fits(int i, t_hands *hands);
void	free_em_shits(t_hands **poopy);// to destroy em mutexexs

void	*thrawd(void *agu) {
	int		i;
	t_pp	*sloopy;
	t_hands	*the_hand;
	t_hands	*the_neighbours_hand;

	sloopy = (t_pp *)agu;
	i = sloopy->id;
	printf("ids => %d\n", i);
	printf("sloopy's poopy %p\n", *sloopy[sloopy->id].gig_hands);
	t_hands *tmp;
	int k = 0;
	tmp = *sloopy[sloopy->id].gig_hands;
	// printf("first node %p\n", *handy);
	printf("first node %p\n", tmp);
	while (tmp)
	{
		if (k > 10)
			break ;
		printf("%p\n", tmp->next);
		printf("%d\n", tmp->hand);
		tmp = tmp->next;
		k++;
	}
	pthread_mutex_lock(&*sloopy->potty);
	the_hand = chk_if_fits(i, *sloopy[sloopy->id].gig_hands);
	pthread_mutex_unlock(&*sloopy->potty);
	the_neighbours_hand = the_hand->next;
	pthread_mutex_lock(&the_hand->cuffs);// to see the effect of the mutex lock comment the mutex lock and unlocks and test it
	pthread_mutex_lock(&the_neighbours_hand->cuffs);
	printf("hello\n");
	// sleep(1);
	pthread_mutex_unlock(&the_hand->cuffs);
	pthread_mutex_unlock(&the_neighbours_hand->cuffs);
	return (NULL);
}

int	main(int c, char **v) {
	t_ea			tea;
	pthread_mutex_t	morty;
	t_hands			**handy;
	// pthread			potty;
	
	tea.pps = calloc(ppz, sizeof(t_pp));
	handy = cuffs_init(ppz);
	pthread_mutex_init(&morty, NULL);
	// t_hands *tmp;
	// int k = 0;
	// tmp = *handy;
	// printf("first node %p\n", *handy);
	// printf("first node %p\n", tmp);
	// while (tmp)
	// {
	// 	if (k > 10)
	// 		break ;
	// 	printf("%p\n", tmp->next);
	// 	printf("%d\n", tmp->hand);
	// 	tmp = tmp->next;
	// 	k++;
	// }
	for (int i = 0; i < ppz; i++) {
		tea.pps[i].id = i + 1;
		// tea.id = i + 1;
		tea.pps[i].gig_hands = handy;
		tea.pps[i].potty = &morty;
		// printf("ids => %d\n", tea.pps[i].id);
		pthread_create(&tea.pps[i].tid, NULL, thrawd, &tea.pps[i]);
	} for (int i = 0; i < ppz; i++)
		pthread_join(tea.pps[i].tid, NULL);
	free_em_shits(handy);
	pthread_mutex_destroy(&morty);
	// for (int i = 0; i < ppz; i++)
		// pthread_mutex_destroy(&morty[i]);
	
	// printf("undies -> %d\n", undies);
}

































void	free_em_shits(t_hands **poopy)
{
	t_hands	*tmp;
	t_hands	*plmp;
	int		i;

	i = -1;
	tmp = *poopy;
	while (++i < tmp->hand)
	{
		plmp = tmp->next;
		pthread_mutex_destroy(&tmp->cuffs);
		free(tmp);
		tmp = plmp;
	}
	free(poopy);
}

void	ultimate_destructor(t_hands **poopy)
{
	t_hands	*tmp;
	int	i;

	i = -1;
	tmp = *poopy;
	while (++i < tmp->hand)
	{
		pthread_mutex_destroy(&tmp->cuffs);
		tmp = tmp->next;
	}
	free_em_shits(poopy);
}

t_hands	*cuffs_manufacturer()
{
	t_hands	*hnd;

	hnd = calloc(1, sizeof(t_hands));
	if (!hnd)
		return (NULL);
	hnd->hand = 1;
	hnd->next = NULL;
	// write(1, "hello\n", 6);
	return (hnd);
}

t_hands	**cuffs_init(int amt_of_prosthetic_arms)
{//make an inner alloc failiure for the prev alloc to remove them
	t_hands	**idk;
	t_hands	*tmp;
	t_hands	*tmpy;
	int	i;

	i = 0;
	idk = calloc(1, sizeof(t_hands *));
	if (!idk)
		return (NULL);
	tmp = cuffs_manufacturer();
	if(!tmp)
		return (NULL);
	if (pthread_mutex_init(&tmp->cuffs, NULL)) // have to do the inner alloc failiure for this too
		return (NULL);
	*idk = tmp;
	// write(1, "hello\n", 6);
	while (++i < amt_of_prosthetic_arms)
	{
		tmp->next = cuffs_manufacturer();
		if(!tmp->next)
			return (NULL);
		tmp = tmp->next;
		tmp->hand = i + 1;
		if (pthread_mutex_init(&tmp->cuffs, NULL)) // have to do the inner alloc failiure for this too
			return (NULL);
	}
	// write(1, "hello\n", 6);
	tmp->next = *idk;
	return (idk);
}







t_hands	*chk_if_fits(int i, t_hands *hands)
{
	while (i != hands->hand) {
		printf("i = %d\n", i);
		printf("hands.hand = %d\n", hands->hand);
		printf("hands.next.hand = %d\n", hands->next->hand);
		hands = hands->next;
	}
	return (hands);
}

