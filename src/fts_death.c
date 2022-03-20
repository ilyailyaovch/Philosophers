/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_death.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:46:34 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 13:31:45 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	detach_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_detach(data->philos[i].thread_id) != 0)
			return (false);
		i++;
	}
	return (true);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

int	isdead(t_philo *philo)
{
	unsigned long	now;

	now = ft_gettime();
	pthread_mutex_lock(&philo->mutex);
	if (now - philo->lasttime > philo->input.die_time)
		return (true);
	pthread_mutex_unlock(&philo->mutex);
	return (false);
}

int	manage_meals(t_data *data, int i)
{
	pthread_mutex_lock(&data->philos[i].mutex);
	if (data->philos[i].xate >= data->input.meal_num)
	{
		pthread_mutex_unlock(&data->philos[i].mutex);
		return (join_threads(data));
	}
	pthread_mutex_unlock(&data->philos[i].mutex);
	return (false);
}

void	ft_check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->num)
	{
		if (i == data->num)
			i = 0;
		if (isdead(&data->philos[i]))
		{
			pthread_mutex_lock(data->philos[i].print);
			detach_threads(data);
			mysleep(1);
			printf(RED"%lu %d died\n"WTH,
				ft_gettime() - data->philos[i].starttime - 1,
				data->philos[i].id);
			return ;
		}
		else if (data->input.meal_num != -1)
		{
			if (manage_meals(data, i))
				return ;
		}
		i++;
	}
}
