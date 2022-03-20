/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:19 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 15:42:24 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (data->forks && i < data->input.ph_num)
			pthread_mutex_destroy(&data->forks[i++]);
	}
	if (data->philos != NULL)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks != NULL)
	{
		free(data->forks);
		data->forks = NULL;
	}
	return (true);
}

int	one_philo(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		free_philo(data);
		return (false);
	}
	printf("%lu %d has taken a fork\n", ft_gettime() - data->starttime,
		data->philos->id);
	mysleep(data->philos->input.die_time);
	printf(RED"%lu %d died\n"WTH, ft_gettime() - data->starttime,
		data->philos->id);
	free_philo(data);
	pthread_mutex_destroy(&data->print);
	return (true);
}

void	ft_print_philo(char *str, t_philo *philo)
{
	unsigned int	now;

	now = ft_gettime() - philo->starttime;
	pthread_mutex_lock(philo->print);
	if (str == EATING)
		printf(GREEN"%d %d %s\n"WTH, now, philo->id, str);
	if (str == SLEEPING)
		printf(BLUE"%d %d %s\n"WTH, now, philo->id, str);
	if (str == THINKING)
		printf(YELW"%d %d %s\n"WTH, now, philo->id, str);
	if (str == TAKEN_FORK)
		printf(WTH"%d %d %s\n"WTH, now, philo->id, str);
	if (*str == 'd')
		printf(WTH"%d %d %s\n"WTH, now, philo->id, str);
	pthread_mutex_unlock(philo->print);
}
