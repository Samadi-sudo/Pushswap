/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:38:16 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 09:29:56 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ra(t_list **stack_a)
{
	if (!rotate(stack_a))
		return ;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	if (!rotate(stack_b))
		return ;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
