/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:16:18 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/06 17:26:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_data	data;
	
	if (!ft_check_args(argc, argv))
		return (FAILURE);
		
	ft_data_init(argc, argv, &data);

	if (!ft_philo_init(&data, argc, argv))				//
		return (free_philo(&data));						//


	
	printf("nice\n");
	printf("phils: %d\n", data.num);
	return (SUCCESS);
}