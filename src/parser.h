/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:37:56 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 14:17:26 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define INVALID_NUMBER 0
# include "defines.h"

int				ft_isdigit(int c);
int				ft_isspace(char c);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
int				get_number(const char *str);
t_bool			is_valid_input(const int argc, const char *argv[]);
t_exit_status	parse_philo_stats(const char *argv[], t_philo_stats *stats);

#endif