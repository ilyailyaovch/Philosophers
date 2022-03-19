/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:04:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/14 19:33:28 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(true)
	{
		if (!go_eat(philo)) //not yet
			break ;
		if (!go_sleep(philo)) //not yet
			break ;
		if (!go_think(philo)) //not yet
			break ;
	}
	return (NULL);
}

int	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (false);
	while (i < data->num)
	{
		data->philos[i].print = &data->print;
		if (pthread_create(&data->philos[i].thread_id, NULL,
			&routine, (void *)&data->philos[i]))
			return (false);
		i++;
		usleep(1);
	}
	//ft_check_death(data);
	pthread_mutex_destroy(&data->print); // ?
	//(void) data;
	return (true);
}
