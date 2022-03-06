/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:28:54 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/06 17:05:51 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int symb)
{	
	if ((symb >= '0') && (symb <= '9'))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	unsigned int	coun;

	coun = 0;
	while (str[coun] != '\0')
	{
		coun++;
	}
	return (coun);
}

int	ft_atoi(const char *str)
{	
	int		sign;
	int		sbl;
	long	number;

	sign = 1;
	sbl = 0;
	number = 0;
	while (((str[sbl] >= 9) && (str[sbl] <= 13)) || (str[sbl] == ' '))
		sbl++;
	if ((str[sbl] == '-') || (str[sbl] == '+'))
	{
		if (str[sbl] == '-')
			sign *= (-1);
		sbl++;
	}
	while ((str[sbl] >= '0') && (str[sbl] <= '9'))
	{
		number = (number * 10) + (str[sbl] - '0');
		if (number > 2147483647 && sign == 1)
			return (-1);
		if (number > 2147483648 && sign == -1)
			return (0);
		sbl++;
	}
	return (sign * number);
}
