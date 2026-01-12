/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:45:13 by abantari          #+#    #+#             */
/*   Updated: 2026/01/07 18:54:13 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_atoi_suite(const char *str, int *sign, long *result, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*result) = (*result) * 10 + (str[*i] - '0');
		if ((*sign) == 1 && (*result) > INT_MAX)
			return (0);
		if ((*sign) == -1 && -(*result) < INT_MIN)
			return (0);
		(*i)++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *out)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	if (!(ft_atoi_suite(str, &sign, &result, &i)))
		return (0);
	if (str[i] != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}

int	check(int *table, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (table[i] == table[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_int_suite_init(size_t *i, size_t *len, char **arguments)
{
	*i = 0;
	*len = 0;
	while (arguments[(*len)])
		(*len)++;
}

int	*to_int(char **arguments)
{
	size_t	i;
	size_t	len;
	int		*table;

	to_int_suite_init(&i, &len, arguments);
	table = malloc(sizeof(int) * len);
	if (!table)
		return (NULL);
	while (i < len)
	{
		if (!(ft_atoi(arguments[i], &table[i])))
		{
			free(table);
			return (NULL);
		}
		i++;
	}
	if (!(check(table, len)))
	{
		free(table);
		return (NULL);
	}
	return (table);
}
