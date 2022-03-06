/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:16:20 by pleoma            #+#    #+#             */
/*   Updated: 2022/03/06 17:13:57 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELW "\033[1;33m"
# define WTH "\033[0;37m"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_input
{
	int				ph_num;
	unsigned long	die_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	int				meal_num;
}	t_input;

typedef struct s_philo
{	
	int				id;
	t_input			input;

}	t_philo;

typedef struct s_data
{
	int				num;
	t_input			input;
	t_philo			*philos;
	
}	t_data;

/*	fts_args.c */
int 	ft_check_digit(int argc, char **argv);
int		ft_check_args(int argc, char **argv);
int		ft_check_value(int argc, char **argv);
void	ft_data_init(int argc, char **argv, t_data *data);

/*	fts_init.c */
int		ft_philo_init(t_data *data, int argc, char **argv);
int		free_philo(t_data *data);

/*	lib_1.c */
int		ft_isdigit(int symb);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif