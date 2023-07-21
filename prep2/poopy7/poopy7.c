//literally poopy0 + gettimeofday bruh, bruh bruh bruh bruh
// its poopy and froopy lessssss gooooooooooooooooo!!!!
// like its literally poopy and froopy, poooooopyyy froooooooopyyy!!


// difference between poopy6 and poopy7 is the different approach to hold a thread if both are not free, that is
// to loop it until the other one leaves!
#include "pp.h"

int undies = 0;
int ppz = 5;

// typedef struct	s_hands {
// 	int				hand;
// 	int				cuffed;
// 	pthread_mutex_t	cuffs;
// 	struct s_hands	*next;
// }	t_hands;

// typedef struct	s_pp {
// 	int				id;
// 	int				*forky;
// 	pthread_t		tid;
// 	t_hands			*the_hand;
// 	t_hands			*the_neighbours_hand;
// 	struct timeval	poopy;
// 	struct timeval	froopy;
// }	t_pp;

// typedef struct	s_ea {
// 	t_hands	**gig_hands;
// 	t_pp	*pps;
// }	t_ea;

t_hands	**cuffs_init(int amt_of_prosthetic_arms);
t_hands	*chk_if_fits(int i, t_hands *hands);
void	free_em_shits(t_hands **poopy);// to destroy em mutexexs
void	find_hands(t_pp *pps, t_ea *tea);

// void	__tmp2__chk_for_prosthetic_arm(t_pp *sloopy)
// {
// 	// if (/* sloopy->the_neighbours_hand->cuffed ||  */sloopy->the_hand->cuffed)
// 	// 	printf("thread no. %d -> waiting s\n", sloopy->id);
// 	// while (sloopy->the_neighbours_hand->cuffed)
// 	// 	printf("a\n");
// 	if (sloopy->the_hand->cuffed)
// 		printf("thread no. %d -> waiting a\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_hand->cuffs);
// 	sloopy->the_hand->cuffed = 1;
// 	printf("thread no. %d picked prosthetic arm no. %da\n", sloopy->id, sloopy->the_hand->hand);
// 	if (sloopy->the_neighbours_hand->cuffed)
// 		printf("thread no. %d -> waiting b\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_neighbours_hand->cuffs);// to see the effect of the mutex lock comment the mutex lock and unlocks and test it
// 	sloopy->the_neighbours_hand->cuffed = 1;
// 	printf("thread no. %d picked prosthetic arm no. %db\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// 	printf("hello\n");
// 	sleep(1);
// 	pthread_mutex_unlock(&sloopy->the_hand->cuffs);
// 		sloopy->the_hand->cuffed = 0;
// 		printf("thread no. %d realeased prosthetic arm no. %d\n", sloopy->id, sloopy->the_hand->hand);
// 	pthread_mutex_unlock(&sloopy->the_neighbours_hand->cuffs);
// 		sloopy->the_neighbours_hand->cuffed = 0;
// 		printf("thread no. %d released prosthetic arm no. %d\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// }

// void	__tmp2__chk_for_neighbours_prosthetic_arm(t_pp *sloopy)
// {
// 	// if (/* sloopy->the_hand->cuffed ||  */sloopy->the_neighbours_hand->cuffed)
// 	// 	printf("thread no. %d -> waiting b\n", sloopy->id);
// 	// while (sloopy->the_hand->cuffed)
// 	// 	printf("a\n");
// 	if (sloopy->the_neighbours_hand->cuffed)
// 		printf("thread no. %d -> waiting c\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_neighbours_hand->cuffs);
// 	sloopy->the_neighbours_hand->cuffed = 1;
// 	printf("thread no. %d picked prosthetic arm no. %dc\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// 	if (sloopy->the_hand->cuffed)
// 		printf("thread no. %d -> waiting d\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_hand->cuffs);// to see the effect of the mutex lock comment the mutex lock and unlocks and test it
// 	sloopy->the_hand->cuffed = 1;
// 	printf("thread no. %d picked prosthetic arm no. %dd\n", sloopy->id, sloopy->the_hand->hand);
// 	printf("hello\n");
// 	sleep(1);
// 	pthread_mutex_unlock(&sloopy->the_neighbours_hand->cuffs);
// 		sloopy->the_neighbours_hand->cuffed = 0;
// 		printf("thread no. %d released prosthetic arm no. %d\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// 	pthread_mutex_unlock(&sloopy->the_hand->cuffs);
// 		sloopy->the_hand->cuffed = 0;
// 		printf("thread no. %d realeased prosthetic arm no. %d\n", sloopy->id, sloopy->the_hand->hand);
// }


