/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:37:56 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 20:16:13 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define INVALID_NUMBER 0
# include "defines.h"

# define USAGE_STRING "Usage: ./philo num_of_philos[ > 1] \
tt_die tt_eat tt_sleep [number_of_times_each_philosopher_must_eat] "

int				ft_isdigit(int c);
int				ft_isspace(char c);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
int				get_number(const char *str);
t_bool			is_valid_input(const int argc, const char *argv[]);
t_exit_status	parse_philo_stats(const char *argv[], t_philo_stats *stats);

#endif