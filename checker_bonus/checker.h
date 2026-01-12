/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:53:19 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 10:40:19 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./metodes/push_bonus.h"
# include <stddef.h>
# include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2);
int	ft_parse(int argc, char **argv, int **table, size_t *count);
int	is_sorted(t_list *stack);

#endif