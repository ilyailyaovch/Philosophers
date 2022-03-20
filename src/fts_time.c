/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:32:51 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 13:26:27 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	ft_gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	mysleep(unsigned long ms)
{
	unsigned long	starttime;
	unsigned long	currenttime;

	starttime = ft_gettime();
	currenttime = starttime;
	while (currenttime - starttime < ms)
	{
		currenttime = ft_gettime();
		usleep(ms);
	}
}
