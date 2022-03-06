/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:01:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/06 17:17:22 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_init(t_data *data, int argc, char **argv)
{
	
	
	return (true);
}

int	free_philo(t_data *data)
{
	if (data->philos != NULL)
		free(data->philos);
	//if (data->forks != NULL)
	//	free(data->forks);
	return (true);
}