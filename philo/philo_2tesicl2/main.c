	/*

	---> current phil to sleep and tteat
	---> and phil's time to think which is
	related to the other philosopher's time to eat! and tteat
	---> first phil to eat! -> 	only ttsleep and tteat surr-pils time to eat!
	---> second phil ttthink and ttsleep and tteat

	------><>> valgrind --tool=helgrind ./philo 5 800 200 200
----> valgrind --tool=helgrind ./philo 4 310 200 100
	---> ttthink which is the surr-phils tteat		200
	---> tteat										200 / 400
	---> ttsleep									100
	
	---> ttthink which is the surr-phils tteat		200
	---> tteat										200 / 400
	---> ttsleep									200

	--> 🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯
	*/

#include "pp.h"

void	artificial_intelligence(t_info *info)
{
	int	n[6];

	n[0] = info->tT_DIE;
	n[1] = info->tT_EAT;
	n[2] = info->tT_sleep;
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

// void	pre_testr(t_hands *hands, int amt) // temporary
// {
// 	int i;

// 	i = 0;
// 	printf("\npre_testr\n\n");
// 	while (++i <= amt * 2)
// 	{
// 		printf("hand no. %d cuffed? %d\n", hands->hand, hands->cuffed);
// 		printf("neighbour's hand no. %d cuffed? %d\n", hands->next->hand, hands->next->cuffed);
// 		hands = hands->next;
// 	}
// 	printf("\n\n\n");
// }

// void	testr(t_philo *philo) // temporary
// {
// 	// int i;
// 	// i = 0;
// 	// while (++i < philo->table->info.pp_amt)
// 	// {
// 		printf("hand no. %d cuffed? %d\n", philo->the_hand->hand, philo->the_hand->cuffed);
// 		printf("neighbour's hand no. %d cuffed? %d\n", philo->the_neighbours_hand->hand, philo->the_neighbours_hand->cuffed);
// 	// }
// }

int	death_reaper(t_philo *drPhil)
{
	long	prevtime;
	long	curntime;
	long	result;

	gettimeofday(&drPhil->curnt_ime, NULL);
	curntime = (drPhil->curnt_ime.tv_sec * 1000 + \
	drPhil->curnt_ime.tv_usec / 1000) % drPhil->table->info.fig;
	prevtime = (drPhil->init_ime.tv_sec * 1000 + \
	drPhil->init_ime.tv_usec / 1000) % drPhil->table->info.fig;
	result = curntime - prevtime;
	if (result < 0)
		result += drPhil->table->info.fig;
	// printf("phil no-> %d,, current time -> %ld\n", drPhil->the_hand->hand, curntime % 10000);
	// printf("phil no-> %d,, init time -> %ld\n", drPhil->the_hand->hand, prevtime % 10000);
	// printf("phil no-> %d,, resultant -> %ld\n", drPhil->the_hand->hand, result % 10000);
	// pthread_mutex_unlock(&drPhil->table->printm);
	if (result > drPhil->table->info.tT_DIE)
	{
		// printf("whaaaaæt -> previou -> %ld\n", prevtime);
		// printf("whaaaaæt -> current -> %ld\n", curntime);
		// printf("whaaaaæt -> res -> %ld\n", result);
		// printf("whaaaaæt -> tT_die -> %d\n", drPhil->table->info.tT_DIE);
		timeStamp(drPhil, RED, 1, DED);
		// if (drPhil->the_hand->cuffed == drPhil->id)
			// pthread_mutex_unlock(&drPhil->the_hand->cuffs);
		// if (drPhil->the_neighbours_hand->cuffed == drPhil->id)
			// pthread_mutex_unlock(&drPhil->the_neighbours_hand->cuffs);
		return (0);
	}
	return (0);
}

void	timeStamp(t_philo *philo, char *clr, int ded, char *msg)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->table->printm);
	gettimeofday(&time, NULL);
	if (ded)
	{
		printf("%s%0*ld \e[9m\e[2m%d\e[29m\e[22m %s", clr,
		philo->table->info.dig, (long)((time.tv_sec * 1000
		+ time.tv_usec / 1000) % philo->table->info.fig), philo->id, msg);
	}
	else
	{
		printf("%s%0*ld %d %s", clr, philo->table->info.dig,
		(long)((time.tv_sec * 1000 + time.tv_usec / 1000)
		% philo->table->info.fig), philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->printm);
	// return ;
}

