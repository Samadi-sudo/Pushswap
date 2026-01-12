/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:47:36 by abantari          #+#    #+#             */
/*   Updated: 2026/01/07 14:35:43 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	ft_strlen_word(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && !(str[len] == ' ' || (str[len] >= 9 && str[len] <= 13)))
		len++;
	return (len);
}

size_t	count_words(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
	}
	return (count);
}

int	ft_separate(char *str, char **arguments, size_t *j)
{
	size_t	len;
	size_t	i;
	size_t	x;

	i = 0;
	while (str[i])
	{
		x = 0;
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (!str[i])
			break ;
		len = ft_strlen_word(&str[i]);
		arguments[*j] = malloc(sizeof(char) * (len + 1));
		if (!arguments[*j])
			return (1);
		arguments[*j][len] = '\0';
		while (x < len)
			arguments[*j][x++] = str[i++];
		(*j)++;
	}
	return (0);
}

char	**allo_arguments(int argc, char **argv, size_t count)
{
	size_t	i;
	size_t	j;
	char	**arguments;

	i = 1;
	j = 0;
	arguments = malloc(sizeof(char *) * (count + 1));
	if (!arguments)
		return (NULL);
	while (i < (size_t)argc)
	{
		if (ft_separate(argv[i], arguments, &j))
		{
			i = 0;
			while (i < j)
				free(arguments[i++]);
			free(arguments);
			return (NULL);
		}
		i++;
	}
	arguments[j] = NULL;
	return (arguments);
}

char	**ft_split(int argc, char **argv)
{
	size_t	count;
	char	**arguments;
	size_t	word;
	size_t	i;

	count = 0;
	i = 1;
	while (i < (size_t)argc)
	{
		word = count_words(argv[i]);
		if (!(word))
			return (NULL);
		count += word;
		i++;
	}
	arguments = allo_arguments(argc, argv, count);
	if (!arguments)
		return (NULL);
	return (arguments);
}
