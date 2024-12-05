/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:28 by ezekaj            #+#    #+#             */
/*   Updated: 2024/12/05 18:40:04 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

t_list	*find_last_node(t_list *list);

char	*get_next_line(int fd);
char	*ft_get_line(t_list	*list);

int		len_to_newline(t_list *list);
int		found_newline(t_list **list);

void	create_list(t_list **list, int fd);
void	ft_append(t_list **list, char *buffer);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buffer);
void	ft_strcpy(t_list *list, char *str);
void	ft_polish(t_list **list);

#endif