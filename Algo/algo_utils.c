/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:22:02 by abantari          #+#    #+#             */
/*   Updated: 2026/01/10 11:26:11 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../metodes/push.h"

int	stack_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_index_pos(t_list *stack, int target_index)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->index == target_index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_max_index(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (1);
		stack = stack->next;
	}
	return (0);
}
