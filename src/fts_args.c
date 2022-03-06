/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:02:14 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/06 16:50:04 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_check_digit(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_check_value(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		//
		if (ft_atoi(argv[i]) <= 0)
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc !=5 && argc !=6)
		return(printf(RED"Wrong number of args\n"WTH) && false);

	if (!ft_check_digit(argc, argv))
		return(printf(RED"Invalid input data\n"WTH) && false);
		
	if (!ft_check_value(argc, argv))
		return(printf(RED"Wrong input data\n"WTH) && false);
		
	return (true);
}

void	ft_data_init(int argc, char **argv, t_data *data)
{
	data->num = ft_atoi(argv[1]);
	data->input.die_time = ft_atoi(argv[2]);
	data->input.eat_time = ft_atoi(argv[3]);
	data->input.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->input.meal_num = ft_atoi(argv[5]);
	else
		data->input.meal_num = -1;
}