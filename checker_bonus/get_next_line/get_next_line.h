/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:09:19 by abantari          #+#    #+#             */
/*   Updated: 2026/01/12 12:05:59 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct sg_list
{
	char			*data;
	ssize_t			len;
	struct sg_list	*next;
}					t_glist;

// next_line
char				*get_next_line(int fd);
// utils
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
ssize_t				find_nl(const char *s);
t_glist				*lstaddbac(t_glist **head, t_glist **tail, const char *s,
						ssize_t state);
void				lst_clear(t_glist *head);
// helper norminnete

inline static void	free_stash(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

#endif