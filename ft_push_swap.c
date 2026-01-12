/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:53:40 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 11:30:37 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	sort(t_list **stack_a, size_t count)
{
	if (is_sorted(*stack_a))
	{
		if (count <= 5)
			small_sort(stack_a, count);
		else
			chunk_sort(stack_a);
	}
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
	assign_index(a, table, count);
	sort(&a, count);
	free(table);
	free_stack(&a);
}
