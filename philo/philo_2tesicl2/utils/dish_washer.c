#include "pp.h"

void	ultimate_destructor(t_hands *hands)
{
	t_hands	*tmp;
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (++i[1] <= hands->hand)
		hands = hands->next;
	while (++i[0] < i[1])
	{
		tmp = hands->next;
		pthread_mutex_destroy(&hands->cuffs);
		pthread_mutex_destroy(&hands->chk_cuff);
		free(hands);
		hands = tmp;
	}
}

void	*mission_failed_retreat(t_hands *hands, int l)
{
	t_hands	*tmp;
	int	i;

	i = 0	;
	while (++i < l)
	{
		if (i + 1 < l)
			tmp = hands->next;
		pthread_mutex_destroy(&hands->cuffs);
		pthread_mutex_destroy(&hands->chk_cuff);
		free(hands);
		if (i + 1 < l)
			break ;
		hands = tmp;
	}
	return (NULL);
}