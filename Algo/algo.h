/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:21:07 by abantari          #+#    #+#             */
/*   Updated: 2026/01/09 19:29:17 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "../metodes/push.h"

int	stack_size(t_list *stack);
int	find_index_pos(t_list *stack, int target_index);
int	get_max_index(t_list *stack);
int	is_sorted(t_list *stack);

#endif