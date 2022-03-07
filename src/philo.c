/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:16:18 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/07 13:02:04 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_data	data;
	
	if (!ft_check_args(argc, argv))
		return (FAILURE);
		
	ft_data_init(argc, argv, &data);

	if (!ft_philo_init(&data, argc, argv))
		return (free_philo(&data));

	if (!ft_forks_init(&data)) //not yet
		return (free_philo(&data));

	

	// tests
	printf("nice\n");
	printf("phils: %d\n", data.num);
	printf("phil_0: %d\n", data.philos->id);
	printf("phil_1: %d\n", data.philos[1].id);
	printf("start time: %lu\n", data.starttime);
	printf("eat: %lu\n", data.input.eat_time);
	printf("sleep: %lu\n", data.input.sleep_time);
	printf("die: %lu\n", data.input.die_time);
	//free_philo(&data);
	return (SUCCESS);
}