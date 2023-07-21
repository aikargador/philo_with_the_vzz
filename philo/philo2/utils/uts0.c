#include "pp.h"

void	ft_cautious_free(void **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

void	ft_very_cautious_free(void ***pointer)
{
	free(*pointer);
	*pointer = NULL;
}

bool	chk_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		return (ret_putstr_fd("philosophers: %s: be positive!\n", str, 2, false));
	if (str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (ret_putstr_fd("philosophers: %s: numeric arg only!\n", str, 2, false));
	if (ft_atopi(str) == -1)
		return (ret_putstr_fd("philosophers: %s: arg too big!\n", str, 2, false));
	return (true);
}


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
