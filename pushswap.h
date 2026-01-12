/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:32:16 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 11:30:40 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_parse(int argc, char **argv, int **table, size_t *count);
void				assign_index(t_list *stack, int *arr, int size);
void				small_sort(t_list **stack_a, int count);
void				chunk_sort(t_list **stack_a);
int					is_sorted(t_list *stack);

#endif
