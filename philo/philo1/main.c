	/*

	---> current phil to sleep and tteat
	---> and phil's time to think which is
	related to the other philosopher's time to eat! and tteat
	---> first phil to eat! -> 	only ttsleep and tteat surr-pils time to eat!
	---> second phil ttthink and ttsleep and tteat

	------><>> valgrind --tool=helgrind ./philo 5 800 200 200

	---> ttthink which is the surr-phils tteat		200
	---> tteat										200 / 400
	---> ttsleep									100
	
	---> ttthink which is the surr-phils tteat		200
	---> tteat										200 / 400
	---> ttsleep									200

	--> 🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯🤯
	*/

#include "pp.h"

void	pre_testr(t_hands *hands, int amt) // temporary
{
	int i;

	i = 0;
	printf("\npre_testr\n\n");
	while (++i <= amt * 2)
	{
		printf("hand no. %d cuffed? %d\n", hands->hand, hands->cuffed);
		printf("neighbour's hand no. %d cuffed? %d\n", hands->next->hand, hands->next->cuffed);
		hands = hands->next;
	}
	printf("\n\n\n");
}

void	testr(t_philo *philo) // temporary
{
	// int i;

	// i = 0;
	// while (++i < philo->table->info.pp_amt)
	// {
		printf("hand no. %d cuffed? %d\n", philo->the_hand->hand, philo->the_hand->cuffed);
		printf("neighbour's hand no. %d cuffed? %d\n", philo->the_neighbours_hand->hand, philo->the_neighbours_hand->cuffed);
	// }
}

int	death_reaper(t_philo *drPhil)
{
	long	prevTime;
	long	curntTime;
	long	result;

	gettimeofday(&drPhil->curntTime, NULL);
	curntTime = (drPhil->curntTime.tv_sec * 1000 + drPhil->curntTime.tv_usec / 1000)
		 % 1000;
	prevTime = (drPhil->initTime.tv_sec * 1000 + drPhil->initTime.tv_usec / 1000)
	 % 1000;
	result = curntTime - prevTime;
	if (result < 0)
		result += 1000;
	if (result > drPhil->table->info.tT_DIE)
	{
		timeStamp(drPhil, DED);
		return (1);
	}
	return (0);
}

void	timeStamp(t_philo *philo, char *msg)
{
	struct timeval	time;

	gettimeofday(&time, NULL);// include mutex lock here
	pthread_mutex_lock(&philo->table->printm);
	printf("%03ld %d %s", (long)((time.tv_sec * 1000 + \
		time.tv_usec / 1000) % 1000), philo->id, msg);
	pthread_mutex_unlock(&philo->table->printm);
	// return ;
}

void	*bon_appetit(void *args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)args;
	gettimeofday(&philo->initTime, NULL);

	while (1)
	{
		// testr(philo);
		if (death_reaper(philo))
			return ((void *)1);
		if (think_about_life_with_arms(philo))
			return ((void *)1);
		if (philo->id % 2)
		{
			usleep(2);
			if (even_philosophers(philo))
				return ((void *)1);
		}
		else
		{
			if (odd_philosophers(philo))
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

void	restaurant_with_limited_utensils(t_able *table)
{
	t_hands	*tmp;
	int		i;

	i = -1;
	tmp = table->hands;
	while (++i < table->info.pp_amt)
	{
		table->pps[i].id = i + 1;
		table->pps[i].the_hand = tmp;
		tmp = tmp->next;
		table->pps[i].the_neighbours_hand = tmp;
		table->pps[i].table = table;
		pthread_create(&table->pps[i].tid, NULL, bon_appetit, &table->pps[i]);
	}
	i = -1;
	while (++i < table->info.pp_amt)
		pthread_join(table->pps[i].tid, NULL);
	return ;
}

int	main(int c, char **v)
{
	t_able	table;

	if (!valid_arg(c, v))
		return (1);
	initInfo(c, v, &table.info);
	table.pps = calloc(table.info.pp_amt, sizeof(t_philo));
	table.hands = cuffs_init(table.info.pp_amt);
	if (pthread_mutex_init(&table.printm, NULL))//addition
	{
		ultimate_destructor(table.hands);
		return (1);
	}
	// pre_testr(table.hands, table.info.pp_amt);
	restaurant_with_limited_utensils(&table);
	pthread_mutex_destroy(&table.printm);
	ultimate_destructor(table.hands);
	return (0);
}