void	*bon_appetit(void *args)
{
	// timeStamp((t_philo *)args, WHT, 0, "created!\n");
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)args;
	gettimeofday(&philo->init_ime, NULL);
	while (1)
	{
		// testr(philo);
		if (death_reaper(philo))
			return ((void *)1);
		timeStamp(philo, GRN, 0, THK);
		// if (think_about_life_with_arms(philo))
			// return ((void *)1);
		if (philo->id % 2)
		{
			if (odd_philosophers(philo))
				return ((void *)1);
		}
		else
		{
			usleep(500);
			if (even_philosophers(philo))
				return ((void *)1);
		}
		if (dream_about_life_with_arms(philo))
			return ((void *)1);
		if (philo->table->info.tPpMEat)
			if (++i == philo->table->info.tPpMEat)
				break ;
	}
	return ((void *)0);
}

// int	stalker_69(t_able *table)
// {
// 	int	i;

// 	i = 0;
// 	while (69)
// 	{
// 		if ((table->pps[i].curnt_ime.tv_sec * 1000 \
// 			+ table->pps[i].curnt_ime.tv_usec / 1000) \
// 			- (table->pps[i].init_ime.tv_sec * 1000 \
// 				+ table->pps[i].init_ime.tv_usec / 1000) \
// 				>= table->info.tT_DIE)
// 					break ;
// 		i++;
// 		if (i == table->info.pp_amt)
// 			i = 0;
// 	}
// 	return (69);
// }

void	*restaurant_with_limited_utensils(void *arg)
{
	t_able	*table;
	t_hands	*tmp;
	int		i;

	i = -1;
	table = (t_able *)arg;
	tmp = table->hands;
	while (++i < table->info.pp_amt)
	{
		table->pps[i].id = i + 1;
		table->pps[i].the_hand = tmp;
		table->pps[i].clr = 0;
		tmp = tmp->next;
		table->pps[i].the_neighbours_hand = tmp;
		table->pps[i].table = table;
		// if (pthread_create(&table->pps[i].tid, NULL, bon_appetit, &table->pps[i]))
		// 	exit(EXIT_FAILURE);
		pthread_create(&table->pps[i].tid, NULL, bon_appetit, &table->pps[i]);
		timeStamp(&table->pps[i], WHT, 0, "created!\n");
	}
	i = -1;
	while (++i < table->info.pp_amt)
		pthread_join(table->pps[i].tid, NULL);
	return (NULL);
}

int	main(int c, char **v)
{
	pthread_t	root;
	t_able	table;

	if (!valid_arg(c, v))
		return (1);
	initInfo(c, v, &table.info);
	artificial_intelligence(&table.info);
	printf("fig = %d\n", table.info.fig);
	printf("dig = %d\n", table.info.dig);
	printf("tT_DIE = %d\n", table.info.tT_DIE);
	table.pps = calloc(table.info.pp_amt, sizeof(t_philo));
	table.hands = cuffs_init(table.info.pp_amt);
	if (pthread_mutex_init(&table.printm, NULL))//addition
	{
		ultimate_destructor(table.hands);
		return (1);
	}
	// pre_testr(table.hands, table.info.pp_amt);
	// pthread_create(&root, NULL, restaurant_with_limited_utensils, &table);
	// pthread_join(root, NULL);
	restaurant_with_limited_utensils(&table);
	pthread_mutex_destroy(&table.printm);
	ultimate_destructor(table.hands);
	return (0);
}
