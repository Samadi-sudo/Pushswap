/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:46:36 by abantari          #+#    #+#             */
/*   Updated: 2026/01/09 18:48:36 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_parse(int argc, char **argv, int **table, size_t	*count)
{
	char	**arguments;

	arguments = ft_split(argc, argv);
	if (!arguments)
		return (0);
	(*table) = to_int(arguments);
	while (arguments[(*count)])
	{
		free(arguments[(*count)]);
		(*count)++;
	}
	free(arguments);
	if (!(*table))
		return (0);
	return (1);
}
