#include "pp.h"

t_hands	*cuffs_manufacturer(void)
{
	t_hands	*hand;

	hand = calloc(1, sizeof(t_hands));
	if (!hand)
		return (NULL);
	// hand->cuffed = 0;
	hand->next = NULL;
	return (hand);
}

t_hands	*cuffs_init(int amt_of_prosthetic_arms)
{
	t_hands	*hands;
	t_hands	*tmp;
	int	i;

	i = 0;
	hands = 0;
	while (++i <= amt_of_prosthetic_arms)
	{
		tmp = cuffs_manufacturer();
		if(!tmp)
			return (mission_failed_retreat(hands, i));
		ft_lstadd_back(&hands, tmp);
		tmp->hand = i;
		if (pthread_mutex_init(&tmp->cuffs, NULL))
			return (mission_failed_retreat(hands, i));
		if (pthread_mutex_init(&tmp->chk_cuff, NULL))
			return (mission_failed_retreat(hands, i));
	}
	tmp->next = hands;
	return (hands);
}
// t_hands	*cuffs_init(int amt_of_prosthetic_arms)
// {
// 	t_hands	*hands;
// 	t_hands	*tmp;
// 	t_hands *idk;
// 	int		i;

// 	i = 0;
// 	hands = 0;
// 	while (++i < amt_of_prosthetic_arms)
// 	{
// 		tmp = cuffs_manufacturer();
// 		if(!tmp)
// 			return (mission_failed_retreat(hands, i));
		
// 		// ft_lstadd_back(hands, tmp);
// 		tmp->hand = i;
// 		if (pthread_mutex_init(&tmp->cuffs, NULL))
// 			return (mission_failed_retreat(hands, i));
// 	}

// 	return (hands);
// }