void __tmp2__chk_for_prosthetic_arm(t_pp *sloopy)
{
	while (1) {
		if (!sloopy->the_neighbours_hand->cuffed) {
			pthread_mutex_lock(&sloopy->the_neighbours_hand->cuffs);
			sloopy->the_neighbours_hand->cuffed = 1;
			printf("thread no. %d picked prosthetic arm no. %db\n", sloopy->id, sloopy->the_neighbours_hand->hand);
			break;
		}
	}

	while (1) {
		if (!sloopy->the_hand->cuffed) {
			pthread_mutex_lock(&sloopy->the_hand->cuffs);
			sloopy->the_hand->cuffed = 1;
			printf("thread no. %d picked prosthetic arm no. %da\n", sloopy->id, sloopy->the_hand->hand);
			break;
		}
	}

	printf("hello\n");
	sleep(1);

	pthread_mutex_unlock(&sloopy->the_hand->cuffs);
	sloopy->the_hand->cuffed = 0;
	printf("thread no. %d realeased prosthetic arm no. %d\n", sloopy->id, sloopy->the_hand->hand);

	pthread_mutex_unlock(&sloopy->the_neighbours_hand->cuffs);
	sloopy->the_neighbours_hand->cuffed = 0;
	printf("thread no. %d released prosthetic arm no. %d\n", sloopy->id, sloopy->the_neighbours_hand->hand);
}

void __tmp2__chk_for_neighbours_prosthetic_arm(t_pp *sloopy)
{
	while (1) {
		if (!sloopy->the_hand->cuffed) {
			pthread_mutex_lock(&sloopy->the_hand->cuffs);
			sloopy->the_hand->cuffed = 1;
			printf("thread no. %d picked prosthetic arm no. %dd\n", sloopy->id, sloopy->the_hand->hand);
			break;
		}
	}

	while (1) {
		if (!sloopy->the_neighbours_hand->cuffed) {
			pthread_mutex_lock(&sloopy->the_neighbours_hand->cuffs);
			sloopy->the_neighbours_hand->cuffed = 1;
			printf("thread no. %d picked prosthetic arm no. %dc\n", sloopy->id, sloopy->the_neighbours_hand->hand);
			break;
		}
	}

	printf("hello\n");
	sleep(1);

	pthread_mutex_unlock(&sloopy->the_neighbours_hand->cuffs);
	sloopy->the_neighbours_hand->cuffed = 0;
	printf("thread no. %d released prosthetic arm no. %d\n", sloopy->id, sloopy->the_neighbours_hand->hand);

	pthread_mutex_unlock(&sloopy->the_hand->cuffs);
	sloopy->the_hand->cuffed = 0;
	printf("thread no. %d realeased prosthetic arm no. %d\n", sloopy->id, sloopy->the_hand->hand);
}




// void	chk_for_negihbours_prosthetic_arm(t_pp *sloopy)
// {
// 	if (sloopy->the_hand->cuffed || sloopy->the_neighbours_hand->cuffed)
// 		printf("thread no. %d -> waiting\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_neighbours_hand->cuffs);
// 		sloopy->the_neighbours_hand->cuffed = 1;
// 		printf("thread no. %d picked prosthetic arm no. %dc\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// 	if (sloopy->the_hand->cuffed)
// 		printf("thread no. %d -> waiting\n", sloopy->id);
// 	pthread_mutex_lock(&sloopy->the_hand->cuffs);// to see the effect of the mutex lock comment the mutex lock and unlocks and test it
// 		sloopy->the_hand->cuffed = 1;
// 		printf("thread no. %d picked prosthetic arm no. %dd\n", sloopy->id, sloopy->the_hand->hand);
// 	printf("hello\n");
// 	sleep(1);
// 	if (!pthread_mutex_unlock(&sloopy->the_neighbours_hand->cuffs))
// 		printf("thread no. %d released prosthetic arm no. %d\n", sloopy->id, sloopy->the_neighbours_hand->hand);
// 	if (!pthread_mutex_unlock(&sloopy->the_hand->cuffs))
// 		printf("thread no. %d realeased prosthetic arm no. %d\n", sloopy->id, sloopy->the_hand->hand);
// }

