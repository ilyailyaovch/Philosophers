/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:48:33 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 13:28:30 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_meals_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->xate >= philo->input.meal_num)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (false);
}

void	take_forks(t_philo *philo)
{
	if (philo->leftfirst)
	{
		pthread_mutex_lock(philo->leftfork);
		ft_print_philo(TAKEN_FORK, philo);
		pthread_mutex_lock(philo->rightfork);
		ft_print_philo(TAKEN_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(philo->rightfork);
		ft_print_philo(TAKEN_FORK, philo);
		pthread_mutex_lock(philo->leftfork);
		ft_print_philo(TAKEN_FORK, philo);
	}
	ft_print_philo(EATING, philo);
}

int	go_eat(t_philo *philo)
{
	usleep(1);
	if (philo->input.meal_num > 0 && ft_meals_done(philo) == true)
		return (false);
	take_forks(philo);
	pthread_mutex_lock(&philo->mutex);
	philo->xate++;
	philo->lasttime = ft_gettime();
	pthread_mutex_unlock(&philo->mutex);
	mysleep(philo->input.eat_time);
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
	return (true);
}

int	go_sleep(t_philo *philo)
{
	if (philo->input.meal_num > 0 && ft_meals_done(philo) == true)
		return (false);
	ft_print_philo(SLEEPING, philo);
	mysleep(philo->input.sleep_time);
	return (true);
}

int	go_think(t_philo *philo)
{
	if (philo->input.meal_num > 0 && ft_meals_done(philo) == true)
		return (false);
	ft_print_philo(THINKING, philo);
	return (true);
}
