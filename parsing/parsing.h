/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:30:02 by abantari          #+#    #+#             */
/*   Updated: 2026/01/07 17:57:37 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

char	**ft_split(int argc, char **argv);
int		*to_int(char **arguments);

#endif