void	think_about_life_with_hands(t_pp *ppp)
{
	struct timeval	shit;
	gettimeofday(&shit, NULL);
	printf("%ld %d is thinking\n", (long)shit.tv_usec / 1000, ppp->id);
	while (1) {
		if (!ppp->the_hand->cuffed && !ppp->the_neighbours_hand->cuffed)
			return ;
	}
}

void	*thrawd(void *agu) {
	t_pp	*sloopy;

	sloopy = (t_pp *)agu;
	// printf("ids => %d\n", i);
	// printf("sloopy's poopy %p\n", *sloopy[sloopy->id].gig_hands);
	while (1)
	{
		think_about_life_with_hands(sloopy);
		if (sloopy->id % 2)
			__tmp2__chk_for_prosthetic_arm(sloopy);
	//\\//\\//\\//\\/c_f_p_a
		else {
			usleep(2);
			__tmp2__chk_for_neighbours_prosthetic_arm(sloopy);
		}
	}
	return (NULL);
}

int	main(int c, char **v) {
	t_ea			tea;
	t_info			inf;

	if (!valid_arg(c, v))
		return (1);
	initInfo(c, v, &inf);
	tea.info = &inf;
	tea.pps = calloc(inf.pp_amt, sizeof(t_pp));
	tea.gig_hands = cuffs_init(inf.pp_amt);
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
	for (int i = 0; i < inf.pp_amt; i++) {
		// tea.id = i + 1;
		// printf("ids => %d\n", tea.pps[i].id);
		tea.pps[i].id = i + 1;
		tea.pps[i].info = &inf;
		find_hands(&tea.pps[i], &tea);
		pthread_create(&tea.pps[i].tid, NULL, thrawd, &tea.pps[i]);
	} for (int i = 0; i < ppz; i++)
		pthread_join(tea.pps[i].tid, NULL);
	free_em_shits(tea.gig_hands);
	// for (int i = 0; i < ppz; i++)
		// pthread_mutex_destroy(&morty[i]);
	
	// printf("undies -> %d\n", undies);
}










// bool	ppInit(t_tbl *tbl)
// {
// 	t_pps	*tmp;
// 	int	i;

// 	i = -1;
// 	tbl->pps = ft_calloc(tbl->info->pp_amt, sizeof(t_pps *));
// 	if (!tbl->pps)
// 		return (false);
// 	tmp = *tbl->pps;
// 	while (++i < tbl->info->pp_amt)
// 	{
// 		tmp = pthread_create(tmp->pp, NULL, fewd, );
// 		tmp = tmp->nxt;
// 	}
// 	tmp->nxt = *tbl->pps;
// }

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

// int	ft_atopi(const char *str)
// {
// 	unsigned long	res;

// 	res = 0;
// 	while (*str == 32 || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '+')
// 		str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		res = res * 10 + *(str)++ - '0';
// 		if (res > INT_MAX)
// 			return (-1);
// 	}
// 	if (res > 2147483647)
// 		return (-1);
// 	return (res);
// }

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
















void	find_hands(t_pp *pps, t_ea *tea)
{
	t_hands	*tmp;

	tmp = *tea->gig_hands;
	while (pps->id != tmp->hand)
		tmp = tmp->next;
	pps->the_hand = tmp;
	pps->the_neighbours_hand = tmp->next;
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
	hnd->cuffed = 0;
	hnd->hand = 1;
	hnd->next = NULL;
	// write(1, "hello\n", 6);
	return (hnd);
}

t_hands	**cuffs_init(int amt_of_prosthetic_arms)
{//make an inner alloc failiure for the prev alloc to remove them
	t_hands	**idk;
	t_hands	*tmp;
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

