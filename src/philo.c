/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:16:18 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/20 15:50:22 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_check_args(argc, argv))
		return (FAILURE);
	ft_data_init(argc, argv, &data);
	if (!ft_philo_init(&data, argc, argv))
		return (free_philo(&data));
	if (!ft_forks_init(&data))
		return (free_philo(&data));
	if (data.input.ph_num == 1)
		return (one_philo(&data));
	else
	{
		ft_create_threads(&data);
		free_philo(&data);
		return (SUCCESS);
	}
	return (SUCCESS);
}
