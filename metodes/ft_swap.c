/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:01:51 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 09:30:00 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_list **stack_a)
{
	if (!swap(stack_a))
		return ;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	if (!swap(stack_b))
		return ;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
