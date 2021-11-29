/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 19:19:54 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/11/29 19:51:18 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			negative;
	long int	digit;

	i = 0;
	digit = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		if ((digit * negative) < FT_INT_MIN)
			return (0);
		else if ((digit * negative) > FT_INT_MAX)
			return (-1);
		i++;
	}
	return (digit * negative);
}