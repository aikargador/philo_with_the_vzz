#include "pp.h"

void	ultimate_destructor(t_hands *hands)
{
	t_hands	*tmp;
	int	i;

	i = -1;
	while (++i < hands->hand)
	{
		tmp = hands->next;
		pthread_mutex_destroy(&hands->cuffs);
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
		free(hands);
		if (i + 1 < l)
			break ;
		hands = tmp;
	}
	return (NULL);
}