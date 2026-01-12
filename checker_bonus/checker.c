/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:15:43 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 10:41:31 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "checker.h"

static int	check_move(char *move, t_list **a, t_list **b)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(a);
	else if (!ft_strcmp(move, "sb\n"))
		sb(b);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(move, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(move, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(move, "rra\n"))
		rra(a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b);
	else
		return (0);
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*prev;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		prev = *stack;
		*stack = (*stack)->next;
		free(prev);
	}
}

int	lst_add_back(t_list **head, int data)
{
	t_list	*cur_lst;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->index = -1;
	new->data = data;
	if (!*head)
	{
		*head = new;
		return (1);
	}
	cur_lst = *head;
	while (cur_lst->next)
	{
		cur_lst = cur_lst->next;
	}
	cur_lst->next = new;
	return (1);
}

int	checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*move;

	stack_b = NULL;
	move = get_next_line(0);
	while (move)
	{
		if (!(check_move(move, stack_a, &stack_b)))
		{
			free(move);
			return (0);
		}
		free(move);
		move = get_next_line(0);
	}
	if (is_sorted(*stack_a) || stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(move);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*table;
	t_list	*a;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	a = NULL;
	if (!(ft_parse(argc, argv, &(table), &count)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (i < count)
	{
		lst_add_back(&a, table[i]);
		i++;
	}
	if (!(checker(&a)))
		write(2, "Error\n", 6);
	free(table);
	free_stack(&a);
}
