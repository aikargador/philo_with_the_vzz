/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:06:54 by aikram            #+#    #+#             */
/*   Updated: 2023/03/23 15:15:40 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &(s[index]), 1);
		index++;
	}
	return (false);
}

bool	ret_putstr_fd(char *s, char *inc, int fd, bool free)
{
	size_t	i[2];

	i[0] = -1;
	while (s[++i[0]] && s[i[0]] != '%')
		write(fd, &(s[i[0]]), 1);
	if (inc && *inc)
	{
		i[1] = -1;
		while (inc[++i[1]])
			write(fd, &(inc[i[1]]), 1);
		if (free)
			ft_cautious_free((void **)&inc);
		write(fd, " ", 1);
	}
	i[0] += 1;
	while (s[++i[0]])
		write(fd, &(s[i[0]]), 1);
	return (false);
}

// static char	*ft_strcpy(char *dest, char *src)
// {
// 	size_t	index;

// 	index = 0;
// 	while (src[index] != '\0')
// 	{
// 		dest[index] = src[index];
// 		index++;
// 	}
// 	dest[index] = '\0';
// 	return (dest);
// }

// char	*ft_strdup(char *src)
// {
// 	char	*new;

// 	if (src == NULL)
// 		return (NULL);
// 	new = malloc((ft_strlen(src) + 1) * sizeof(char));
// 	if (new == NULL)
// 	{
// 		errno = ENOMEM;
// 		return (NULL);
// 	}
// 	ft_strcpy(new, src);
// 	return (new);
// }

// void	fill_struct(int c, char *v[], t_info *vals)
// {
// 	vals->amt_philo = ft_atoi(v[1]);
// 	vals->time_to_DIE = ft_atoi(v[2]);
// 	vals->time_to_EAT = ft_atoi(v[3]);
// 	vals->time_to_sleep = ft_atoi(v[4]);
// 	if (c == 6)
// 		vals->time_philo_eats = ft_atoi(v[0]);
// }

// void	create_philos(t_philo *pho, t_info *vals)
// {
// 	int i;

// 	i = -1;
// 	while (++i < vals->amt_philo) {
// 		pthread_create(pho->philo + i, NULL, (void *)chicken_biryani, NULL);
// 		pthread_mutex_init(pho->right_hand + i, NULL);
// 	}
// }

// void	print_time(int x, char l)
// {
// 	// timeval *tv;

// 	gettimeofday(&tv, NULL);
// 	if (l == 'f')
// 		printf("%d %d has taken a fork\n", );
// 	else if (l == 'e')
// 		printf("%d %d is eating\n", );
// 	else if (l == 's')
// 		printf("%d %d is sleeping\n", );
// 	else if (l == 't')
// 		printf("%d %d is thinking\n", );
// 	else
// 		printf("%d %d died\n", );
// }