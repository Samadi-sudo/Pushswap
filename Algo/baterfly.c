/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baterfly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:16:32 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 11:10:17 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../metodes/push.h"
#include "algo.h"

void	push_to_b(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index < i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_idx;
	int	max_pos;
	int	size_b;

	while ((*stack_b))
	{
		max_idx = get_max_index(*stack_b);
		max_pos = find_index_pos(*stack_b, max_idx);
		size_b = stack_size(*stack_b);
		if (max_pos <= size_b / 2)
		{
			while ((*stack_b)->index != max_idx)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_idx)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_list **stack_a)
{
	int		range;
	int		num;
	t_list	*stack_b;

	stack_b = NULL;
	num = stack_size(*stack_a);
	if (num >= 500)
		range = 33;
	else
		range = 15;
	push_to_b(stack_a, &stack_b, range);
	push_to_a(stack_a, &stack_b);
}
