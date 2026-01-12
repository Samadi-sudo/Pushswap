/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:42:35 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 09:27:43 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../metodes/push.h"
#include "algo.h"

static int	get_min_index(t_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static void	sort_trois(t_list **stack_a, int *count)
{
	int		max_idx;

	if (*count == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	else if (*count == 3)
	{
		max_idx = get_max_index(*stack_a);
		if ((*stack_a)->index == max_idx)
			ra(stack_a);
		else if ((*stack_a)->next->index == max_idx)
			rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}

void	small_sort(t_list **stack_a, int count)
{
	int		min_idx;
	int		min_pos;
	t_list	*stack_b;

	stack_b = NULL;
	while (count > 3)
	{
		min_idx = get_min_index(*stack_a);
		min_pos = find_index_pos(*stack_a, min_idx);
		if (min_pos <= count / 2)
		{
			while ((*stack_a)->index != min_idx)
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->index != min_idx)
				rra(stack_a);
		}
		pb(stack_a, &stack_b);
		count--;
	}
	sort_trois(stack_a, &count);
	while (stack_b)
		pa(stack_a, &stack_b);
}
