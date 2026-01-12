/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:07:28 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 09:29:49 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_lst;

	if (!stack_b || !(*stack_b))
		return ;
	tmp_lst = *stack_b;
	*stack_b = tmp_lst->next;
	tmp_lst->next = *stack_a;
	*stack_a = tmp_lst;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_lst;

	if (!stack_a || !(*stack_a))
		return ;
	tmp_lst = *stack_a;
	*stack_a = tmp_lst->next;
	tmp_lst->next = *stack_b;
	*stack_b = tmp_lst;
	write(1, "pb\n", 3);
}
