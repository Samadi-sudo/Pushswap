/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:07:28 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 10:17:11 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_lst;

	if (!stack_b || !(*stack_b))
		return ;
	tmp_lst = *stack_b;
	*stack_b = tmp_lst->next;
	tmp_lst->next = *stack_a;
	*stack_a = tmp_lst;
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
}
