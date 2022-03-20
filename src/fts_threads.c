/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:04:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 15:26:52 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (!go_eat(philo))
			break ;
		if (!go_sleep(philo))
			break ;
		if (!go_think(philo))
			break ;
	}
	return (NULL);
}

int	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		free_philo(data);
		return (false);
	}
	while (i < data->num)
	{
		data->philos[i].print = &data->print;
		if (pthread_create(&data->philos[i].thread_id, NULL,
				&routine, (void *)&data->philos[i]))
			return (false);
		i++;
		usleep(1);
	}
	ft_check_death(data);
	return (true);
}
