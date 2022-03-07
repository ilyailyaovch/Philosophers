/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:01:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/07 13:01:50 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_init(t_data *data, int argc, char **argv)
{
	int count;

	count = 0;
	data->starttime = ft_gettime();
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num);
	if (!data->philos)
		return(false);
	while (count < data->num)
	{
		data->philos[count].id = count + 1;
		data->philos[count].xate = 0;
		data->philos[count].starttime = data->starttime;
		data->philos[count].lasttime = data->starttime;
		data->philos[count].leftfirst = count % 2;
		pthread_mutex_init(&data->philos[count].mutex, NULL);
		ft_data_philo_init(argc, argv, &(data->philos[count]));
		count++;
	}
	return (true);
}

int	ft_forks_init(t_data *data)
{
	
	
	return (true);
}

void	ft_data_init(int argc, char **argv, t_data *data)
{
	data->num = ft_atoi(argv[1]);
	data->input.ph_num = ft_atoi(argv[1]);
	data->input.die_time = ft_atoi(argv[2]);
	data->input.eat_time = ft_atoi(argv[3]);
	data->input.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->input.meal_num = ft_atoi(argv[5]);
	else
		data->input.meal_num = -1;
}

void	ft_data_philo_init(int argc, char **argv, t_philo *philo)
{
	philo->input.ph_num = ft_atoi(argv[1]);
	philo->input.die_time = ft_atoi(argv[2]);
	philo->input.eat_time = ft_atoi(argv[3]);
	philo->input.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		philo->input.meal_num = ft_atoi(argv[5]);
	else
		philo->input.meal_num = -1;
}