/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:19 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/07 12:39:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_philo(t_data *data)
{
	if (data->philos != NULL)
		free(data->philos);
	if (data->forks != NULL)
		free(data->forks);
	return (true);
}
