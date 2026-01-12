/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:35:55 by abantari          #+#    #+#             */
/*   Updated: 2026/01/09 18:56:54 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../metodes/push.h"

void	buble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_list *stack, int *arr, int size)
{
	int		i;
	t_list	*cur;

	buble_sort(arr, size);
	cur = stack;
	while (cur)
	{
		i = 0;
		while (i < size)
		{
			if (cur->data == arr[i])
			{
				cur->index = i;
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
}
